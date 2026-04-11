#include<iostream>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<cmath>
#define h 1000
#define w 1000
using namespace std;
bool showAxes = true;
int screenHeight = 1000;
int screenWidth = 1000;

void myInit()
{
	glClearColor(1.0,1.0,1.0,1.0);//set to black
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
	glColor3f(1.0,0.0,0.0);//set to red
}
void setPixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();

}

void axes()
{
	if(showAxes)
	{
		for(int i = -h ; i <= h ; i++)
		{
			setPixel(i ,0);
			setPixel(0,i);
		}
	}
}
int sign(float x)
{
	if(x < 0)
	  {
	   return -1;
      }        
	else if(x >= 0)
	 
	 {
	  return 1;
    }  
	else
    
    {
		return 0; 
	}
}
void dda(int x1, int y1, int x2 , int y2)
{
	if( x1 == x2 && y1 == y2)
{ 
      cout<<"same"<<endl;
      return;
}
     float dx ;
     float dy;
	 dx = x2 - x1;
     dy = y2 - y1;
	float length;
	if(abs(dx) > abs(dy))
	 {
	 	length = dx;
	 }
	 else 
	 {
	 	length = dy;
	 }
	float DX;
	float DY;
	 DX = dx / length;
	 DY = dy / length;
	 float x = x1 + 0.5 * sign(DX);
	 float y = y1 + 0.5 * sign(DY);
	 glBegin(GL_POINTS);
	 glPointSize(10);
	 for(int i = 0 ; i <= length; i++)
	 {
	 	glVertex2i(round(x), round(y));
	 	x += DX;
	 	y += DY;
	 }
	 glEnd();
	 glFlush();
}
void simple()
{
	int x1,  y1,  x2 ,  y2;
	cout<<"x1 and y1"<<endl;
	cin>>x1;
	cin>>y1;
	cout<<endl;
	cout<<"x2 and y2"<<endl;
	cin>>x2;
	cin>>y2;
	dda(x1,y1,x2,y2);
}
void dotted()
{
	float x1,  y1,  x2 ,  y2;
	cout<<"x1 and y1"<<endl;
	cin>>x1;
	cin>>y1;
	cout<<"x2 and y2"<<endl;
	cin>>x2;
	cin>>y2;
	glBegin(GL_POINTS);
  	glPointSize(90.0);
	  dda(x1,y1,x2,y2);
	glEnd();
	glFlush();
}
void solid()
{
	float x1,  y1,  x2 ,  y2;
	cout<<"x1 and y1"<<endl;
	cin>>x1;
	cin>>y1;
	cout<<"x2 and y2"<<endl;
	cin>>x2;
	cin>>y2;
	glLineWidth(100.0);
	glBegin(GL_LINES);
	   dda(x1,y1,x2,y2);
	glEnd();
	glFlush();
}
void boat()
{
	dda(-30,-50,30,-50);
	dda(-30,-50,-50,0);
	dda(-50,0,50,0);
	dda(30,-50,50,0);
	dda(-35,0,0,50);
	dda(35,0,0,50);
}
void dashed()
{
	float x1,  y1,  x2 ,  y2;
	cout<<"x1 and y1"<<endl;
	cin>>x1;
	cin>>y1;
	cout<<"x2 and y2"<<endl;
	cin>>x2;
	cin>>y2;
	glBegin(GL_POINTS);
    glPointSize(10);
	float dx = x2 - x1;
	float dy = y2 - y1;
	float length;
	if(abs(dx) > abs(dy))
	 {
	 	length = dx;
	 }
	 else 
	 {
	 	length = dy;
	 }
	float DX;
	float DY;
	 DX = dx / length;
	 DY = dy / length;
	 float x = x1 + 0.5 * sign(DX);
	 float y = y1 + 0.5 * sign(DY);
	 
	 for(int i = 0 ; i <= length; i++)
	 {
	 	if( i % 5 != 0)
	 	{
		
	 	glVertex2i(round(x), round(y));
	   }
	 	x += DX;
	 	y += DY;
	   
	 }
	 glEnd();
	 glFlush();
	
}
void myMouse(int btn , int state ,int x, int y)
{
	if(state == GLUT_DOWN)
	{
	
	if( btn == GLUT_LEFT_BUTTON )
	{
		cout<<"x and y coordintes"<<x<<" , "<< screenHeight - y<<endl;
		showAxes = !showAxes;
		glutPostRedisplay();
	}
	else if(btn == GLUT_RIGHT_BUTTON);
	{
		cout<<"x and y coordintes"<<x<<" , "<< screenHeight - y<<endl;
		glutAttachMenu(GLUT_RIGHT_BUTTON);
		glutPostRedisplay();
	}
}
}
int selected;
void menu(int index)
{
	selected = index;
	glutSwapBuffers();
	glutPostRedisplay();
}
void my_func()
{
	glClear(GL_COLOR_BUFFER_BIT);
	if(showAxes)
	 {
	 axes();
    }
    if(selected == 1)
    {
    	simple();
	}
	else if(selected == 2)
	   {
	   	solid();
	   }
	else if(selected == 3)
	{
	 dotted();   
    }  
    else if(selected == 4)
    {
    	boat();
	}
	else if(selected == 5)
    {
    	dashed();
	}
   glFlush();
}

int main(int charc, char **charv)
{
	glutInit(&charc, charv);
    glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(400, 200);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("DDA");
    
    glutDisplayFunc(my_func);
    
    glutCreateMenu(menu);
    glutAddMenuEntry("simple",1);
    glutAddMenuEntry("solid",2);
    glutAddMenuEntry("dotted",3);
    glutAddMenuEntry("boat",4);
    glutAddMenuEntry("dashed",5);
    glutMouseFunc(myMouse);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    myInit();
    glutMainLoop();
    
 return 0;	
}
