#include "MainWindow.h"
#include "ui_MainWindow.h"

Chessie::MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui{new Ui::MainWindow}
{
    m_ui = new Ui::MainWindow();
    m_ui->setupUi(this);
}

Chessie::MainWindow::~MainWindow()
{
    delete m_ui;
}
