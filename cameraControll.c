//
//  cameraControll.h
//  cGraphics
//
//  Created by Ruben Cuadra on 2/2/17.
//  Copyright © 2017 Ruben Cuadra. All rights reserved.
//

//
//  main.h
//  cGraphics
//
//  Created by Ruben Cuadra on 1/26/17.
//  Copyright © 2017 Ruben Cuadra. All rights reserved.
//
#ifdef __APPLE__
#include <GLUT/glut.h>
#elif _WIN32 || __linux_
#include <GL/glut.h>
#endif

#include <stdlib.h>

float camX=0.0, camY=0.0, camZ=5.0;
float camXOffset=0.0, camYOffset=0.0, camZOffset=0.0;
float radioCono=0.5, altoCono=1.5, posXcono=0.0, posYcono=0.0, posZcono=0.0;

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void misObjetos()
{
    glPushMatrix();
    glTranslatef(3.0, -3.0, 1.0);
    glutWireSphere(1.0, 15, 10);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(posXcono, posYcono, posZcono);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glutWireCone(radioCono, altoCono, 10, 5);
    glPopMatrix();
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    
    glColor3f (1.0, 1.0, 1.0);
    
    glPushMatrix();
    /* viewing transformation  */
    // la camara, 3 1os valores de posicion, otros 3 valores
    // de a done ve la camara, y ultimos 3 valores son la
    // orientacion de la camara.
    gluLookAt (camX, camY, camZ, camXOffset, camYOffset, camZOffset, 0.0, 1.0, 0.0); //NORMAL
    //gluLookAt (camX, camY, camZ, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0); //PORTRAIT
    //gluLookAt (camX, camY, camZ, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0); //Comida Instagram
    
    
    glPushMatrix();
    glScalef (2.0, 3.0, 1.0);      /* modeling transformation */
    glutWireCube (1.0);
    glPopMatrix();
    
    misObjetos();
    
    glPopMatrix();
    
    glutSwapBuffers ();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();             /* clear the matrix */
}

/* ARGSUSED1 */
void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 'q':
            exit(0);
            break;
        case 'x':
            camX++;
            camXOffset++;
            glutPostRedisplay();
            break;
        case 'X':
            camX--;
            camXOffset--;
            glutPostRedisplay();
            break;
        case 'y':
            camY++;
            camYOffset++;
            glutPostRedisplay();
            break;
        case 'Y':
            camY--;
            camYOffset--;
            glutPostRedisplay();
            break;
        case 'z':
            camZ++;
            glutPostRedisplay();
            break;
        case 'Z':
            camZ--;
            glutPostRedisplay();
            break;
        case 'a':
            posXcono++;
            glutPostRedisplay();
            break;
        case 'A':
            posXcono--;
            glutPostRedisplay();
            break;
        case 'b':
            posYcono++;
            glutPostRedisplay();
            break;
        case 'B':
            posYcono--;
            glutPostRedisplay();
            break;
        case 'c':
            posZcono++;
            glutPostRedisplay();
            break;
        case 'C':
            posZcono--;
            glutPostRedisplay();
            break;
        case 'r':
            radioCono++;
            glutPostRedisplay();
            break;
        case 'R':
            radioCono--;
            glutPostRedisplay();
            break;
        case 'l':
            altoCono++;
            glutPostRedisplay();
            break;
        case 'L':
            altoCono--;
            glutPostRedisplay();
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
