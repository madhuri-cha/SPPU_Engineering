#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;
float nx, ny ,ox,oy;
void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10.0);
    glLineWidth(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-250,250,-250,250);
    }
    void kc(float dir , float l, int itr)
    {
        float ndir = ((3.14 * dir) / 180);
        nx = ox + (1 * cos(ndir));
        ny = oy + (1 * sin(ndir));

        if(itr == 0)
        {
         glBegin(GL_LINE_LOOP);
         glVertex2f(ox,oy);
         glVertex2f(nx,ny);
         glEnd();
         ox = nx;
         oy = ny;
        }
        else
        {
            itr--;
            kc(dir,l,itr);
            dir = dir + 60;
            kc(dir, l, itr);
            dir = dir - 120;
            kc(dir, l, itr);
            dir = dir + 60;
            kc(dir, l, itr);
        }
    }
    void display()
    {
    	int n;
      cout<<"iteration"<<endl;
      glColor3f(1.0f,0.0f,0.0f);
      ox = -150;
      oy = 50;
       cin>>n;
      kc(0,10,n);
      kc(-120,10,n);
      kc(120,10,n);
      glFlush();
    }
    int main(int argc, char **argv)
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500,500);
        glutInitWindowPosition(100,150);
        glutCreateWindow("koch");
        init();
        glutDisplayFunc(display);
        
        
        glutMainLoop();

     return 0;
    }
