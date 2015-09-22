#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "analogclock.h"
#include "tabdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void createTab();
    void showDialog();
    void showMainWidget();
    void clear();

private:
    Ui::MainWindow *ui;
    QWidget *centralWidget;
// Tool Bars (better use ui design tool)
    void createActions();
    void createMenus();

    QMenu *fileMenu;
    QMenu *helpMenu;

    QAction *createTabAct;
    QAction *dialogAct;
    QAction *showAct;
    QAction *clearAct;
    QAction *exitAct;

// Widgets
    AnalogClock *analogClock;
    TabDialog *tabDialog;
};

#endif // MAINWINDOW_H
