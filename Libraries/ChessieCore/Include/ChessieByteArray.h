#ifndef INCLUDED_CHESSIEBYTEARRAY_H
#define INCLUDED_CHESSIEBYTEARRAY_H

#include "ChessieCommon.h"

namespace Chessie
{
    template <Size size>
    class ByteArray
    {
    public:
        ByteArray() = default;
        ByteArray(Byte initialValue);
        virtual ~ByteArray() = default;

        ByteArray(const ByteArray& other) noexcept;
        Byte& operator[](Size index) noexcept;

        Void push(BytePointer source, Size size) noexcept;
        Void pushTo(BytePointer source, Size size, Size offset) noexcept;
        Void pop(BytePointer destination, Size size) const noexcept;
        Void popFrom(BytePointer destination, Size size, Size offset) const noexcept;
        Size capacity() const noexcept;
        Void clear() noexcept;
        
    protected: 
        Byte m_buffer[size];
    };
    };
}

#endif // INCLUDED_CHESSIEBYTEARRAY_H