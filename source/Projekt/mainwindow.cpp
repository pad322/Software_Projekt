#include "mainwindow.h"
#include <QMessageBox>
#include <QLabel>
#include <windows.h>

MainWindow::MainWindow(QWidget *parent)
{

    setSurfaceType(QWindow::OpenGLSurface);
    QSurfaceFormat formate;
    formate.setProfile(QSurfaceFormat::CompatibilityProfile);
    formate.setVersion(2,1);
    setFormat(formate);

    context = new QOpenGLContext;
    context->setFormat(formate);
    context->create();
    context->makeCurrent(this);

    openGLFunctions = context->functions();
}


MainWindow::~MainWindow()
{
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if( event->key() == Qt::Key_A )
    {
        if(square_corner1==2.0)
        {
            square_corner2=-4.0;
            square_corner1=-2.0;
        }
        else if(square_corner1>-2.0)
        {
            square_corner1-=4;
            square_corner2-=4;
        }

    }
    if( event->key() == Qt::Key_D )
    {
        if(square_corner1==2.0)
        {
            square_corner2=4.0;
            square_corner1=6.0;
        }
        else if(square_corner1<6.0)
        {
            square_corner1+=4;
            square_corner2+=4;
        }
    }
}

void MainWindow::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    resizeGL(this->width(), this->height());
}

void MainWindow::resizeGL(int w, int h)
{
    glViewport(0,0,w, h);

    qreal aspectRatio = qreal (w)/ qreal(h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    glPerspective(75, aspectRatio, 0.1, 400000000);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void MainWindow::bopping()
{
    if(y==-4.8)
        y+=0.1;
    else if(y==-4.6)
        y-=0.1;
}

float triangle_distance_a=-70;
float triangle_distance_b=-70;
unsigned int speed = 1, wait = 0;
float score = 0.0;

void MainWindow::paintGL()
{
    glClearColor(0.1f, 0.8f, 0.93f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QTimer *aTimer = new QTimer;
    connect(aTimer,SIGNAL(timeout()),SLOT(bopping()));
    aTimer->start(750);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(x, y, z);
    //sun
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(sun_x, sun_y, sun_z); //-> center of circle
    for(int i = 0; i <= 20;i++) {
        glVertex3f(
            sun_x + (6 * cos(i * twicePi / 20)),
            sun_y + (6 * sin(i * twicePi / 20)),
            sun_z = -70
        );
    }
    glEnd();
    //
    //tree1
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.5f, 0.4f);
    glVertex3f(-6, 0.0f, tree1);
    glVertex3f(-8, 0.0f, tree1);
    glVertex3f(-8, 6.0f, tree1);
    glVertex3f(-6, 6.0f, tree1);
    glEnd();
    //
    //tree2
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.8f, 0.2f);
    glVertex3f(8, 0.0f, tree2);
    glVertex3f(10, 0.0f, tree2);
    glVertex3f(10, 6.0f, tree2);
    glVertex3f(8, 6.0f, tree2);
    glEnd();
    //
    //tree3
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.9f, 0.6f);
    glVertex3f(-6, 0.0f, tree3);
    glVertex3f(-8, 0.0f, tree3);
    glVertex3f(-8, 6.0f, tree3);
    glVertex3f(-6, 6.0f, tree3);
    glEnd();
    //
    //tree4
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.4f, 0.9f);
    glVertex3f(8, 0.0f, tree4);
    glVertex3f(10, 0.0f, tree4);
    glVertex3f(10, 6.0f, tree4);
    glVertex3f(8, 6.0f, tree4);
    glEnd();
    //
    //tree5
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.6f);
    glVertex3f(-6, 0.0f, tree5);
    glVertex3f(-8, 0.0f, tree5);
    glVertex3f(-8, 6.0f, tree5);
    glVertex3f(-6, 6.0f, tree5);
    glEnd();
    //
    //tree6
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.2f, 0.1f);
    glVertex3f(8, 0.0f, tree6);
    glVertex3f(10, 0.0f, tree6);
    glVertex3f(10, 6.0f, tree6);
    glVertex3f(8, 6.0f, tree6);
    glEnd();
    //
    //tree7
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.2f, 0.3f);
    glVertex3f(-6, 0.0f, tree7);
    glVertex3f(-8, 0.0f, tree7);
    glVertex3f(-8, 6.0f, tree7);
    glVertex3f(-6, 6.0f, tree7);
    glEnd();
    //
    //tree8
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.2f, 0.2f);
    glVertex3f(8, 0.0f, tree8);
    glVertex3f(10, 0.0f, tree8);
    glVertex3f(10, 6.0f, tree8);
    glVertex3f(8, 6.0f, tree8);
    glEnd();
    //
    //square
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex3f(square_corner1, 0.0f, 0.0f);
    glVertex3f(square_corner2, 0.0f, 0.0f);
    glVertex3f(square_corner2, 2.0f, 0.0f);
    glVertex3f(square_corner1, 2.0f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex3f(square_corner1, 0.0f, 0.0f);
    glVertex3f(square_corner2, 0.0f, 0.0f);
    glVertex3f(square_corner2, 0.0f, 1.0f);
    glVertex3f(square_corner1, 0.0f, 1.0f);
    glEnd();
    //
    //road left
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.0f, 0.6f);
    glVertex3f(road_left, -0.1f, -70.0f);
    glVertex3f(road_left-2, -0.1f, -70.0f);
    glVertex3f(road_left-2, -0.1f, 10.0f);
    glVertex3f(road_left, -0.1f, 10.0f);
    glEnd();
    //
    //road middle
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.0f, 0.6f);
    glVertex3f(road_middle, -0.1f, -70.0f);
    glVertex3f(road_middle-2, -0.1f, -70.0f);
    glVertex3f(road_middle-2, -0.1f, 10.0f);
    glVertex3f(road_middle, -0.1f, 10.0f);
    glEnd();
    //
    //road right
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.0f, 0.6f);
    glVertex3f(road_right, -0.1f, -70.0f);
    glVertex3f(road_right-2, -0.1f, -70.0f);
    glVertex3f(road_right-2, -0.1f, 10.0f);
    glVertex3f(road_right, -0.1f, 10.0f);
    glEnd();
    //
    //basic triangle obstacle
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(triangle_coord1-2, 0.0f, triangle_distance_a);
    glVertex3f(triangle_coord1, 0.0f, triangle_distance_a);
    glVertex3f(triangle_coord1-1, 1.0f, triangle_distance_a);
    glEnd();
    //
    //double triangle obstacle
    if(speed>1){
        glBegin(GL_TRIANGLES);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(triangle_coord2-2, 0.0f, triangle_distance_a);
        glVertex3f(triangle_coord2, 0.0f, triangle_distance_a);
        glVertex3f(triangle_coord2-1, 1.0f, triangle_distance_a);
        glEnd();
    }
    //
    //half-distance triangle
    if(triangle_distance_a>-35){
        triangle_distance_b+=speed;
        glBegin(GL_TRIANGLES);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(triangle_coord3-2, 0.0f, triangle_distance_b);
        glVertex3f(triangle_coord3, 0.0f, triangle_distance_b);
        glVertex3f(triangle_coord3-1, 1.0f, triangle_distance_b);
        glEnd();
    }
    //
    //score display

    //

    glFlush();
    if( started != true){
        started = true;
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(updateAnimation()));
        timer->start(100);
    }

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    resizeGL(this->width(), this->height());
    this->update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    paintGL();
}


