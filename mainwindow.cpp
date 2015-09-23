#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customlogger.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    analogClock = 0;
    tabDialog = 0;
    customDialog = 0;

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
}

void MainWindow::showMainWidget()
{
    customLog(DEBUG, "analogClock = %p", analogClock);
    if (analogClock == 0)
    {
        analogClock = new AnalogClock(this);
        setCentralWidget(analogClock);
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
    fileMenu->addSeparator();
    fileMenu->addAction(showAct);
    fileMenu->addAction(clearAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
    menuBar()->addMenu(fileMenu);

    helpMenu = new QMenu(tr("&Help"), this);
    menuBar()->addMenu(helpMenu);
}

void MainWindow::on_actionShow_sample_dialog_triggered()
{
    customLog(DEBUG, "on_actionShow_sample_dialog_triggered()");
    tabDialog = new TabDialog("test file name", this);
    tabDialog->show();
}

void MainWindow::on_actionCreate_Custom_Dialog_triggered()
{
//    customDialog = new CustomDialog(this);
//    customDialog->show();
//    customLog(DEBUG, "on_actionCreate_Custom_Dialog_triggered()");
//    SimpleWizard *testWizard = new SimpleWizard();
//    testWizard->buildWizardPages();
//    testWizard->show();
}
