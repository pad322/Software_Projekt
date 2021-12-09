#ifndef TEXT_3D_H
#define TEXT_3D_H


#include <QOpenGLFunctions>
#include <QString>
#include <QFont>
#include <QFontMetricsF>
#include <QList>
#include <QPainter>
#include <QChar>
#include <gl/GLU.h>
#include <QPainterPath>

class text_3d
{
public:
    text_3d();
    void initfont(QFont & f, float thickness); //-> set up a font and specify the "thickness"
    void print(QString text); //-> print it in 3D!
private:
    void buildglyph(GLuint b, int c); // create one displaylist for character "c"
    QFont* font;
    QFontMetricsF* fm;
    float glyphthickness;
    GLuint base; // the "base" of our displaylists
};

#endif // TEXT_3D_H
