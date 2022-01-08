#include "ChessieCore/ChessieUtilities.h"
#include <string>

using namespace Chessie;

VoidPointer Utilities::memSet(VoidPointer destination, CINT32 value, Size length)
{
    return memset(destination, value, length);
}

VoidPointer Utilities::memCopy(VoidPointer destination, ConstVoidPointer source, Size length)
{
    return memcpy(destination, source, length);
}