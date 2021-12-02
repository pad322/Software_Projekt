#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *wid = new QWidget;
    QWidget *wid2 = new QWidget;
    QVBoxLayout *layout=new QVBoxLayout();

    QPushButton *start=new QPushButton("Start");
    QPushButton *credits=new QPushButton("Credits");
    QPushButton *exitfinish=new QPushButton("Exit");
    QLabel *title = new QLabel("Squares Dash");
    title->setAlignment(Qt::AlignHCenter);

    layout->addWidget(title);
    layout->addWidget(start);
    layout->addWidget(credits);
    layout->addWidget(exitfinish);

    MainWindow w;
    w.resize(800,800);

    QObject::connect(start,&QPushButton::clicked,&a,[&]()
    {
        w.started = false;
        wid->hide();
        w.show();
    });

    QObject::connect(credits,&QPushButton::clicked,&a,[&]()
    {
        QVBoxLayout *layout2 = new QVBoxLayout();
        QLabel *gods = new QLabel("Made by: Török Csongor & Stoica Attila & Fodor Lehel");
        layout2->addWidget(gods);
        wid2->setLayout(layout2);
        wid2->show();
    });

    QObject::connect(exitfinish,&QPushButton::clicked,&a,[&]()
    {
        exit(1);
    });
    wid->setLayout(layout);
    wid->setFixedSize(150,150);
    wid->show();
    return a.exec();
}
