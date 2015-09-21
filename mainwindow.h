#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "analogclock.h"

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
    void tab();

private:
    Ui::MainWindow *ui;

    void createActions();
    void createMenus();

    QMenu *fileMenu;
    QMenu *helpMenu;

    QAction *createTab;
    QAction *clearAct;
    QAction *exitAct;

    AnalogClock *analogClock;
};

#endif // MAINWINDOW_H
