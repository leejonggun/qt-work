#include "controllerwindow.h"

ControllerWindow::ControllerWindow(QWidget *parent) : QWidget(parent)
{
    mainLayout = createDefaultLayout();
    helloGLLayoutHolder = 0;
    helloGL = 0;
}

ControllerWindow::~ControllerWindow()
{
}

QVBoxLayout *ControllerWindow::createDefaultLayout()
{
    quitButton = new QPushButton(tr("&Close"));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *bottomLayout = new QHBoxLayout();
    bottomLayout->addStretch();
    bottomLayout->addWidget(quitButton);

    simpleWizardButton = new QPushButton(tr("&show Simple Wizard"));
    connect(simpleWizardButton, SIGNAL(clicked()), this, SLOT(on_simpleWizardButton_clicked()));

    helloGLButton = new QPushButton(tr("&show hello OpenGL example"));
    connect(helloGLButton, SIGNAL(clicked()), this, SLOT(on_helloGLButton_clicked()));

    QVBoxLayout *retLayout = new QVBoxLayout();
    retLayout->addWidget(simpleWizardButton);
    retLayout->addWidget(helloGLButton);

    retLayout->addLayout(bottomLayout);
    setLayout(retLayout);

    return retLayout;
}

void ControllerWindow::on_simpleWizardButton_clicked()
{
    SimpleWizard *testWizard = new SimpleWizard(this);
    testWizard->buildWizardPages();
    testWizard->show();
}

void ControllerWindow::on_helloGLButton_clicked()
{
    helloGL = new HelloGLWindow(this);
    helloGL->show();

    QVBoxLayout *helloGLLayout = new QVBoxLayout();
    QPushButton *lineButton = new QPushButton(tr("&draw line"));
    QPushButton *rectButton = new QPushButton(tr("&draw rect"));
    QPushButton *clearButton = new QPushButton(tr("&clear all items"));
    QPushButton *closeHelloGLButton = new QPushButton(tr("&close example Window"));
    connect(lineButton, SIGNAL(clicked()), this, SLOT(on_lineButton_clicked()));
    connect(rectButton, SIGNAL(clicked()), this, SLOT(on_rectButton_clicked()));
    connect(clearButton, SIGNAL(clicked()), this, SLOT(on_clearButton_clicked()));
    connect(closeHelloGLButton, SIGNAL(clicked()), this, SLOT(on_closeHelloGLButton_clicked()));
    helloGLLayout->addWidget(lineButton);
    helloGLLayout->addWidget(rectButton);
    helloGLLayout->addWidget(clearButton);
    helloGLLayout->addWidget(closeHelloGLButton);

    helloGLLayoutHolder = new QWidget();
    helloGLLayoutHolder->setLayout(helloGLLayout);

    helloGLButton->hide();
    mainLayout->insertWidget(mainLayout->indexOf(helloGLButton), helloGLLayoutHolder);
}

void ControllerWindow::on_lineButton_clicked()
{
}

void ControllerWindow::on_rectButton_clicked()
{
}

void ControllerWindow::on_clearButton_clicked()
{
}

void ControllerWindow::on_closeHelloGLButton_clicked()
{
    delete helloGLLayoutHolder;
    helloGLButton->show();
    helloGL->close();
}
