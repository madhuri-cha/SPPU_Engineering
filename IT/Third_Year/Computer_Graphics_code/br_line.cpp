#include <GL/glut.h>
#include <iostream>
#define zero 0.0
#define one 1.0
using namespace std;

int a, b, c, d, type;

int sign(int value)
{
    if(value > 0)
        return 1;
    else if(value < 0)
        return -1;
    else
        return 0;
}

void bresenham(int x1, int y1, int x2, int y2, int type) 
{
    int x = x1;
    int y = y1;
    int Dx = abs(x2 - x1);
    int Dy = abs(y2 - y1);
    int s1 = sign(x2-x1);
    int s2 = sign(y2-y1);
    int  interchange = 0;
	
    if (Dy > Dx) 
	{
        // Swap Dx and Dy, set interchange flag
        int temp = Dx;
        Dx = Dy;
        Dy = temp;
        interchange = 1;
    }
    int e = 2 * Dy - Dx;
	
    glPointSize(1.0f);
    if (type == 4) 
	{
        glPointSize(10.0f);
    }
	
    glBegin(GL_POINTS);
    glVertex2i(x, y);

    for (int i = 1; i <= Dx; i++) 
	{
        if (type == 4 || type == 1) 
		{
            glVertex2i((int)x, (int)y);
        }
        if (i % 4 == 0 && type == 2) 
		{
            glVertex2i((int)x, (int)y);
        }
        if ((i / 5) % 2 == 0 && type == 3) 
		{
            glVertex2i((int)x, (int)y);
        }
		
        while (e >= 0) 
		{
            if (interchange) 
			{
                x = x + s1;
            } 
			else 
			{
                y = y + s2;
            }
            e = e - 2 * Dx;
        }
		
        if (interchange) 
		{
            y = y + s2;
        } 
		else 
		{
            x = x + s1;
        }
        e = e + 2 * Dy;
    }
    glEnd();
}

void pattern()
{
    glBegin(GL_LINE_LOOP);
        glVertex2f(-100,70);
        glVertex2f(-100,-70);
        glVertex2f(100,-70);
        glVertex2f(100,70);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(0,70);
        glVertex2f(-100,0);
        glVertex2f(0,-70);
        glVertex2f(100,0);
        glVertex2f(0,70);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(-40,40);
        glVertex2f(-40,-40);
        glVertex2f(40,-40);
        glVertex2f(40,40);
    glEnd();
}

void display() 
{
    glClear(GL_COLOR_BUFFER_BIT);
	
    glColor3f(one, zero, zero);
    bresenham(-350, 0, 350, 0, 1);
    bresenham(0, 350, 0, -350, 1);
    glColor3f(zero, zero, one);
	
    pattern();
    glFlush();
}

void init() 
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-700 / 2, 700 / 2, -700 / 2, 700 / 2);
}

int cnt = 0;
int oldx, oldy;
int newx, newy;

void mouse(int button, int state, int x, int y) 
{
    if (state == GLUT_DOWN) 
	{
        if (button == GLUT_LEFT_BUTTON) 
		{
            int xi = x - 350;
            int yi = 350 - y;
            cout << xi << "\t" << yi << "\n";
            if (cnt == 0) 
			{
                oldx = xi;
                oldy = yi;
                cnt = 1;
                cout << "Starting point selected." << endl;
            } 
			else 
			{
                newx = xi;
                newy = yi;
                cnt = 0;
                cout << "Ending point selected." << endl;
				
                glPointSize(5.0f);
                glColor3f(1.0, 0.0, 0.0);
				
                glBegin(GL_POINTS);
                glVertex2i(oldx, oldy);
                glVertex2i(newx, newy);
                glEnd();
				
                // Draw the line immediately without waiting for display function
                glColor3f(1.0, 0.0, 0.0);
                bresenham(oldx, oldy, newx, newy, type);
                glFlush();
            }
        }
    }
}
void menu(int a) 
{
    type = a;
}
int main(int argc, char **argv) 
{
    a = 200, b = -200, c = -200, d = 200;
    type = 1;
	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Line Drawing");
	
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
	
    glutCreateMenu(menu);
    glutAddMenuEntry("Bresenham_SIMPLE", 1);
    glutAddMenuEntry("Bresenham_DOTTED", 2);
    glutAddMenuEntry("Bresenham_DASHED", 3);
    glutAddMenuEntry("Bresenham_SOLID", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
	
    glutMainLoop();
    return 0;
}
