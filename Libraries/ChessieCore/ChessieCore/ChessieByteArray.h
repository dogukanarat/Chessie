#ifndef INCLUDED_CHESSIEBYTEARRAY_H
#define INCLUDED_CHESSIEBYTEARRAY_H

#include "ChessieCommon.h"

namespace Chessie
{
    template <Size S>
    class ByteArray
    {
    public:
        ByteArray()
        {

        }

        ByteArray(Byte initialValue)
        {

        }

        virtual ~ByteArray() = default;

        ByteArray(const ByteArray& other) noexcept
        {

        }

        Byte& operator[](Size index) noexcept
        {

        }

        Void push(BytePointer source, Size size) noexcept
        {

        }
        Void pushTo(BytePointer source, Size size, Size offset) noexcept
        {

        }
        Void pull(BytePointer destination, Size size) const noexcept
        {

        }
        Void pullFrom(BytePointer destination, Size size, Size offset) const noexcept
        {

        }
        Size capacity() const noexcept
        {
            return S;
        }
        Void clear() noexcept
        {

        }
        
    protected: 
        Byte m_buffer[S];
    };
}

#endif // INCLUDED_CHESSIEBYTEARRAY_H