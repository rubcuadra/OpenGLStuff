#ifdef __APPLE__
    #include <GLUT/glut.h>
#elif _WIN32 || __linux_
    #include <GL/glut.h>
#endif
#include <stdlib.h>

static GLfloat minX = -1000.0;
static GLfloat maxX =  1000.0;
static GLfloat minY = -1000.0;
static GLfloat maxY =  1000.0;

static GLfloat height = 300.0; //Per Char
static GLfloat width =  150.0; //Per Char

static GLfloat y_start=600;
static GLfloat x_start=-900;


void drawP(GLfloat x_offset,GLfloat y_offset)
{
    glPushMatrix();
        glTranslatef(x_offset,y_offset,0.0);
        glColor3f(0.0, 0.0, 0.0);
        glRectf(0,0,10.0,height);             //VERTICAL IZQ
        glRectf(0, height,width,height+10);       //TOP HORIZONTAL
        glRectf(0, height/2,width,(height/2)+10);       //MIDDLE HORIZONTAL
        glRectf(width-10,height,width,(height/2)+10);   //HALF RIGHT VERTICAL
    glPopMatrix();
}

void drawR(GLfloat x_offset,GLfloat y_offset)
{
    drawP(x_offset,y_offset);               //Draw a P
    glPushMatrix();                         //Draw extra line
        glTranslatef(x_offset,y_offset,0.0);
        glBegin(GL_LINES);
            glVertex2i(0,height/2);
            glVertex2i(width,0);
        glEnd();
    glPopMatrix();
}

void drawU(GLfloat x_offset,GLfloat y_offset)
{
    glPushMatrix();
        glTranslatef(x_offset,y_offset,0.0);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINE_STRIP);
            glVertex2i(0,height+10);          //Top Left
            glVertex2i(0,0);                  //Down-Left
            glVertex2i(width,0);                //Down-Right
            glVertex2i(width,height+10);        //Top-Right
        glEnd();
    glPopMatrix();
}

void drawB(GLfloat x_offset,GLfloat y_offset)
{
    glPushMatrix();
        glTranslatef(x_offset,y_offset,0.0);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINE_LOOP);
            glVertex2i(0,0);
            glVertex2i(0,height+10);
            glVertex2i(width-20,height+10);
            glVertex2i(width-20,height/2);
            glVertex2i(0,height/2);
            glVertex2i(width,height/2);
            glVertex2i(width,0);
        glEnd();
    glPopMatrix();
}
void drawC(GLfloat x_offset,GLfloat y_offset)
{
    glPushMatrix();
        glTranslatef(x_offset,y_offset,0.0);
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_LINE_STRIP); // C
            glVertex2i(width,0);
            glVertex2i(0,0);
            glVertex2i(0,height);
            glVertex2i(width,height);
        glEnd();
    glPopMatrix();
}
void drawE(GLfloat x_offset,GLfloat y_offset)
{
    drawC(x_offset,y_offset);
    glPushMatrix();
        glTranslatef(x_offset,y_offset,0.0);
        glBegin(GL_LINES);      //Missing middle -
            glVertex2i(0,height/2);
            glVertex2i(width,height/2);
        glEnd();
    glPopMatrix();
}

void drawN(GLfloat x_offset,GLfloat y_offset)
{
    glPushMatrix();
        glTranslatef(x_offset,y_offset,0.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINE_STRIP);
            glVertex2i(0,0);
            glVertex2i(0,height);
            glVertex2i(width,0);
            glVertex2i(width,height);
        glEnd();
    glPopMatrix();
}

void drawA(GLfloat x_offset,GLfloat y_offset)
{
    glPushMatrix();
        glTranslatef(x_offset,y_offset,0.0);
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_LINE_STRIP);     //Esto nos pinta una U al reves
            glVertex2i(0,0);
            glVertex2i(0,height);
            glVertex2i(width,height);
            glVertex2i(width,0);
        glEnd();
        glBegin(GL_LINES);
            glVertex2i(0,height/2);
            glVertex2i(width,height/2);
        glEnd();
    glPopMatrix();
}

