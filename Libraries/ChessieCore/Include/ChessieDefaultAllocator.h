#ifndef INCLUDED_ICHESSIEDEFAULTALLOCATOR_H
#define INCLUDED_ICHESSIEDEFAULTALLOCATOR_H

#include "ChessieCommon.h"
#include "ChessieIAllocator.h"

namespace Chessie
{
    class DefaultAllocator : public IAllocator
    {
    {
    public:
        DefaultAllocator() = default;
        virtual ~DefaultAllocator() = default;
        virtual VoidPointer allocate(Size size) override noexcept const;
        virtual VoidPointer reallocate(VoidPointer pointer, Size size) override noexcept const;
        virtual Void free(VoidPointer pointer) override noexcept const;
    };
}

#endif // INCLUDED_ICHESSIEDEFAULTALLOCATOR_H