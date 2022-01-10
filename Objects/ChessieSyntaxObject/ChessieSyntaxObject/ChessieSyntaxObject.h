#ifndef INCLUDED_CHESSIESYNTAXOBJECT_H
#define INCLUDED_CHESSIESYNTAXOBJECT_H

#include <QObject>

namespace ChessieObjects
{
    class Syntax : public QObject
    {
        Q_OBJECT
        
    public:
        Syntax(QObject* parent = NULL);
        virtual ~Syntax();

    };
    
}
#endif
