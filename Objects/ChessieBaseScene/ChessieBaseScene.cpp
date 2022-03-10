#include "ChessieBaseScene/ChessieBaseScene.h"

ChessieBaseScene::ChessieBaseScene(QObject* parent)
    : QGraphicsScene(parent)
    , m_fps{ 60 }
{
}

void ChessieBaseScene::setFrameRate(int fps)
{
    m_fps = fps;
}


void ChessieBaseScene::initialise()
{
    // initialise the scene
    clear();
}