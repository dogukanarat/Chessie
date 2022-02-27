#include "ChessieGraphicWidget/ChessieGraphicWidget.h"
#include "ui_ChessieGraphicWidget.h"

ChessieGraphicWidget::ChessieGraphicWidget(QWidget *parent)
    : ChessieBaseWidget(parent)
    , m_ui(new Ui::ChessieGraphicWidget)
{
    m_ui->setupUi(this);
}

ChessieGraphicWidget::~ChessieGraphicWidget()
{
}
