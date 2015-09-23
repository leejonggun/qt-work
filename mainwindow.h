#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "analogclock.h"
#include "tabdialog.h"
#include "customdialog.h"
#include "simplewizard.h"

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
    void showMainWidget();
    void clear();

    void on_actionShow_sample_dialog_triggered();

    void on_actionCreate_Custom_Dialog_triggered();

private:
    Ui::MainWindow *ui;
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
    CustomDialog *customDialog;
};

#endif // MAINWINDOW_H
