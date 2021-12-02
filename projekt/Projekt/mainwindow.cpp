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
    //event->key() == Qt::Key_Enter &&

    if( event->key() == Qt::Key_A )
    {
        if(cucc1==2.0)
        {
            cucc2=-4.0;
            cucc1=-2.0;
        }
        else if(cucc1>-2.0)
        {
            cucc1-=4;
            cucc2-=4;
        }

    }
    if( event->key() == Qt::Key_D )
    {
        if(cucc1==2.0)
        {
            cucc2=4.0;
            cucc1=6.0;
        }
        else if(cucc1<6.0)
        {
            cucc1+=4;
            cucc2+=4;
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
    //-4.8
    if(y==-4.8)
        y+=0.1;
    else if(y==-4.6)
        y-=0.1;
}

float a=-70;
float b=-70;
int speed = 1, wait = 0;

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
    //glRotatef(rot,1.0,1.0,1.0);
    //nap
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(xx, yy, zz); // center of circle
    for(int i = 0; i <= 20;i++) {
        glVertex3f(
            xx + (6 * cos(i * twicePi / 20)),
            yy + (6 * sin(i * twicePi / 20)),
            zz = -70
        );
    }
    glEnd();
    //
    //fa1
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.5f, 0.4f);
    glVertex3f(-6, 0.0f, fa1);
    glVertex3f(-8, 0.0f, fa1);
    glVertex3f(-8, 6.0f, fa1);
    glVertex3f(-6, 6.0f, fa1);
    glEnd();
    //
    //fa2
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.8f, 0.2f);
    glVertex3f(8, 0.0f, fa2);
    glVertex3f(10, 0.0f, fa2);
    glVertex3f(10, 6.0f, fa2);
    glVertex3f(8, 6.0f, fa2);
    glEnd();
    //
    //fa3
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.9f, 0.6f);
    glVertex3f(-6, 0.0f, fa3);
    glVertex3f(-8, 0.0f, fa3);
    glVertex3f(-8, 6.0f, fa3);
    glVertex3f(-6, 6.0f, fa3);
    glEnd();
    //
    //fa4
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.4f, 0.9f);
    glVertex3f(8, 0.0f, fa4);
    glVertex3f(10, 0.0f, fa4);
    glVertex3f(10, 6.0f, fa4);
    glVertex3f(8, 6.0f, fa4);
    glEnd();
    //
    //fa5
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.6f);
    glVertex3f(-6, 0.0f, fa5);
    glVertex3f(-8, 0.0f, fa5);
    glVertex3f(-8, 6.0f, fa5);
    glVertex3f(-6, 6.0f, fa5);
    glEnd();
    //
    //fa6
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.2f, 0.1f);
    glVertex3f(8, 0.0f, fa6);
    glVertex3f(10, 0.0f, fa6);
    glVertex3f(10, 6.0f, fa6);
    glVertex3f(8, 6.0f, fa6);
    glEnd();
    //
    //fa7
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.2f, 0.3f);
    glVertex3f(-6, 0.0f, fa7);
    glVertex3f(-8, 0.0f, fa7);
    glVertex3f(-8, 6.0f, fa7);
    glVertex3f(-6, 6.0f, fa7);
    glEnd();
    //
    //fa8
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.2f, 0.2f);
    glVertex3f(8, 0.0f, fa8);
    glVertex3f(10, 0.0f, fa8);
    glVertex3f(10, 6.0f, fa8);
    glVertex3f(8, 6.0f, fa8);
    glEnd();
    //
    //negyzet
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex3f(cucc1, 0.0f, 0.0f);
    glVertex3f(cucc2, 0.0f, 0.0f);
    glVertex3f(cucc2, 2.0f, 0.0f);
    glVertex3f(cucc1, 2.0f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex3f(cucc1, 0.0f, 0.0f);
    glVertex3f(cucc2, 0.0f, 0.0f);
    glVertex3f(cucc2, 0.0f, 1.0f);
    glVertex3f(cucc1, 0.0f, 1.0f);
    glEnd();
    //
    //ut bal
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.0f, 0.6f);
    glVertex3f(ut_bal, -0.1f, -70.0f);
    glVertex3f(ut_bal-2, -0.1f, -70.0f);
    glVertex3f(ut_bal-2, -0.1f, 10.0f);
    glVertex3f(ut_bal, -0.1f, 10.0f);
    glEnd();
    //
    //ut kozep
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.0f, 0.6f);
    glVertex3f(ut_kozep, -0.1f, -70.0f);
    glVertex3f(ut_kozep-2, -0.1f, -70.0f);
    glVertex3f(ut_kozep-2, -0.1f, 10.0f);
    glVertex3f(ut_kozep, -0.1f, 10.0f);
    glEnd();
    //
    //ut jobb
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.0f, 0.6f);
    glVertex3f(ut_jobb, -0.1f, -70.0f);
    glVertex3f(ut_jobb-2, -0.1f, -70.0f);
    glVertex3f(ut_jobb-2, -0.1f, 10.0f);
    glVertex3f(ut_jobb, -0.1f, 10.0f);
    glEnd();
    //
    //alap haromszog
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(koord-2, 0.0f, a);
    glVertex3f(koord, 0.0f, a);
    glVertex3f(koord-1, 1.0f, a);
    glEnd();
    //
    //dupla haromszog
    if(speed>1){
        glBegin(GL_TRIANGLES);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(koord2-2, 0.0f, a);
        glVertex3f(koord2, 0.0f, a);
        glVertex3f(koord2-1, 1.0f, a);
        glEnd();
    }
    //
    //feltavolsag haromszog
    if(a>-35){
        b+=speed;
        glBegin(GL_TRIANGLES);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(koord3-2, 0.0f, b);
        glVertex3f(koord3, 0.0f, b);
        glVertex3f(koord3-1, 1.0f, b);
        glEnd();
    }
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
    //haromszogek sebessege
    a += speed;
    fa1 += speed;
    fa2 += speed;
    fa3 += speed;
    fa4 += speed;
    fa5 += speed;
    fa6 += speed;
    fa7 += speed;
    fa8 += speed;
    if(fa1 > 5.0){
        fa1 = -70;
    }
    if(fa2 > 5.0){
        fa2 = -70;
    }
    if(fa3 > 5.0){
        fa3 = -70;
    }
    if(fa4 > 5.0){
        fa4 = -70;
    }
    if(fa5 > 5.0){
        fa5 = -70;
    }
    if(fa6 > 5.0){
        fa6 = -70;
    }
    if(fa7 > 5.0){
        fa7 = -70;
    }
    if(fa8 > 5.0){
        fa8 = -70;
    }
    if(a > 5.0 && b > 5.0){
       a = -70;
       b = -70;
       int n = rand()%10;
       if(n % 3 == 0){
           koord = -2.0;
       }
       else if(n % 3 == 1){
           koord = 2.0;
       }
       else{
           koord = 6.0;
       }
       int q = rand()%10;
       if(q % 3 == 0){
           koord3 = -2.0;
       }
       else if(q%3 == 1){
           koord3 = 2.0;
       }
       else{
           koord3 = 6.0;
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
               koord2 = -2.0;
           }
           else if(m % 3 == 1){
               koord2 = 2.0;
           }
           else{
               koord2 = 6.0;
           }
       }
       else{
           wait++;
       }
    }
    //
    //Utkozes pillanata
    QLabel* label=new QLabel("Squares dash");
    if(a==0 && ((cucc1 == koord)||(cucc1 == koord2)))
    {
        QMessageBox::warning(label,"Géjmover","A háromszög veri a négyzetet.");
        exit(1);
    }
    if(b==0 && (cucc1 == koord3))
    {
        QMessageBox::warning(label,"Géjmover","A háromszög veri a négyzetet.");
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
