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
    CHESSIE_ASSERT(buffer != NULL);
    CHESSIE_ASSERT(size > 0);
    CHESSIE_ASSERT(paddingSize > 2); // Min header size
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
    
}