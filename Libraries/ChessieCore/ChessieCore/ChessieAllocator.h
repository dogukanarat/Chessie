#ifndef INCLUDED_CHESSIEALLOCATOR_H
#define INCLUDED_CHESSIEALLOCATOR_H

#include "ChessieIAllocator.h"

namespace Chessie
{
    class Allocator : public IAllocator
    {
        const Size BlockStatusMask = 0x00000001;
        const Size BlockSizeMask = 0xFFFFFFFE;

    public:
        Allocator(BytePointer buffer, Size size, Size paddingSize = 4);
        virtual ~Allocator() = default;
        virtual VoidPointer allocate(Size size) override;
        virtual VoidPointer reallocate(VoidPointer pointer, Size size) override;
        virtual Void free(VoidPointer pointer) override;

    protected:
        typedef enum BlockStatus
        {
            Available = 0,
            Unavailable = !Available,
        } BlockStatus;

        Size getBlockStatus(VoidPointer pointer);
        Size setBlockStatus(VoidPointer pointer, Bool isAvaible);
        Size getBlockSize(VoidPointer pointer);
        Size setBlockSize(VoidPointer pointer, Size size);

        Void initialize();
        VoidPointer getNextAvailableBlock(VoidPointer pointer);

        BytePointer m_buffer;
        Size m_size;
        Size m_paddingSize;
    };
}
#endif // INCLUDED_CHESSIEALLOCATOR_H