#include<iostream>
#include<GL/glut.h>
using namespace std;

GLfloat point[4][2];
int clicks = 0;
bool curveDrawn = false;

void drawp(GLfloat x, GLfloat y)
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
}
void drawl(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
	glFlush();
}
void midpoint(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4)
{
	GLfloat xAB = (x1 + x2) / 2;
	GLfloat yAB = (y1 + y2) / 2;
	GLfloat xBC = (x2 + x3) / 2;
	GLfloat yBC = (y2 + y3 ) / 2;
	GLfloat xCD = (x3 + x4) / 2;
	GLfloat yCD = (y3 + y4) / 2;
	GLfloat xABC = (xAB + xBC) / 2;
	GLfloat yABC = (yAB + yBC) / 2;
	GLfloat xBCD = (xBC + xCD) / 2;
	GLfloat yBCD = (yBC + yCD) / 2;
	GLfloat xABCD = (xABC + xBCD) / 2;
	GLfloat yABCD = (yABC + yBCD) / 2;
	
	if((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) > 4 || (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2) > 4 || (x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3) > 4)
	{
		midpoint(x1, y1 , xAB , yAB , xABC , yABC , xABCD, yABCD);
		midpoint(xABCD, yABCD, xBCD, yBCD, xCD, yCD , x4, y4);
		
	}
	else
	{
		drawl(x1, y1 ,xABCD , yABCD);
		drawl(xABCD,yABCD,x4,y4);
		
	}
}
void mouse(int state, int btn , int x, int y)
{
	if(state == GLUT_DOWN && btn == GLUT_LEFT_BUTTON)
	{
		point[clicks][0] = GLfloat (x) ;
		point[clicks][1] = GLfloat (600 - y);
		clicks++;
		
		drawp((GLfloat) x, (GLfloat)(600 - y));
		
		if(clicks == 4)
		{
			drawl(point[0][0], point[0][1], point[1][0], point[1][1]);
			drawl(point[1][0], point[1][1], point[2][0], point[2][1]);
			drawl(point[2][0], point[2][1], point[3][0], point[3][1]);
			
			//draw curve 
			midpoint(point[0][0], point[0][1], point[1][0], point[1][1],
			point[2][0], point[2][1], point[3][0], point[3][1]);
		}
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	if(curveDrawn)
	{
		for(int i = 0; i < 4; ++i)
		{//redraw curve
			drawp(point[i][0], point[i][1]);
		}
	}
}
void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,600,0,600);
	
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("B Curve");
    
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
  
    glutMainLoop();
    return 0;
}

