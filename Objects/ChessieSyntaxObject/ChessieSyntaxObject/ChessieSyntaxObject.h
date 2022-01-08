#ifndef INCLUDED_CHESSIESYNTAXOBJECT_H
#define INCLUDED_CHESSIESYNTAXOBJECT_H

#include <QObject>

namespace ChessieObjects
{
    class SyntaxObject : public QObject
    {
        Q_OBJECT
        
    public:
        SyntaxObject();
        virtual ~SyntaxObject();

    };
    
}
#endif
