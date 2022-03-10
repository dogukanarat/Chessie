#include "ChessieGraphicWidget/ChessieGraphicWidget.h"
#include "ui_ChessieGraphicWidget.h"

ChessieGraphicWidget::ChessieGraphicWidget(QWidget *parent)
    : ChessieBaseWidget(parent), m_ui(new Ui::ChessieGraphicWidget), m_timer{}, m_scenes{}, m_fps{60}
{
    m_ui->setupUi(this);

    m_scenes.insert("pathPlanner", new ChessiePathPlanner{this});

    initialise();

    connect(&m_timer, &QTimer::timeout, this, &ChessieGraphicWidget::update);

    m_timer.setInterval(QVariant(1000 / m_fps).toInt());
    m_timer.setSingleShot(false);
    m_timer.start();
}

ChessieGraphicWidget::~ChessieGraphicWidget()
{
    delete m_ui;
}

void ChessieGraphicWidget::initialise()
{
    for (auto it = m_scenes.begin(); it != m_scenes.end(); ++it)
    {
        it.value()->initialise();
        it.value()->setSceneRect(0,0, m_ui->graphicsView->width() - 20, m_ui->graphicsView->height() - 20);
    }

    m_ui->graphicsView->setScene(m_scenes.value("pathPlanner"));
    m_ui->graphicsView->fitInView(m_scenes.value("pathPlanner")->sceneRect(), Qt::KeepAspectRatio);
    m_ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    m_ui->graphicsView->show();
}

void ChessieGraphicWidget::update()
{
    for (auto it = m_scenes.begin(); it != m_scenes.end(); ++it)
    {
        it.value()->update();
    }
}
