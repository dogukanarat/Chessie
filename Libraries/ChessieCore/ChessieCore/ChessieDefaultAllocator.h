#ifndef INCLUDED_ICHESSIEDEFAULTALLOCATOR_H
#define INCLUDED_ICHESSIEDEFAULTALLOCATOR_H

#include "ChessieCommon.h"
#include "ChessieIAllocator.h"

namespace Chessie
{
    class DefaultAllocator : public IAllocator
    {
    public:
        DefaultAllocator() = default;
        virtual ~DefaultAllocator() = default;
        virtual VoidPointer allocate(Size size) override;
        virtual VoidPointer reallocate(VoidPointer pointer, Size size) override;
        virtual Void free(VoidPointer pointer) override;
    };
}

#endif // INCLUDED_ICHESSIEDEFAULTALLOCATOR_H