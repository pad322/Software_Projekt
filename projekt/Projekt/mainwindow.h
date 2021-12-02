#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWindow>
#include <QSurfaceFormat>
#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <GL/glu.h>
#include <QKeyEvent>

class MainWindow : public QOpenGLWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    GLfloat x=-1,y=-4.8,z=-7.4;
    GLfloat xx=1,yy=10,zz=-70;
    GLfloat cucc1=2.0,cucc2=0.0;
    GLfloat ut_bal=-2.0, ut_kozep=2.0, ut_jobb=6.0;
    GLfloat koord = 2.0;
    GLfloat koord2;
    GLfloat koord3 = -2.0;
    GLfloat fa1 = -10.0, fa2 = -15, fa3 = -27.5, fa4 = -32.5, fa5 = -45, fa6 = -50, fa7 = -62.5, fa8 = -67.5;
    GLfloat twicePi = 2.0f * 3.14;
    bool started = true;

    // -6.8 -4.8 -7.4
    // 4.8 -4.8 -7.4

protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int width, int height) override;
    virtual void paintGL() override;
    void resizeEvent(QResizeEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void virtual keyPressEvent(QKeyEvent *) override;

public slots:
    void updateAnimation();
    void bopping();
    //void coming();
    //void triangles();

private:
    QOpenGLContext *context;
    QOpenGLFunctions  *openGLFunctions;
    void glPerspective( GLdouble fov, GLdouble aspectRatio, GLdouble zNear, GLdouble zFar );

    //float rotation;
};
#endif // MAINWINDOW_H
