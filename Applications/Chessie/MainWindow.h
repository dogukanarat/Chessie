#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

namespace Chessie
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        Ui::MainWindow* m_ui;

    };
}
