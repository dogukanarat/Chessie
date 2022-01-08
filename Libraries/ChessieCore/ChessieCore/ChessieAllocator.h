#ifndef INCLUDED_CHESSIEALLOCATOR_H
#define INCLUDED_CHESSIEALLOCATOR_H

#include "ChessieIAllocator.h"

namespace Chessie
{
    class Allocator : public IAllocator
    {
    public:
        Allocator(BytePointer buffer, Size size, Size paddingSize = 4);
        virtual ~Allocator() = default;
        virtual VoidPointer allocate(Size size) override;
        virtual VoidPointer reallocate(VoidPointer pointer, Size size) override;
        virtual Void free(VoidPointer pointer) override;
    private:
        Void initialize();
    private:
        BytePointer m_buffer;
        Size m_size;
        Size m_paddingSize;
    };
}
#endif // INCLUDED_CHESSIEALLOCATOR_H