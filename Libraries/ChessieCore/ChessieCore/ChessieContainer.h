#ifndef INCLUDED_CHESSIEICONTAINER_H
#define INCLUDED_CHESSIEICONTAINER_H

#include "ChessieCommon.h"

namespace Chessie
{
    class IContainer
    {
    public:
        IContainer() = default;
        virtual ~IContainer() = default;
    };
}

#endif // INCLUDED_CHESSIEICONTAINER_H