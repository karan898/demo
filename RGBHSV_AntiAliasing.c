#include <GL/glut.h>
#include <math.h>

// HSV → RGB (short)
void hsv(float h, float s, float v, float *r, float *g, float *b)
{
    int i = h / 60;
    float f = h / 60 - i;
    float p = v * (1 - s), q = v * (1 - s * f), t = v * (1 - s * (1 - f));

    switch (i % 6)
    {
    case 0:
        *r = v;
        *g = t;
        *b = p;
        break;
    case 1:
        *r = q;
        *g = v;
        *b = p;
        break;
    case 2:
        *r = p;
        *g = v;
        *b = t;
        break;
    case 3:
        *r = p;
        *g = q;
        *b = v;
        break;
    case 4:
        *r = t;
        *g = p;
        *b = v;
        break;
    case 5:
        *r = v;
        *g = p;
        *b = q;
        break;
    }
}

// Draw square (reuse)
void square(int x1, int y1, int x2, int y2)
{
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // RGB squares
    glColor3f(1, 0, 0);
    square(50, 300, 150, 200);
    glColor3f(0, 1, 0);
    square(200, 300, 300, 200);
    glColor3f(0, 0, 1);
    square(350, 300, 450, 200);

    // HSV triangle
    float r, g, b;
    hsv(120, 1, 1, &r, &g, &b);
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    glVertex2f(150, 100);
    glVertex2f(300, 100);
    glVertex2f(225, 200);
    glEnd();

    // Anti-aliasing line
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glLineWidth(3);
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex2f(50, 50);
    glVertex2f(450, 50);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 400);
    glutCreateWindow("RGB HSV AA");

    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 500, 0, 400);

    glutDisplayFunc(display);
    glutMainLoop();
}