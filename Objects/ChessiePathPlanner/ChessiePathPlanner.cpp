#include "ChessiePathPlanner/ChessiePathPlanner.h"

ChessiePathPlanner::ChessiePathPlanner(QObject *parent)
    : ChessieBaseScene(parent)
    , m_isLengthSet{FALSE}
{
}

void ChessiePathPlanner::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF currentPoint = event->scenePos();
    double pointX = currentPoint.x();
    double pointY = currentPoint.y();

    if (m_points.size() < 2)
    {
        QLineF newLine{};
        newLine.setP1(QPointF{pointX, pointY});
        newLine.setAngle(-90);
        newLine.setLength(1);

        m_activeLine = addLine(newLine, QPen(Qt::green, 1, Qt::DashLine, Qt::RoundCap));
        m_activePoint = currentPoint;

        m_points.push_back(currentPoint);
    }
    else
    {
    }
}

void ChessiePathPlanner::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF currentPoint = event->scenePos();
    double pointX = currentPoint.x();
    double pointY = currentPoint.y();

    if(NULL != m_activeLine)
    {
        double startX = m_activePoint.x();
        double startY = m_activePoint.y();

        double length = sqrt(pow(pointX - startX, 2) + pow(pointY - startY, 2));

        if(!m_isLengthSet)
        {
            m_lastLength = length;
        }
        else
        {
            length = m_lastLength;
        }

        m_lastAngle = radToDeg(-atan2(pointY - startY, pointX - startX));

        QLineF replacedLine{};
        replacedLine.setP1(m_activePoint);
        replacedLine.setAngle(m_lastAngle);
        replacedLine.setLength(length);
        
        m_activeLine->setLine(replacedLine);
    }
}

void ChessiePathPlanner::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_activeLine = NULL;
    m_angles.push_back(m_lastAngle);
    m_isLengthSet = TRUE;

    if (m_points.size() == 2)
    {
        algorithmRun();
        algorithmDisplay();
    }
    else
    {}
}

void ChessiePathPlanner::algorithmRun()
{
    double initialPose[] = {m_points[0].x(), m_points[0].y(), degToRad(-m_angles[0])};
    double finalPose[] = {m_points[1].x(), m_points[1].y(), degToRad(-m_angles[1])};

    dubinsPathShortestPath(&m_dubinsPath, initialPose, finalPose, m_lastLength);
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