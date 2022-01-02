#ifndef INCLUDED_CHESSIEUTILITIES_H
#define INCLUDED_CHESSIEUTILITIES_H

#include "ChessieCommon.h"

namespace Chessie
{
    class Utilities
    {
    public:
        static VoidPointer memSet(VoidPointer destination, CINT32 value, Size length);
        static VoidPointer memCopy(VoidPointer destination, ConstVoidPointer source, Size length);
    }
}

#endif // INCLUDED_CHESSIEUTILITIES_H 