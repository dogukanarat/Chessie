#include "ChessieSyntaxObject/ChessieSyntaxObject.h"
#include "ChessieCore/ChessieCommon.h"
#include "ChessieCore/ChessieDefaultAllocator.h"

using namespace ChessieObjects;

Syntax::Syntax(QObject* parent)
    : QObject(parent)
{
    CHESSIE_EXPECT(TRUE);
}

Syntax::~Syntax()
{
    CHESSIE_EXPECT(TRUE);
}
