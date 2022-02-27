#ifndef INCLUDED_CHESSIEPENDULUM_H
#define INCLUDED_CHESSIEPENDULUM_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QtMath>
#include "ChessieCore/ChessieCommon.h"

class ChessiePendulum : public QObject
{
    Q_OBJECT
    
public:
    ChessiePendulum(QObject* parent = NULL);
    ChessiePendulum(QGraphicsScene* scene, QObject* parent = NULL);
    virtual ~ChessiePendulum();

    constexpr static Real32 convertDegToRad(Real32 deg) { return deg * M_PI / 180.0; }
    constexpr static Real32 normalizeDeg(Real32 deg) { return (UInt32)(deg) % 360; }


    void setScene(QGraphicsScene* scene);
    void setFrameRate(int fps);
    void initialise();
    void update();

protected:
    QGraphicsScene* m_scene;
    QGraphicsLineItem* m_line;
    QGraphicsEllipseItem* m_ellipse;

    UInt32 m_fps;
    UInt32 m_t;
    Real32 m_g;
    Real32 m_dps;
    Real32 m_l;
    Real32 m_initialTheta;
    Real32 m_cirleRadius;
};
    
#endif
