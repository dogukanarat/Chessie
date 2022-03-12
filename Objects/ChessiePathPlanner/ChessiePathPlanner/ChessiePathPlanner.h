#ifndef INCLUDED_CHESSIEPATHPLANNER_H
#define INCLUDED_CHESSIEPATHPLANNER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <QtMath>
#include <QVector>
#include "ChessieCore/ChessieCommon.h"
#include "ChessieBaseScene/ChessieBaseScene.h"
#include "DubinsPath/DubinsPath.h"

class ChessiePathPlanner : public ChessieBaseScene
{
    Q_OBJECT

    typedef enum DrawState
    {
        DRAW_STATE_NONE,
        DRAW_STATE_END,
        DRAW_STATE_DRAW
    } DrawState;

    constexpr static Real32 degToRad(Real32 deg) { return deg * M_PI / 180.0; }
    constexpr static Real32 radToDeg(Real32 rad) { return rad * 180.0 / M_PI; }
    
public:
    ChessiePathPlanner(QObject* parent = NULL);
    virtual ~ChessiePathPlanner() = default;

    virtual void initialise();
    virtual void update();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

protected:
    QVector<QPointF> m_points;
    QVector<double> m_angles;
    DubinsPath m_dubinsPath;
    DrawState m_drawState;

    QGraphicsLineItem* m_activeLine;
    QPointF m_activePoint;
    double m_lastAngle;
    double m_lastLength;
    bool m_isLengthSet;

    void algorithmRun();
    void algorithmDisplay();

    static int printConfiguration(double q[3], double x, void* obj);
};
    
#endif
