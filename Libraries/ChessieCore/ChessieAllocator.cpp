#include "ChessieCore/ChessieAllocator.h"

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
    CHESSIE_EXPECT(size > 0);
    CHESSIE_EXPECT(paddingSize > 2); // Min header size
}

/**
 * @brief Destructor for ChessieAllocator.
 * @param size Size of the buffer.
 * @return Allocated memory.
 */
VoidPointer Allocator::allocate(Size size)
{
    return NULL;
}

/**
 * @brief Reallocate a block of memory.
 * @param pointer Pointer to the allocated memory.
 * @param size Size of the block of memory to allocate.
 * @return Pointer to the reallocated memory.
 */
VoidPointer Allocator::reallocate(VoidPointer pointer, Size size)
{
    return NULL;
}

/**
 * @brief Free a block of memory.
 */
Void Allocator::free(VoidPointer pointer)
{
    CHESSIE_EXPECT( NULL != pointer);

    setBlockStatus(pointer, Available);
}

Size Allocator::getBlockStatus(VoidPointer pointer)
{
    CHESSIE_EXPECT( NULL != pointer);

    return (Size)(((UInt32)(*(UInt32*)pointer) & BlockStatusMask) >> 0);
}

Size Allocator::setBlockStatus(VoidPointer pointer, Bool isAvailable)
{
    CHESSIE_EXPECT( NULL != pointer);

    UInt32 HeaderSize = (getBlockSize(pointer) << 1) & BlockSizeMask;
    UInt32 HeaderStatus = (~isAvailable << 0) & BlockStatusMask;
    *(UInt32*)(pointer) = HeaderStatus | HeaderSize;
    return *(Size*)pointer;
}

Size Allocator::getBlockSize(VoidPointer pointer)
{
    CHESSIE_EXPECT( NULL != pointer);

    return (((*(UInt32*)pointer) & BlockSizeMask) >> 1);
}

Size Allocator::setBlockSize(VoidPointer pointer, Size size)
{
    CHESSIE_EXPECT( NULL != pointer);

    UInt32 HeaderSize = (size << 1) & BlockSizeMask;
    UInt32 HeaderStatus = (getBlockStatus(pointer) << 0) & BlockStatusMask;
    *(UInt32*)(pointer) = HeaderStatus | HeaderSize;
    return *(Size*)pointer;
}

VoidPointer Allocator::getNextAvailableBlock(VoidPointer pointer)
{
    CHESSIE_EXPECT( NULL != pointer);

    UInt32* tempPointer = (UInt32*)pointer;
    VoidPointer resultPointer = NULL;

    if(Available == getBlockStatus(tempPointer))
    {
        resultPointer = tempPointer;
    }
    else
    {
        // @note infinite recursion guard might be implemented
        resultPointer = getNextAvailableBlock(tempPointer);
    }

    return resultPointer;
}