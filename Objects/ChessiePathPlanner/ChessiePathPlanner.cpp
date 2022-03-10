#include "ChessiePathPlanner/ChessiePathPlanner.h"

ChessiePathPlanner::ChessiePathPlanner(QObject *parent)
    : ChessieBaseScene(parent)
{
    connect(this, &ChessiePathPlanner::mousePressEvent, this, &ChessiePathPlanner::mousePressEvent);
}

void ChessiePathPlanner::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    double pointX = event->scenePos().x();
    double pointY = event->scenePos().y();

    if (m_points.size() < 2)
    {
        QLineF newLine{};
        newLine.setP1(QPointF{pointX, pointY});
        newLine.setAngle(-90);
        newLine.setLength(50);

        addLine(newLine, QPen(Qt::green, 1, Qt::DashLine, Qt::RoundCap));

        m_points.push_back(event->scenePos());
    }
    else
    {
    }

    if (m_points.size() == 2)
    {
        algorithmRun();
        algorithmDisplay();
    }
    else
    {
    }
}

void ChessiePathPlanner::algorithmRun()
{
    double initialPose[] = {m_points[0].x(), m_points[0].y(), degToRad(90)};
    double finalPose[] = {m_points[1].x(), m_points[1].y(), degToRad(90)};

    dubinsPathShortestPath(&m_dubinsPath, initialPose, finalPose, 40.0);
}

void ChessiePathPlanner::algorithmDisplay()
{
    dubinsPathSampleMany(&m_dubinsPath, 0.1, ChessiePathPlanner::printConfiguration, this);
}

int ChessiePathPlanner::printConfiguration(double point[3], double x, void *obj)
{
    ChessiePathPlanner* self = (ChessiePathPlanner *)obj;

    self->addEllipse(point[0],
                     point[1],
                     1,
                     1,
                     QPen(Qt::NoPen),
                     QBrush(Qt::red));
    return 0;
}

void ChessiePathPlanner::initialise()
{
    clear();

    setBackgroundBrush(Qt::white);
}

void ChessiePathPlanner::update()
{
}