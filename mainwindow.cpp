#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customlogger.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createActions();
    createMenus();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tab()
{
    int a=0, b=1, c=2;
    customLog(DEBUG, "info test %d, %d, %d", a, b, c);

    if (analogClock != 0)
        analogClock = new AnalogClock(this);
    setCentralWidget(analogClock);
}

void MainWindow::createActions()
{
    createTab = new QAction(tr("&Create Tab"), this);
    createTab->setShortcut(QKeySequence::Open);
    connect(createTab, SIGNAL(triggered()), this, SLOT(tab()));

    clearAct = new QAction(tr("&Clear"), this);
    clearAct->setShortcut(tr("Ctrl+C"));
    //connect(clearAct, SIGNAL(triggered()), textViewer, SLOT(clear()));

    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::createMenus()
{
    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(createTab);
    fileMenu->addAction(clearAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    menuBar()->addMenu(fileMenu);
}
