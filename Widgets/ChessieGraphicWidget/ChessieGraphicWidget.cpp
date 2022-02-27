#include "ChessieGraphicWidget/ChessieGraphicWidget.h"
#include "ui_ChessieGraphicWidget.h"

ChessieGraphicWidget::ChessieGraphicWidget(QWidget *parent)
    : ChessieBaseWidget(parent)
    , m_ui(new Ui::ChessieGraphicWidget)
    , m_scene{}
    , m_timer{}
{
    m_ui->setupUi(this);

    m_fps = 60;

    m_pendulum.setScene(&m_scene);
    m_pendulum.setFrameRate(m_fps);

    initialise();

    connect(&m_timer, &QTimer::timeout, this, &ChessieGraphicWidget::update);

    m_timer.setInterval(QVariant(1000 / m_fps).toInt());
    m_timer.setSingleShot(false);
    m_timer.start();
}

ChessieGraphicWidget::~ChessieGraphicWidget()
{
}

void ChessieGraphicWidget::initialise()
{
    m_pendulum.initialise();

    m_ui->graphicsView->setScene(&m_scene);
    m_ui->graphicsView->show();
}

void ChessieGraphicWidget::update()
{
    m_pendulum.update();
}
