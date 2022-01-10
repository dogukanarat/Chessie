#ifndef INCLUDED_ICHESSIEALLOCATOR_H
#define INCLUDED_ICHESSIEALLOCATOR_H

#include "ChessieCommon.h"

namespace Chessie
{
    class IAllocator
    {
    public:
        IAllocator() = default;
        virtual ~IAllocator() = default;
        virtual VoidPointer allocate(Size size) = 0;
        virtual VoidPointer reallocate(VoidPointer pointer, Size size) = 0;
        virtual Void free(VoidPointer pointer) = 0;
    };
}

#endif // INCLUDED_ICHESSIEALLOCATOR_HI