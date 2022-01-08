#include "ChessieCore/ChessieDefaultAllocator.h"

using namespace Chessie;

VoidPointer DefaultAllocator::allocate(Size size)
{
    return malloc(size);
}

VoidPointer DefaultAllocator::reallocate(VoidPointer pointer, Size size)
{
    return realloc(pointer, size);
}

Void DefaultAllocator::free(VoidPointer pointer)
{
    free(pointer);
}