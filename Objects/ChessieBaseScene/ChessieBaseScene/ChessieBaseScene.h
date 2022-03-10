#ifndef INCLUDED_CHESSIEBASESCENE_H
#define INCLUDED_CHESSIEBASESCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "ChessieCore/ChessieCommon.h"

class ChessieBaseScene : public QGraphicsScene
{
    Q_OBJECT
    
public:
    ChessieBaseScene(QObject* parent = NULL);
    virtual ~ChessieBaseScene() = default;

    virtual void setFrameRate(int fps);
    virtual void initialise();
    virtual void update() = 0;

protected:
    UInt32 m_fps;
};
    
#endif