void drawD(GLfloat x_offset,GLfloat y_offset)
{
    glPushMatrix();
        glTranslatef(x_offset,y_offset,0.0);
        glColor3f(0.0, 1.0, 1.0);
        glBegin(GL_LINE_LOOP);
            glVertex2i(0,0);
            glVertex2i(0,height);
    
            glVertex2i(width-40,height); //Curva de la D
            glVertex2i(width,height-50);
            glVertex2i(width,50);
            glVertex2i(width-40,0);
    
        glEnd();
    glPopMatrix();
}

void draw0(GLfloat x_offset,GLfloat y_offset)
{
    glPushMatrix();
        glTranslatef(x_offset,y_offset,0.0);
        glColor3f(1.0, 0.0, 1.0);
        glBegin(GL_LINE_LOOP);
            glVertex2i(0,0);
            glVertex2i(0,height);
            glVertex2i(width,height);
            glVertex2i(width,0);
        glEnd();
    glPopMatrix();
}

void draw1(GLfloat x_offset,GLfloat y_offset)
{
    glPushMatrix();
        glTranslatef(x_offset,y_offset,0.0);
        glColor3f(1, 0.7, 0.2);
        glBegin(GL_LINE_STRIP);
            glVertex2i(0,height-30);
            glVertex2i(width/2,height);
            glVertex2i(width/2,0);
        glEnd();
    glPopMatrix();
}

void draw9(GLfloat x_offset,GLfloat y_offset)
{
    glPushMatrix();
        glTranslatef(x_offset,y_offset,0.0);
        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_LINE_STRIP);
            glVertex2i(width,0);
            glVertex2i(width,height);
            glVertex2i(0,height);
            glVertex2i(0,height/2);
            glVertex2i(width,height/2);
        glEnd();
    glPopMatrix();
}

void draw2(GLfloat x_offset,GLfloat y_offset)
{
    glPushMatrix();
        glTranslatef(x_offset,y_offset,0.0);
        glColor3f(0.7, 1, 0.2);
        glBegin(GL_LINE_STRIP);
            glVertex2i(0,height);
            glVertex2i(width,height);
            glVertex2i(width,height/2);
            glVertex2i(0,height/2);
            glVertex2i(0,0);
            glVertex2i(width,0);
        glEnd();
    glPopMatrix();
}

void drawName(GLfloat x_offset,GLfloat y_offset)
{
    drawR(x_offset,y_offset); x_offset+=width+50;
    drawU(x_offset,y_offset); x_offset+=width+50;
    drawB(x_offset,y_offset); x_offset+=width+50;
    drawE(x_offset,y_offset); x_offset+=width+50;
    drawN(x_offset,y_offset);
}

void drawLastName(GLfloat x_offset,GLfloat y_offset)
{
    drawC(x_offset,y_offset); x_offset+=width+50;
    drawU(x_offset,y_offset); x_offset+=width+50;
    drawA(x_offset,y_offset); x_offset+=width+50;
    drawD(x_offset,y_offset); x_offset+=width+50;
    drawR(x_offset,y_offset); x_offset+=width+50;
    drawA(x_offset,y_offset);
}

void drawNumber(GLfloat x_offset,GLfloat y_offset)
{
    drawA(x_offset,y_offset); x_offset+=width+50;
    draw0(x_offset,y_offset); x_offset+=width+50;
    draw1(x_offset,y_offset); x_offset+=width+50;
    draw0(x_offset,y_offset); x_offset+=width+50;
    draw1(x_offset,y_offset); x_offset+=width+50;
    draw9(x_offset,y_offset); x_offset+=width+50;
    draw1(x_offset,y_offset); x_offset+=width+50;
    draw0(x_offset,y_offset); x_offset+=width+50;
    draw2(x_offset,y_offset);
}

void dibujado(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    drawName(x_start,y_start);     y_start-=(height+100.0);
    drawLastName(x_start,y_start); y_start-=(height+100.0);
    drawNumber(x_start,y_start);   y_start = 600;
    glutSwapBuffers();
}

void inicializar(void)
{
    glClearColor (0.8, 0.8, 0.8, 0.0);
    glLineWidth(5.0); //Default = 1
    glShadeModel (GL_FLAT);
}

void reshape(int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(minX,maxX,minY,maxY,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (1000, 1000);
    glutInitWindowPosition (0,0);
    glutCreateWindow ("RubenCuadraA01019102");
    inicializar ();
    glutDisplayFunc(dibujado);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
