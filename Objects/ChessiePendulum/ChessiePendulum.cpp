#include "ChessiePendulum/ChessiePendulum.h"

ChessiePendulum::ChessiePendulum(QObject* parent)
    : QObject(parent)
    , m_scene{ NULL }
    , m_fps{ 60 }
    , m_t{ 0 }
    , m_g{ 0.0 }
    , m_dps{ 0.0 }
    , m_l{ 0.0 }
    , m_cirleRadius{ 0.0 }
{

}

ChessiePendulum::ChessiePendulum(QGraphicsScene* scene, QObject* parent)
    : QObject(parent)
    , m_scene(scene)
{

}

ChessiePendulum::~ChessiePendulum()
{
}

void ChessiePendulum::setScene(QGraphicsScene* scene)
{
    m_scene = scene;
}

void ChessiePendulum::setFrameRate(int fps)
{
    m_fps = fps;
}

void ChessiePendulum::initialise()
{
    if( m_scene != NULL )
    {
        m_g = 9.81;
        m_l = 50;
        m_dps = 20;
        m_cirleRadius = 10.0;

        m_initialTheta = 170.0;

        Real32 x = m_l * qSin(convertDegToRad(m_initialTheta));
        Real32 y = m_l * qCos(convertDegToRad(m_initialTheta));

        m_line = m_scene->addLine(0, 0, x, y);
        m_ellipse = m_scene->addEllipse(
            x - ( m_cirleRadius / 2 ),
            y - ( m_cirleRadius / 2 ),
            m_cirleRadius,
            m_cirleRadius
        );

        m_scene->setSceneRect(-180, -90, 360, 180);

        m_ellipse->setBrush(Qt::red);
    }
}

void ChessiePendulum::update()
{
    if( m_scene != NULL )
    {
        m_t++;

        Real32 timeInSecond = (Real32)(m_t) / (Real32)(m_fps);
        Real32 theta = m_initialTheta * qCos( qSqrt( ( m_g / m_l )  ) * timeInSecond );

        Real32 x = m_l * qSin(convertDegToRad(theta));
        Real32 y = m_l * qCos(convertDegToRad(theta));

        m_line->setLine(0, 0, x, y);

        m_ellipse->setRect(
            x - ( m_cirleRadius / 2 ),
            y - ( m_cirleRadius / 2 ),
            m_cirleRadius,
            m_cirleRadius
            );
    }
}