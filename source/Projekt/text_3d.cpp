#include "text_3d.h"

typedef void (__stdcall *TessFuncPtr)(); // defintion of the callback function type

text_3d::text_3d(): glyphthickness(1.0f), base(0)
{

}

void text_3d::initfont(QFont& f, float thickness)
{
    font = &f;
    fm = new QFontMetricsF(f);
    glyphthickness = thickness;
    if (base) // if we have display lists already, delete them first
        glDeleteLists(base, 256);
    base = glGenLists(256); // generate 256 display lists
    if (base==0) {
        qDebug() << "cannot create display lists.";
        throw;
    }
    for (int i = 0; i < 256; ++i){ // loop to build the first 256 glyphs
        buildglyph(base+i, (char)i);
    }
}

void text_3d::print(QString text)
{
    glPushAttrib(GL_LIST_BIT); // Pushes The Display List Bits
    glListBase(base); // Sets The Base Character to 0
    glCallLists(text.length(), GL_UNSIGNED_BYTE, text.toLocal8Bit()); // Draws The Display List Text
    glPopAttrib(); // Pops The Display List Bits
}

void text_3d::buildglyph(GLuint listbase, int c)
{
       //ID "listbase" from character "c"
       GLUtriangulatorObj *tobj;
       QPainterPath path;
       path.addText(QPointF(0,0),*font, QString((char)c));
       QList<QPolygonF> poly = path.toSubpathPolygons(); // get the glyph outline as a list of paths
       // set up the tesselation
       tobj = gluNewTess();
       gluTessCallback(tobj, GLU_TESS_BEGIN, (TessFuncPtr)glBegin);
       gluTessCallback(tobj, GLU_TESS_VERTEX, (TessFuncPtr)glVertex3dv);
       gluTessCallback(tobj, GLU_TESS_END, (TessFuncPtr)glEnd);
       gluTessProperty(tobj, GLU_TESS_WINDING_RULE, GLU_TESS_WINDING_ODD);
       glNewList(listbase, GL_COMPILE); // start a new list
       glShadeModel(GL_FLAT);
       gluTessBeginPolygon(tobj, 0 ); // start tesselate
       // first, calculate number of vertices.
       int elements = 0; // number of total vertices in one glyph, counting all paths.
       for (QList<QPolygonF>::iterator it = poly.begin(); it != poly.end(); it) {
           elements= (*it).size();
       }

       GLdouble* vertices = (GLdouble*) malloc(elements* 3 * sizeof(GLdouble));
       int j=0;
       for (QList<QPolygonF>::iterator it = poly.begin(); it != poly.end(); it++) { // enumerate paths
           gluTessBeginContour(tobj);
           int i=0;
           for (QPolygonF::iterator p = (*it).begin(); p != it->end(); p) { // enumerate vertices
               int off = j+i;
               vertices[off+0] = p->rx();
               vertices[off+1] = -p->ry();
               vertices[off+2] = 0; // setting Z offset to zero.
               gluTessVertex(tobj, &vertices[off], &vertices[off] );
               i=3; // array math
           }
           gluTessEndContour(tobj);
           j= (*it).size()*3; // some more array math
       }
       gluTessEndPolygon(tobj);

       gluTessBeginPolygon(tobj, 0 );
       j = 0;
       for (QList<QPolygonF>::iterator it = poly.begin(); it != poly.end(); it) {
           gluTessBeginContour(tobj);
           int i = 0;
           for (QPolygonF::iterator p = (*it).begin(); p != it->end(); p) {
               int off = j+i;
               vertices[off+0] = p->rx();
               vertices[off+1] = -p->ry();
               vertices[off+2] = -glyphthickness; // Z offset set to "minus glyphtickness"
               gluTessVertex(tobj, &vertices[off], &vertices[off] );
               i=3;
           }
           gluTessEndContour(tobj);
           j = (*it).size()*3;
       }
       gluTessEndPolygon(tobj);
       free(vertices); // no need for the vertices anymore

       for (QList<QPolygonF>::iterator it = poly.begin(); it != poly.end(); it) {
           glBegin(GL_QUAD_STRIP);
           QPolygonF::iterator p;
           for (p = (*it).begin(); p != it->end(); p) {
               glVertex3f(p->rx(), -p->ry(), 0.0f);
               glVertex3f(p->rx(), -p->ry(), -glyphthickness);
           }
           p = (*it).begin();
           glVertex3f(p->rx(), -p->ry(), 0.0f); // draw the closing quad
           glVertex3f(p->rx(), -p->ry(), -glyphthickness); // of the "wrapping"
           glEnd();
       }

       GLfloat gwidth = (float)fm->height();
       glTranslatef(gwidth ,0.0f,0.0f);
       glEndList();
       gluDeleteTess(tobj);
}
