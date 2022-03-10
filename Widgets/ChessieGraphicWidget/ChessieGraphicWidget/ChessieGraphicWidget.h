#include <QWidget>
#include <QTimer>
#include <QMap>
#include <QString>
#include "ChessieBaseWidget/ChessieBaseWidget.h"
#include "ChessieBaseScene/ChessieBaseScene.h"
#include "ChessiePathPlanner/ChessiePathPlanner.h"

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

    QTimer m_timer;

    QMap<QString, ChessieBaseScene*> m_scenes;

    ChessiePathPlanner m_pathPlanner;

    UInt32 m_fps;

};
