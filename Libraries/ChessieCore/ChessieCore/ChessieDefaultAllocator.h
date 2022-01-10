#ifndef INCLUDED_ICHESSIEDEFAULTALLOCATOR_H
#define INCLUDED_ICHESSIEDEFAULTALLOCATOR_H

#include "ChessieCommon.h"
#include "ChessieIAllocator.h"

namespace Chessie
{
    class DefaultAllocator : public IAllocator
    {
    public:
        DefaultAllocator();
        virtual ~DefaultAllocator();
        virtual VoidPointer allocate(Size size);
        virtual VoidPointer reallocate(VoidPointer pointer, Size size);
        virtual Void free(VoidPointer pointer);
    };
}

#endif // INCLUDED_ICHESSIEDEFAULTALLOCATOR_H