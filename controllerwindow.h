#ifndef CONTROLLERWINDOW_H
#define CONTROLLERWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include "simplewizard.h"
#include "helloGLwindow.h"

class ControllerWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ControllerWindow(QWidget *parent = 0);
    ~ControllerWindow();

signals:

private slots:
    void on_simpleWizardButton_clicked();
    void on_helloGLButton_clicked();
    void on_lineButton_clicked();
    void on_rectButton_clicked();
    void on_clearButton_clicked();
    void on_closeHelloGLButton_clicked();
private:
    QVBoxLayout *mainLayout;
    QWidget *helloGLLayoutHolder;

    QPushButton *quitButton;
    QPushButton *simpleWizardButton;
    QPushButton *helloGLButton;

    HelloGLWindow *helloGL;

private:
    QVBoxLayout *createDefaultLayout();
};

#endif // CONTROLLERWINDOW_H
