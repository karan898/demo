#include <GL/glut.h>

float carX = -5;    // car movement
float sunAngle = 0; // sun rotation

// -------- DRAW SUN --------
void sun()
{
    glPushMatrix();
    glTranslatef(3, 3, 0);
    glRotatef(sunAngle, 0, 0, 1);

    glColor3f(1, 1, 0);
    glutSolidSphere(0.5, 20, 20);

    glPopMatrix();
}

// -------- DRAW CAR --------
void car()
{
    glPushMatrix();
    glTranslatef(carX, -2, 0);

    // body
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
    glVertex2f(-1, 0);
    glVertex2f(1, 0);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glEnd();

    // wheels
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(-0.7, -0.2, 0);
    glutSolidSphere(0.3, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7, -0.2, 0);
    glutSolidSphere(0.3, 20, 20);
    glPopMatrix();

    glPopMatrix();
}

// -------- DRAW TREE --------
void tree()
{
    glColor3f(0.5, 0.3, 0);
    glBegin(GL_QUADS);
    glVertex2f(-4, -2);
    glVertex2f(-3.8, -2);
    glVertex2f(-3.8, 0);
    glVertex2f(-4, 0);
    glEnd();

    glColor3f(0, 1, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-4.5, 0);
    glVertex2f(-3.3, 0);
    glVertex2f(-3.9, 1);
    glEnd();
}

// -------- DISPLAY --------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    sun();
    tree();
    car();

    glutSwapBuffers();
}

// -------- ANIMATION --------
void update(int v)
{
    carX += 0.05; // move car
    if (carX > 5)
        carX = -5;

    sunAngle += 2; // rotate sun

    glutPostRedisplay();
    glutTimerFunc(30, update, 0);
}

// -------- INIT --------
void init()
{
    glClearColor(0.5, 0.8, 1, 1);
    gluOrtho2D(-5, 5, -5, 5);
}

// -------- MAIN --------
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Simple Animation");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
}