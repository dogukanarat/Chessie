#include <cstdlib>
#include <QDebug>
#include "ChessieCore/ChessieDefaultAllocator.h"

using namespace Chessie;

VoidPointer DefaultAllocator::allocate(Size size)
{
    return std::malloc(size);
}

VoidPointer DefaultAllocator::reallocate(VoidPointer pointer, Size size)
{
    return std::realloc(pointer, size);
}

Void DefaultAllocator::free(VoidPointer pointer)
{
    std::free(pointer);
}