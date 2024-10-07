#include <GL/glut.h>
#include <math.h>
#include <cstdlib>
#include <cstdio>
#include <stdlib.h>
#include <iostream>

using namespace std;

static int shoulder = 0, elbow = 0, ball = 0;
static double i=4.5, j=0.0, k=0.0;
static int sWidth = 500, sHeight = 500;
bool pick = false;
void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
   glEnable(GL_DEPTH_TEST);
}

void robotarm(double i, double j, double k)
{
   glClear (GL_DEPTH_BUFFER_BIT);
   glEnable( GL_TEXTURE_2D );

   glPushMatrix();

   glTranslatef (0.0, 0.0, 0.0);         
   glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) shoulder, 0.5, 0.0, 0.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glColor3f(1.0,1.0,1.0);
   glScalef (2.0, 0.4, 1.0);
   glutSolidCube (1.0);
   glPopMatrix();
   
   
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glColor3f(0.0,1.0,1.0);
   glScalef (2.0, 0.4, 1.0);
   glutSolidCube (1.0);
   glPopMatrix();
if(pick == true){

   glRotatef ((GLfloat) ball, 0.0, 0.0, 1.0);
   glTranslatef (1.5, 0.0, 0.0);
   glColor3f( 0.0 , 0.7 , 0.0);
   glutSolidTorus( 0.2 , 0.2 , 20 , 50);
   glPopMatrix();
   glPopMatrix();
}

if(pick == false){
   glPopMatrix();
   glRotatef ((GLfloat) ball, 0.0, 0.0, 1.0);
   glTranslatef (i, j, k);
   glColor3f( 0.0 , 0.7 , 0.0);
   glutSolidTorus( 0.2 , 0.2 , 20 , 50);
   glPopMatrix();
}
   
   glutSwapBuffers();
}

void display(void) {
  	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, (GLsizei) sWidth, (GLsizei) sHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) sWidth/(GLfloat) sHeight, 2 , 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 8.8, 0.0, 0.0, -100.0, 0.0, 7.5, 7.5);
    robotarm(i, j, k);
  	glFlush();
}


void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 's':
         shoulder = (shoulder + 5) % 360;
         glutPostRedisplay();
         break;
      case 'S':
         shoulder = (shoulder - 5) % 360;
         glutPostRedisplay();
         break;
      case 'e':
	 if (elbow < 180)
         elbow = (elbow + 5) % 360;
         glutPostRedisplay();
         break;
      case 'E':
	 if (elbow > 0)
         elbow = (elbow - 5) % 360;
         glutPostRedisplay();
         break;
      case 'x':
         pick = true;
         glutPostRedisplay();
         break;
      case 'c':
         pick = false;
         ball = elbow;
         glutPostRedisplay();
         break;
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (sWidth, sHeight); 
   glutInitWindowPosition (500, 200);
   glutCreateWindow ("T-900\'s got nothing on this.");
   init();

    glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
