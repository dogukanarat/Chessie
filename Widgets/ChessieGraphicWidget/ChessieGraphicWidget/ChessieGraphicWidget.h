#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QTimer>
#include <QtMath>
#include "ChessieBaseWidget/ChessieBaseWidget.h"

namespace Ui
{
    class ChessieGraphicWidget;
}

class ChessieGraphicWidget : public ChessieBaseWidget
{
    Q_OBJECT

public:
    ChessieGraphicWidget(QWidget *parent = 0);
    ~ChessieGraphicWidget();

public slots:
    void initialise();
    void update();

private:
    Ui::ChessieGraphicWidget* m_ui;
    QGraphicsScene m_scene;
    QTimer m_timer;
    QGraphicsLineItem* m_line;
    QGraphicsEllipseItem* m_ellipse;

    UInt32 fps;
    Real32 dps;
    UInt32 t;
    Real32 phi;
    Real32 length;
    Real32 x;
    Real32 y;
};
