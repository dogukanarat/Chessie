#ifndef INCLUDED_CHESSIEBYTEARRAY_H
#define INCLUDED_CHESSIEBYTEARRAY_H

#include "ChessieCommon.h"
#include "ChessieUtilities.h"

namespace Chessie
{
    template <Size _Size>
    class ByteArray
    {
    public:
        ByteArray()
        {
            clear();
        }

        ByteArray(Byte initialValue)
        {
            Utilities::memSet(m_buffer, initialValue, _Size);
        }

        virtual ~ByteArray() = default;

        ByteArray(const ByteArray& other) noexcept
        {
            Utilities::memCopy(m_buffer, other.m_buffer, _Size);
        }

        Byte& operator[](Size index) noexcept
        {
            return m_buffer[index];
        }

        Void push(BytePointer source, Size size) noexcept
        {
            pushTo(source, size, 0);
        }

        Void pushTo(BytePointer source, Size size, Size offset) noexcept
        {
            CHESSIE_EXPECT(size + offset <= _Size);

            Utilities::memCopy(m_buffer + offset, source, size);
        }

        Void pull(BytePointer destination, Size size) const noexcept
        {
            pullFrom(destination, size, 0);
        }

        Void pullFrom(BytePointer destination, Size size, Size offset) const noexcept
        {
            CHESSIE_EXPECT(size + offset <= _Size);

            Utilities::memCopy(destination, m_buffer + offset, size);
        }

        Size capacity() const noexcept
        {
            return _Size;
        }

        Void clear() noexcept
        {
            Utilities::memSet(m_buffer, 0, _Size);
        }
        
    protected: 
        Byte m_buffer[_Size];
    };
}

#endif // INCLUDED_CHESSIEBYTEARRAY_H