#include <QWidget>
#include <QTimer>
#include "ChessieBaseWidget/ChessieBaseWidget.h"
#include "ChessiePendulum/ChessiePendulum.h"

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
    ChessiePendulum m_pendulum;

    UInt32 m_fps;

};
