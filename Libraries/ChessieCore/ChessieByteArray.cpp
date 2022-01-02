#include "Include/ChessieByteArray.h"
#include "Include/ChessieUtilities.h"

using namespace Chessie;

/**
 * @brief Constructor for ByteArray with initial value.
 * @param initialValue
 */
ByteArray::ByteArray(Byte initialValue)
{
    Utilies::memSet(m_buffer, initialValue, sizeof(m_buffer));
}

/**
 * @brief Copy constructor for ByteArray.
 * @param other
 */
ByteArray::ByteArray(const ByteArray& other)
{
    Utilies::memCopy(m_buffer, other.m_buffer, sizeof(m_buffer));
}

ByteArray::push(BytePointer source, Size size)
{
    pushTo(source, size, 0);
}

ByteArray::pushTo(BytePointer source, Size size, Size offset)
{
    Utilies::memCopy(m_buffer + offset, source, size);
}