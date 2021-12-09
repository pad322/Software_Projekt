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

    GLfloat x=-1,y=-4.8,z=-7.4; //-> for camera, point of view
    GLfloat sun_x=1,sun_y=10,sun_z=-70;
    GLfloat square_corner1=2.0,square_corner2=0.0;
    GLfloat road_left=-2.0, road_middle=2.0, road_right=6.0;
    GLfloat triangle_coord1 = 2.0;
    GLfloat triangle_coord2;
    GLfloat triangle_coord3 = -2.0;
    GLfloat tree1 = -10.0, tree2 = -15, tree3 = -27.5, tree4 = -32.5, tree5 = -45, tree6 = -50, tree7 = -62.5, tree8 = -67.5;
    GLfloat twicePi = 2.0f * 3.14;
    bool started = true;

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

private:
    QOpenGLContext *context;
    QOpenGLFunctions  *openGLFunctions;
    void glPerspective( GLdouble fov, GLdouble aspectRatio, GLdouble zNear, GLdouble zFar );
};
#endif // MAINWINDOW_H
