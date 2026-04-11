#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

using namespace std;

int w = 640;
int h = 480;
int X1;
int Y1;
int flag = 0;
float boundaryFill[3] = {0,0,0}, interiorColor[3] = {1,1,1},
readPixel[3],fillColor[3];

void setPixel(int x, int y)
{
	glColor3fv(fillColor);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}
void getPixel(int x, int y, float *color)
{
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color);
}
int sign(float s)
{
    if(s < 0)
      return -1;
    else if(s > 0)
      return 1;
    else 
      return 0;  
}
void bresenhm(int X1, int Y1 ,int X2, int Y2)
{
    float dx , dy , sx, sy ,x,y ,e ,interchange;
     x = X1 ;
     y = Y1;
    dx = abs(X2 - X1);
    dy = abs(Y2 - Y1);

    sx = sign(X2 - X1);
    sy = sign(Y2 - Y1);
    if( dx >= dy)
    {
        float temp;
        temp = dx;
        dx = dy;
        dy = temp;
        interchange = 1;
    }
    else {
        interchange = 0;
    }
    e = 2 * dy - dx;
    glBegin(GL_POINTS);
    
    for(int i = 1; i <= dx ; i++)
    {
        glVertex2f(x,y);
        while(e >= 0)
        {
            if( interchange == 1)
              x = x + sx;
            else
                y = y + sy;
            e = e - (2 * dx);
        }
        if( interchange == 1)
                y = y + sy;
        else
                x = x + sx;
        e =  e + (2 * dy);
    
       glVertex2f(x,y);
       glEnd();
       glFlush();
    
}
void boundary(int x , int y)
{
    getPixel(x, y, readPixel);
    if(readPixel[0] != boundaryFill[0] && readPixel[1] != boundaryFill[1] && readPixel[2] != boundaryFill[2] )
    {
      setPixel(x,y);
      boundary(x+1 , y);
      boundary(x , y+1);
      boundary(x - 1 , y);
      boundary(x , y-1);
      glFlush();
    }
}
void flood(int x, int y)
{
    getPixel(x , y , readPixel);
    if(readPixel[0] == interiorColor[0] && readPixel[1] == interiorColor[1] && readPixel[2] == interiorColor[2])
{
   setPixel(x,y);
   flood(x+1 , y);
   flood(x , y+1);
   flood(x - 1, y);
   flood(x , y - 1);
  glFlush();
}
}
void myMouse(int btn , int state, int x, int y)
{
 if(state == GLUT_DOWN && btn == GLUT_LEFT_BUTTON)
 {
    X1 = x;
    Y1 = 480 - y;
    if(flag == 1)
    {
        boundary(X1, Y1);
    }
    if(flag == 2)
    {
      flood(X1, Y1);
    }
 }
}
void display()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,640,0,480);

    glClear(GL_COLOR_BUFFER_BIT);   
   bresenhm(300,200,350,250);
   bresenhm(350,250,400,200);
   bresenhm(400,200,350,150);
   bresenhm(350,150,300,200);
}
void menu(int choice)
{
 if(choice == 1)
 {
 	 flag = 1;
    fillColor[0] = 0;
    fillColor[1] = 1;
    fillColor[2] = 2;
   
 }
 if(choice == 2)
 {
 	 flag = 2;
    fillColor[0] = 0;
    fillColor[1] = 0.5;
    fillColor[2]  = 0.8;
   
 }
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(w,h);
    glutCreateWindow("Filling");

    glutCreateMenu(menu);
    glutAddMenuEntry("boundary",1);
    glutAddMenuEntry("Flood",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutMouseFunc(myMouse);
    
    
    glutMainLoop();
 
    return 0;
}
