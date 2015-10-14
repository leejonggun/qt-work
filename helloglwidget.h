#ifndef HELLOGLWIGDET_H
#define HELLOGLWIGDET_H

#include <QLabel>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QMatrix4x4>
#include "logo.h"

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class helloGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    // I don't know the error like this:
    // "symbol(s) cont found for architecture x86_64"
    // "linker command failed with exit code 1 (use -v to see invocation
    Q_OBJECT

public:
    helloGLWidget(QWidget *parent = 0);
    ~helloGLWidget();

public slots:
    void cleanup();

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;

private:
    QOpenGLShaderProgram *m_program;
};






//#include <QOpenGLWidget>
//#include <QOpenGLFunctions>
//#include <QOpenGLVertexArrayObject>
//#include <QOpenGLBuffer>
//#include <QMatrix4x4>
//#include "logo.h"

//QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

//class helloGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
//{
//    Q_OBJECT

//public:
//    helloGLWidget(QWidget *parent = 0);
//    ~helloGLWidget();

//    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
//    QSize sizeHint() const Q_DECL_OVERRIDE;

//public slots:
//    void setXRotation(int angle);
//    void setYRotation(int angle);
//    void setZRotation(int angle);
//    void cleanup();

//signals:
//    void xRotationChanged(int angle);
//    void yRotationChanged(int angle);
//    void zRotationChanged(int angle);

//protected:
//    void initializeGL() Q_DECL_OVERRIDE;
//    void paintGL() Q_DECL_OVERRIDE;
//    void resizeGL(int width, int height) Q_DECL_OVERRIDE;
//    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
//    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

//private:
//    void setupVertexAttribs();

//    bool m_core;
//    int m_xRot;
//    int m_yRot;
//    int m_zRot;
//    QPoint m_lastPos;
//    Logo m_logo;
//    QOpenGLVertexArrayObject m_vao;
//    QOpenGLBuffer m_logoVbo;
//    QOpenGLShaderProgram *m_program;
//    int m_projMatrixLoc;
//    int m_mvMatrixLoc;
//    int m_normalMatrixLoc;
//    int m_lightPosLoc;
//    QMatrix4x4 m_proj;
//    QMatrix4x4 m_camera;
//    QMatrix4x4 m_world;
//    bool m_transparent;
//};












#endif // HELLOGLWIGDET_H
