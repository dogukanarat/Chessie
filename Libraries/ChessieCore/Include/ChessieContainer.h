#ifndef INCLUDED_CHESSIECONTAINER_H
#define INCLUDED_CHESSIECONTAINER_H

#include "ChessieCommon.h"

namespace Chessie
{
    class IContainer
    {
    public:
        Container() = default;
        virtual ~Container() = default;
    };
}

#endif // INCLUDED_CHESSIECONTAINER_H