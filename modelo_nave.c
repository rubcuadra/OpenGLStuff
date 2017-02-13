//
//  nave.h
//  cGraphics
//
//  Created by Ruben Cuadra on 2/9/17.
//  Copyright © 2017 Ruben Cuadra. All rights reserved.
//

#ifdef __APPLE__
    #include <GLUT/glut.h>
#elif _WIN32 || __linux_
    #include <GL/glut.h>
#endif
#include <stdlib.h>

float camX=3.0, camY=2.0, camZ=5.0;
float camXOffset=0.0, camYOffset=0.0, camZOffset=0.0;
float slices=10,stacks=10;
float radioCono=0.3, altoCono=2;
float generatorX = 0.2,generatorY=1,icoZ = 0.5; //Altura y grosor de torus/Icos
float cubeY = 0.2,sphereRadio = 0.3;
float angle = 0;
float coneMultiplier = 1.5; //Altura extra del cono mas grande

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void drawConnector() //Center Cones + the taller one
{
    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glutWireCone( radioCono, altoCono*coneMultiplier, slices, stacks);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glutWireCone( radioCono, altoCono, slices, stacks);
    glRotatef(180.0, 0.0, 1.0, 0.0);
    glutWireCone( radioCono, altoCono, slices, stacks);
    glPopMatrix();
}

void drawGenerators() //Icos + Torus
{
    glPushMatrix(); //Right
    glTranslatef(altoCono+generatorX, 0.0, 0.0);
    glPushMatrix();
    glScalef (generatorX,generatorY,icoZ);
    glutWireIcosahedron();
    glScalef(1,1,1);
    glutWireTorus(generatorY+0.3, 0.5,10, 10);
    glPopMatrix();
    glTranslatef( -2*(altoCono+generatorX), 0.0, 0.0); //Left
    glPushMatrix();
    glScalef (generatorX,generatorY,icoZ);
    glutWireIcosahedron();
    glScalef(1,1,1);
    glutWireTorus(generatorY+0.3, 0.2,10, 10);
    glPopMatrix();
    glPopMatrix();
}
void drawMainDeck()
{
    glPushMatrix(); //Muro Vertical
    glTranslatef(0.0,-(altoCono*coneMultiplier+(cubeY/2)), 0.0);
    glScalef(altoCono,cubeY,icoZ*0.6);
    glutWireCube(1);
    glPopMatrix();
    glPushMatrix(); //Lateral Derecha
    glTranslatef(altoCono/2 -0.1,-(altoCono*coneMultiplier+(cubeY/2)+(altoCono/4)), 0.0);
    glScalef(cubeY,altoCono/2,icoZ*0.6);
    glutWireCube(1);
    glPopMatrix();
    glPushMatrix(); //Lateral Izquierda
    glTranslatef(-altoCono/2 +0.1,-(altoCono*coneMultiplier+(cubeY/2)+(altoCono/4)), 0.0);
    glScalef(cubeY,altoCono/2,icoZ*0.6);
    glutWireCube(1);
    glPopMatrix();
}

void drawPowerCore()
{
    glPushMatrix();
    glTranslatef(0.0,-(altoCono*coneMultiplier+sphereRadio+cubeY+0.2),0.0);
    glutWireSphere(sphereRadio,slices, stacks);
    glutWireSphere(sphereRadio/2,slices, stacks);
    glPopMatrix();
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    
    glColor3f (1.0, 1.0, 1.0);
    
    glPushMatrix();
    gluLookAt (camX, camY, camZ, camXOffset, camYOffset, camZOffset, 0.0, 0.0, 1.0); //NORMAL
    //gluLookAt (camX, camY, camZ, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0); //PORTRAIT
    //gluLookAt (camX, camY, camZ-1, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0); //Comida Instagram
    glRotated( angle, 0.0, 0.0,1.0);
    drawConnector();
    drawGenerators();
    drawMainDeck();
    drawPowerCore();
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

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'q':
            exit(0);
            break;
        case 'a':
            camX++;
            camXOffset++;
            glutPostRedisplay();
            break;
        case 'd':
            camX--;
            camXOffset--;
            glutPostRedisplay();
            break;
        case 'w':
            camY++;
            camYOffset++;
            glutPostRedisplay();
            break;
        case 's':
            camY--;
            camYOffset--;
            glutPostRedisplay();
            break;
        case 'r':
            camZ++;
            camZOffset++;
            glutPostRedisplay();
            break;
        case 'f':
            camZ--;
            camZOffset--;
            glutPostRedisplay();
            break;
        case ' ':
            angle+=5;
            glutPostRedisplay();
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
