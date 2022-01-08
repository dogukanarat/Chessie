#include <QMainWindow>
#include "ChessieSyntaxObject/ChessieSyntaxObject.h"

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
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        Ui::MainWindow* m_ui;
        ChessieObjects::SyntaxObject* m_syntaxObject;
    };
}