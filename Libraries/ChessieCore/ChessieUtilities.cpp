#include "Include/ChessieUtilities.h"
#include <string>

using namespace Chessie;

Utilities::memSet(destination, value, length)
{
    return memset(destination, value, length);
}

Utilities::memCopy(destination, source, length)
{
    return memcpy(destination, source, length);
}