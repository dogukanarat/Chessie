#include "Include/ChessieDefaultAllocator.h"

using namespace Chessie;

Allocator::Allocator(BytePointer buffer, Size size, Size paddingSize)
{
}

VoidPointer Allocator::allocate(Size size)
{
    return malloc(size);
}

VoidPointer Allocator::reallocate(VoidPointer pointer, Size size)
{
    return realloc(pointer, size);
}

Void Allocator::free(VoidPointer pointer)
{
    free(pointer);
}