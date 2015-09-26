#include "helloGLwindow.h"

HelloGLWindow::HelloGLWindow(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::Window);
    QPushButton *quitButton = new QPushButton(tr("&Close"));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

    QPushButton *openButton = new QPushButton(tr("&Open"));
    connect(openButton, SIGNAL(clicked()), this, SLOT(close()));

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(quitButton);
    mainLayout->addWidget(openButton);
    setLayout(mainLayout);
}