void MainWindow::updateAnimation()
{
    this->update();
    score+=0.1;
    //triangle speed
    triangle_distance_a += speed;
    tree1 += speed;
    tree2 += speed;
    tree3 += speed;
    tree4 += speed;
    tree5 += speed;
    tree6 += speed;
    tree7 += speed;
    tree8 += speed;
    if(tree1 > 5.0){
        tree1 = -70;
    }
    if(tree2 > 5.0){
        tree2 = -70;
    }
    if(tree3 > 5.0){
        tree3 = -70;
    }
    if(tree4 > 5.0){
        tree4 = -70;
    }
    if(tree5 > 5.0){
        tree5 = -70;
    }
    if(tree6 > 5.0){
        tree6 = -70;
    }
    if(tree7 > 5.0){
        tree7 = -70;
    }
    if(tree8 > 5.0){
        tree8 = -70;
    }
    if(triangle_distance_a > 5.0 && triangle_distance_b > 5.0){
       triangle_distance_a = -70;
       triangle_distance_b = -70;
       int n = rand()%10;
       if(n % 3 == 0){
           triangle_coord1 = -2.0;
       }
       else if(n % 3 == 1){
           triangle_coord1 = 2.0;
       }
       else{
           triangle_coord1 = 6.0;
       }
       int q = rand()%10;
       if(q % 3 == 0){
           triangle_coord3 = -2.0;
       }
       else if(q%3 == 1){
           triangle_coord3 = 2.0;
       }
       else{
           triangle_coord3 = 6.0;
       }
       if(wait == 2){
           if(speed <= 10){
               speed++;
               while(70 % speed != 0){
                   speed++;
               }
           }
           wait = 0;
           int m = rand()%10;
           if(m % 3 == 0){
               triangle_coord2 = -2.0;
           }
           else if(m % 3 == 1){
               triangle_coord2 = 2.0;
           }
           else{
               triangle_coord2 = 6.0;
           }
       }
       else{
           wait++;
       }
    }
    //
    //Moment of impact
    QLabel* label=new QLabel("Squares dash");
    if(triangle_distance_a==0 && ((square_corner1 == triangle_coord1)||(square_corner1 == triangle_coord2)))
    {
        QMessageBox::warning(label,"Game Over", QString("Score: %1").arg(score));
        exit(1);
    }
    if(triangle_distance_b==0 && (square_corner1 == triangle_coord3))
    {
        QMessageBox::warning(label,"Game Over", QString("Score: %1").arg(score));
        exit(1);
    }
    //
}

void MainWindow::glPerspective( GLdouble fov, GLdouble aspectRatio, GLdouble zNear, GLdouble zFar )
{
    GLdouble rFov = fov * 3.14159265 / 180.0;
    glFrustum( -zNear * tan( rFov / 2.0 ) * aspectRatio,
               zNear * tan( rFov / 2.0 ) * aspectRatio,
               -zNear * tan( rFov / 2.0 ),
               zNear * tan( rFov / 2.0 ),
               zNear, zFar );
}
