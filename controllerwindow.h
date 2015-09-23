#ifndef CONTROLLERWINDOW_H
#define CONTROLLERWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "previewwindow.h"

class ControllerWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ControllerWindow(QWidget *parent = 0);

signals:

public slots:
    void updatePreview();

private:
//    QPushButton *quitButton;
//    QPushButton *simpleWizardButton;

//    PreviewWindow *previewWindow;
};

#endif // CONTROLLERWINDOW_H
