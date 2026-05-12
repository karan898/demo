// PRACTICAL-4
// BRESENHAM's CIRCLE DRAWING ALGO.

#include <GL/glut.h>
#include <stdio.h>

int radius;

void plotCirclePoints(int xc, int yc, int x, int y)
{
glBegin(GL_POINTS);
glVertex2i(xc + x, yc + y);
glVertex2i(xc - x, yc + y);
glVertex2i(xc + x, yc - y);
glVertex2i(xc - x, yc - y);
glVertex2i(xc + y, yc + x);
glVertex2i(xc - y, yc + x);
glVertex2i(xc + y, yc - x);
glVertex2i(xc - y, yc - x);
glEnd();
}

void drawCircle(int xc, int yc, int r)
{
int x = 0;
int y = r;
int d = 3 - 2 * r;

plotCirclePoints(xc, yc, x, y);

while (x <= y)
{

x++;

if (d < 0)
{
d = d + 4 * x + 6;
}
else
{
y--;
d = d + 4 * (x - y) + 10;
}

plotCirclePoints(xc, yc, x, y);
}
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 0.0, 0.0);
glPointSize(2.0);
drawCircle(0, 0, radius);

glFlush();
}

void init()
{
glClearColor(0.0, 0.0, 0.0, 1.0);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-200, 200, -200, 200);
}

int main(int argc, char** argv)
{
printf("Enter the radius of the circle: ");
scanf("%d", &radius);

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(100, 100);
glutCreateWindow("Bresenham Circle Drawing Algorithm");

init();
glutDisplayFunc(display);
glutMainLoop();

return 0;
}
