#include "helloGLwindow.h"
#include <QLabel>

HelloGLWindow::HelloGLWindow(QWidget *parent)
    : QWidget(parent),
      helloGL(0),
      sampleGL(0)
{
    helloGL = new helloGLWidget(this);
    sampleGL = new GLWidget(this);

    QPushButton *closeButton = new QPushButton(tr("&Close"));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    QWidget *container = new QWidget();
    QHBoxLayout *hlayout = new QHBoxLayout();
    QVBoxLayout *vlayout = new QVBoxLayout();
    QVBoxLayout *helloGLlayout = new QVBoxLayout();
    QVBoxLayout *sampleGLlayout = new QVBoxLayout();
    helloGLlayout->addWidget(new QLabel(tr("This is helloGL written by me")));
    helloGLlayout->addWidget(helloGL);
    sampleGLlayout->addWidget(new QLabel(tr("This is openGL2 sample provided by Qt")));
    sampleGLlayout->addWidget(sampleGL);

    hlayout->addLayout(helloGLlayout);
    hlayout->addLayout(sampleGLlayout);
    vlayout->addLayout(hlayout);
    vlayout->addWidget(closeButton);
    container->setLayout(vlayout);

    setWindowFlags(Qt::Window);
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(container);
    setLayout(mainLayout);
}
