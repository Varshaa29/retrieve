// colorcube.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<GL/glut.h>
float v[][3]={{-1.0,-1.0,1.0},{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0},{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},{-1.0,1.0,-1.0}};
float eye[]={0.0,0.0,5.0};

void square(float *a,float *b,float *c,float *d)
{
glBegin(GL_QUADS);
glColor3fv(a);
glVertex3fv(a);
glColor3fv(b);
glVertex3fv(b);
glColor3fv(c);
glVertex3fv(c);
glColor3fv(d);
glVertex3fv(d);
glEnd();
}
void colorcube(void)
{
square(v[0],v[1],v[2],v[3]);
square(v[4],v[5],v[6],v[7]);
square(v[0],v[1],v[5],v[4]);
square(v[3],v[2],v[6],v[7]);
square(v[1],v[5],v[6],v[2]);
square(v[0],v[4],v[7],v[3]);
}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(eye[0],eye[1],eye[2],0,0,0,0,1,0);
//glRotatef(angle[0],1,0,0);
//glRotatef(angle[1],0,1,0);
//glRotatef(angle[2],0,0,1);
colorcube();
glFlush();
glutSwapBuffers();
}
/*void spincube()
{
angle[axis]+=0.2;
if(angle[axis]>360)
angle[axis]=0;
glutPostRedisplay();
}
vo`id mouse(int btn,int state,int x,int y)
{
if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
axis=0;
if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
axis=1;
if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
axis=2;
}*/
void init()
{
glClearColor(0.0,0.0,0.0,1.0);
glEnable(GL_DEPTH_TEST);
}
void myReshape(int w,int h)
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if(w<=h)
	glFrustum(-2,2,-2*h/w,2*h/w,2,20);
else
	glFrustum(-2*w/h,2*w/h,-2,2,2,20);
glMatrixMode(GL_MODELVIEW);
glViewport(0,0,w,h);

}
void keyboard(unsigned char key,int x,int y)
{ 
	if(key == 'x')
		eye[0] += 0.1;
	if(key == 'X')
		eye[0] -= 0.1;
	if(key == 'y')
		eye[1] += 0.1;
	if(key == 'Y')
		eye[1] -= 0.1;
	if(key == 'z')
		eye[2] += 0.1;
	if(key == 'Z')
		eye[2] -= 0.1;
	glutPostRedisplay();
}


void main()
{
glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
glutInitWindowSize(500,500);
glutCreateWindow("3D SPINNING COLOR CUBE");
glutDisplayFunc(display);
glutKeyboardFunc(keyboard);
glutReshapeFunc(myReshape);
init();

//glutIdleFunc(spincube);
//glutMouseFunc(mouse);
glutMainLoop();
}
