#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "helloglwidget.h"
#include "glwidget.h"

class HelloGLWindow : public QWidget
{
    Q_OBJECT
public:
    explicit HelloGLWindow(QWidget *parent = 0);
    //~HelloGLWindow();

signals:

public slots:

private:
    helloGLWidget *helloGL;
    GLWidget *sampleGL;

};

#endif // PREVIEWWINDOW_H
