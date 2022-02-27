#include <QWidget>
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

private:
    Ui::ChessieGraphicWidget* m_ui;
};
