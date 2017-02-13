#ifdef __APPLE__
#include <GLUT/glut.h>
#elif _WIN32 || __linux_
#include <GL/glut.h>
#endif
#include <stdlib.h>

void myinit(void)
{
    GLfloat light_ambient[] = { 0.0, 0.0, 1.0, 1.0 }; //Luz azul de ambiente
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 }; //Neblina
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 }; //Reflejos
    /*	light_position is NOT default value	*/
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glPushMatrix ();
    glRotatef (20.0, 1.0, 0.0, 0.0);
    
    glPushMatrix ();
    glTranslatef (-0.75, 0.5, 0.0);
    glRotatef (90.0, 1.0, 0.0, 0.0); //90 grados contra manecillas
    glutSolidTorus (0.275, 0.85, 15, 15); //A partir del centro
    glPopMatrix ();
    
    glPushMatrix ();
    glTranslatef (-0.75, -0.5, 0.0);
    glRotatef (270.0, 1.0, 0.0, 0.0);
    glutSolidCone (1.0, 2.0, 15, 15); //A partir de la base
    glPopMatrix ();
    
    glPushMatrix ();
    glTranslatef (0.75, 0.0, -1.0);
    glutSolidSphere (1.0, 15, 15);
    glPopMatrix ();
    
    glPopMatrix ();
    glFlush();
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho (-2.5, 2.5, -2.5*(GLfloat)h/(GLfloat)w,
                 2.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
    else
        glOrtho (-2.5*(GLfloat)w/(GLfloat)h,
                 2.5*(GLfloat)w/(GLfloat)h, -2.5, 2.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

/*  Main Loop
 *  Open window with initial window size, title bar,
 *  RGBA display mode, and handle input events.
 */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutCreateWindow (argv[0]);
    myinit();
    glutReshapeFunc (myReshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;             /* ANSI C requires main to return int. */
}
