#include "ChessieCore/ChessieAllocator.h"
#include "ChessieCore/ChessieUtilities.h"

using namespace Chessie;

/**
 * @brief Constructor for ChessieAllocator
 * @param size Size of the buffer
 * @param buffer Pointer to the buffer
 * @param paddingSize Size of the padding
 * @note The buffer is not created dynamicly, 
 * it is assumed that the buffer is already allocated already.
 * @note Implicit Free List Method is used for the allocation.
 */
Allocator::Allocator(BytePointer buffer, Size size, Size paddingSize)
    : m_buffer(buffer)
    , m_size(size)
    , m_paddingSize(paddingSize)
{
    CHESSIE_EXPECT(buffer != NULL);
    CHESSIE_EXPECT(size > 8); // min size due to sum of header and footer sizes
    CHESSIE_EXPECT(paddingSize > 4); // min header size

    initialise(buffer, size);
}

/**
 * @brief Destructor for ChessieAllocator.
 * @param size Size of the buffer.
 * @return Allocated memory.
 */
VoidPointer Allocator::allocate(Size size)
{
    CHESSIE_EXPECT(size <= m_size - 4);
    
    VoidPointer resultPointer = NULL;
    VoidPointer searchPointer = m_buffer;
    Bool isMemoryAllocated = FALSE;

    // @note size with alignment but without header
    Size requiredSize = size + size % m_paddingSize; 

    while(!isMemoryAllocated)
    {
        searchPointer = getNextAvailableBlock(searchPointer);

        if(NULL != searchPointer)
        {
            Size foundBlockSize = getBlockSize(searchPointer);

            Size requiredSizeWithHeader = requiredSize + 4;

            if(foundBlockSize > requiredSizeWithHeader)
            {
                setBlockSize(searchPointer, requiredSize);
                setBlockStatus(searchPointer, Unavailable);

                if(foundBlockSize > requiredSizeWithHeader + 4) // 4 is for next header size
                {
                    VoidPointer nextHeaderPointer = (BytePointer)searchPointer + requiredSizeWithHeader;
                    
                    Size remainingSize = foundBlockSize - (requiredSizeWithHeader + 4);

                    setBlockSize(nextHeaderPointer, remainingSize);
                    setBlockSize(nextHeaderPointer, Unavailable );
                }
                else
                {
                    // the memory is filled completely
                }

                resultPointer = (BytePointer)searchPointer + 4;
                
                isMemoryAllocated = TRUE;
            }
            else
            {
                // @note memory could not be allocated yet, continue to search
                isMemoryAllocated = FALSE;
            }
        }
        else
        {
            resultPointer = NULL;
            isMemoryAllocated = TRUE;
        }       
    }

    return resultPointer;
}

/**
 * @brief Reallocate a block of memory.
 * @param pointer Pointer to the allocated memory.
 * @param size Size of the block of memory to allocate.
 * @return Pointer to the reallocated memory.
 */
VoidPointer Allocator::reallocate(VoidPointer pointer, Size size)
{
    CHESSIE_EXPECT( NULL != pointer);
    
    VoidPointer resultPointer = NULL;

    resultPointer = allocate(size);

    if(NULL != resultPointer)
    {
        Size oldSize = getBlockSize(pointer);

        Utilities::memCopy(resultPointer, pointer, oldSize);

        setBlockStatus(pointer, Available);
    }
    else
    {
        // allocation is failed
        resultPointer = NULL;
    }

    return resultPointer;
}

/**
 * @brief Free a block of memory.
 */
Void Allocator::free(VoidPointer pointer)
{
    CHESSIE_EXPECT( NULL != pointer);

    setBlockStatus(pointer, Available);
}

Size Allocator::initialise(VoidPointer pointer, Size size)
{
    CHESSIE_EXPECT(NULL != pointer);
    CHESSIE_EXPECT(size > 8);

    setBlockSize(pointer, size - 4); // @note 8 is sum of header and footer sizes
    setBlockStatus(pointer, Available);

    m_endOfMemory = (VoidPointer)((UInt64)pointer + size - 4);

    return size - 4;
}

Size Allocator::getBlockStatus(VoidPointer pointer)
{
    CHESSIE_EXPECT(NULL != pointer);

    return (Size)(((UInt32)(*(UInt32*)pointer) & BlockStatusMask) >> 0);
}

Size Allocator::setBlockStatus(VoidPointer pointer, Bool isAvailable)
{
    CHESSIE_EXPECT(NULL != pointer);

    UInt32 HeaderSize = (getBlockSize(pointer) << 1) & BlockSizeMask;
    UInt32 HeaderStatus = (~isAvailable << 0) & BlockStatusMask;
    *(UInt32*)(pointer) = HeaderStatus | HeaderSize;
    return *(Size*)pointer;
}

Size Allocator::getBlockSize(VoidPointer pointer)
{
    CHESSIE_EXPECT(NULL != pointer);

    return (((*(UInt32*)pointer) & BlockSizeMask) >> 1);
}

Size Allocator::setBlockSize(VoidPointer pointer, Size size)
{
    CHESSIE_EXPECT(NULL != pointer);

    UInt32 HeaderSize = (size << 1) & BlockSizeMask;
    UInt32 HeaderStatus = (getBlockStatus(pointer) << 0) & BlockStatusMask;
    *(UInt32*)(pointer) = HeaderStatus | HeaderSize;
    return *(Size*)pointer;
}

VoidPointer Allocator::getNextAvailableBlock(VoidPointer pointer)
{
    CHESSIE_EXPECT(NULL != pointer);

    UInt32* tempPointer = (UInt32*)pointer;
    VoidPointer resultPointer = NULL;

    if(Available == getBlockStatus(tempPointer))
    {
        resultPointer = tempPointer;
    }
    else
    {
        Size allocatedSize = getBlockSize(tempPointer);
        VoidPointer nextHeader = (VoidPointer)((UInt64)tempPointer + allocatedSize);

        if(nextHeader == m_endOfMemory)
        {
            // end of memory
            resultPointer = NULL;
        }
        else
        {
            // @note infinite recursion guard might be implemented
            resultPointer = getNextAvailableBlock(nextHeader);
        }
    }

    return resultPointer;
}