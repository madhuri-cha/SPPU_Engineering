#include <GL/gl.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

float angle = 0.0;
float rotation_speed = -0.9;
float bx = 10;
float carSpeed = 2;

void circle(GLfloat r, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = r * cos(angle);
        float y = r * sin(angle);

        glVertex2f((x + cx), (y + cy));
    }
    glEnd();

    glColor3ub(150, 150, 150);
    glBegin(GL_POLYGON);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = (r - 4) * cos(angle);
        float y = (r - 4) * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix(); // for new matrix

    glTranslatef(bx, 0, 0); // moving the car

    // Enlarge the car
    glScalef(1.5, 1.5, 1.0); // Scale the car uniformly by a factor of 1.5

    // Car body
    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
    glVertex2d(410, 100);
    glVertex2d(490, 100);
    glVertex2d(485, 130);
    glVertex2d(410, 130);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(420, 130);
    glVertex2d(475, 130);
    glVertex2d(465, 160);
    glVertex2d(430, 160);
    glEnd();

    // Car windows
    glColor3ub(220, 220, 220);
    glBegin(GL_POLYGON);
    glVertex2d(425, 130);
    glVertex2d(445, 130);
    glVertex2d(445, 150);
    glVertex2d(430, 150);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(450, 130);
    glVertex2d(470, 130);
    glVertex2d(465, 150);
    glVertex2d(450, 150);
    glEnd();

    glPushMatrix();

    glTranslatef(465, 100, 0);

    glRotatef(angle, 0, 0, 1); // Rotate the wheel

    glColor3ub(0, 0, 0); // Black color for wheel

    circle(14, 0, 0); // Use equal radii for perfect circle
    // Draw nuts
    glColor3ub(255, 255, 255); // White color for nuts
    circle(2.5, 10, 0);        // Draw nut 1
    glColor3ub(255, 255, 255);
    circle(2.5, -10, 0); // Draw nut 2
    glColor3ub(255, 255, 255); // White color for nuts
    circle(2.5, 0, 10);
    glColor3ub(255, 255, 255); // White color for nuts
    circle(2.5, 0, -10);

    glPopMatrix();
    glPushMatrix();

    glTranslatef(430, 100, 0);
    glRotatef(angle, 0, 0, 1); // Rotate the wheel

    glColor3ub(0, 0, 0); // Black color for wheel
    circle(14, 0, 0);    // Use equal radii for perfect circle
    // Draw nuts
    glColor3ub(255, 255, 255); // White color for nuts
    circle(2.5, 10, 0);        // Draw nut 1
    glColor3ub(255, 255, 255);
    circle(2.5, -10, 0); // Draw nut 2
    glColor3ub(255, 255, 255); // White color for nuts
    circle(2.5, 0, 10);
    glColor3ub(255, 255, 255); // White color for nuts
    circle(2.5, 0, -10);
    glPopMatrix();
    glPopMatrix();

    bx += carSpeed;
    angle += rotation_speed; // Increment angle for rotation

    if (bx > 0)
        bx = -500;
    glutPostRedisplay();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(300, 50);

    glutCreateWindow("A Moving Car Scenario");
    glClearColor(0.529, 0.808, 0.922, 0.0); // Sky blue color
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500, 0.0, 500);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}

