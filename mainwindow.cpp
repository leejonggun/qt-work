#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customlogger.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    centralWidget = new QWidget(this);
//    centralWidget->setFixedSize(width(), height());
//    setCentralWidget(centralWidget);

//    tabWidget->setTabPosition(QTabWidget::North);
//    tabWidget->setFixedSize(width() - 10, height() - 10);

    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createTab()
{
    customLog(DEBUG, "createTab()");
//    tabWidget->addTab(new AnalogClock(this), tr("AnalogClock"));
}

void MainWindow::showDialog()
{
    customLog(DEBUG, "showDialog()");
    tabDialog = new TabDialog("test file name", this);
    tabDialog->show();
}

void MainWindow::showMainWidget()
{
    if (analogClock == 0)
    {
        analogClock = new AnalogClock(this);
        customLog(DEBUG, "analogClock = %p", analogClock);
    }
    analogClock->show();
}

void MainWindow::clear()
{
    if (analogClock != 0)
        analogClock->hide();
    customLog(DEBUG, "analogClock = %p", analogClock);
}

void MainWindow::createActions()
{
    createTabAct = new QAction(tr("&Create Tab"), this);
    createTabAct->setShortcut(QKeySequence::Open);
    connect(createTabAct, SIGNAL(triggered()), this, SLOT(createTab()));

    dialogAct = new QAction(tr("&Show Dialog"), this);
    dialogAct->setShortcut(tr("Ctrl+D"));
    connect(dialogAct, SIGNAL(triggered()), this, SLOT(showDialog()));

    showAct = new QAction(tr("&Show Widget"), this);
    showAct->setShortcut(tr("Ctrl+S"));
    connect(showAct, SIGNAL(triggered()), this, SLOT(showMainWidget()));

    clearAct = new QAction(tr("&Clear"), this);
    clearAct->setShortcut(tr("Ctrl+C"));
    connect(clearAct, SIGNAL(triggered()), this, SLOT(clear()));

    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::createMenus()
{
    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(createTabAct);
    fileMenu->addAction(dialogAct);
    fileMenu->addSeparator();
    fileMenu->addAction(showAct);
    fileMenu->addAction(clearAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
    menuBar()->addMenu(fileMenu);

    helpMenu = new QMenu(tr("&Help"), this);
    menuBar()->addMenu(helpMenu);
}
