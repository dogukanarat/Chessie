#include "ChessieGraphicWidget/ChessieGraphicWidget.h"
#include "ui_ChessieGraphicWidget.h"

ChessieGraphicWidget::ChessieGraphicWidget(QWidget *parent)
    : ChessieBaseWidget(parent)
    , m_ui(new Ui::ChessieGraphicWidget)
    , m_scene{}
    , m_timer{}
{
    m_ui->setupUi(this);

    fps = 60;

    m_timer.setInterval(QVariant(1000 / fps).toInt());
    m_timer.setSingleShot(false);
    m_timer.start();

    initialise();

    connect(&m_timer, &QTimer::timeout, this, &ChessieGraphicWidget::update);
}

ChessieGraphicWidget::~ChessieGraphicWidget()
{
}

void ChessieGraphicWidget::initialise()
{
    length = 100;
    dps = 50;
    phi = 0;

    x = length * qCos(phi * M_PI / 180);
    y = length * qSin(phi * M_PI / 180);

    m_line = m_scene.addLine(0, 0, x, y);
    m_ellipse = m_scene.addEllipse(x, y, 10, 10);

    m_scene.setSceneRect(-180, -90, 360, 180);
    m_ui->graphicsView->setScene(&m_scene);
    m_ui->graphicsView->show();
}

void ChessieGraphicWidget::update()
{
    t++;
    phi = QVariant( t * ( dps / fps ) ).toInt() % 360;
    x = length * qCos(phi * M_PI / 180);
    y = length * qSin(phi * M_PI / 180);

    m_line->setLine(0, 0, x, y);
    m_ellipse->setRect(x - 5, y - 5 , 10, 10);
}
