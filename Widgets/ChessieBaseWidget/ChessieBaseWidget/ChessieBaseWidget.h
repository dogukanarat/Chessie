#include <QWidget>
#include "ChessieCore/ChessieCommon.h"

class ChessieBaseWidget : public QWidget
{
    Q_OBJECT

public:
    ChessieBaseWidget(QWidget *parent = 0);
    ~ChessieBaseWidget();

private:
    Int32 test;
};