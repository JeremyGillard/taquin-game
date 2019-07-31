#include <QLabel>
#include <QPushButton>

#include "endlayout.h"

EndLayout::EndLayout(QWidget* parent)
    : QWidget(parent)
{
    QLabel* lbl = new QLabel("FIN", this);
    QPushButton* restartBtn = new QPushButton("Restart", this);
}
