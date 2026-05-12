
Practical – 11 Perform 3D translation, scaling, rotation, reflection, and shearing.
#include <GL/glut.h>
#include <stdlib.h>
                                                                      // Transformation variables
                                                                      float tx = 0,
                                                                            ty = 0, tz = 0;
float sx = 1, sy = 1, sz = 1;
float angle = 0;
int mode = 0;
// 1=translate, 2=scale, 3=rotate, 4=reflect, 5=shear
// ------------------ DRAW AXES ------------------
void drawAxes()
{
    glBegin(GL_LINES);
    // X axis (Red)
    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(3, 0, 0);
    // Y axis (Green)
    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 3, 0);
    // Z axis (Blue)
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 3);
    glEnd();
}
// ------------------ SHEAR ------------------
void applyShear()
{
    GLfloat shearMatrix[] = {
        1, 0.5, 0, 0,
        0.5, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1};
    glMultMatrixf(shearMatrix);
}
// ------------------ REFLECTION ------------------
void applyReflection()
{
    GLfloat reflectMatrix[] = {
        -1, 0, 0, 0, // Reflect across YZ plane
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1};
    glMultMatrixf(reflectMatrix);
}
// ------------------ DISPLAY ------------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(4, 4, 6, 0, 0, 0, 0, 1, 0);
    drawAxes();
    // ---------------- ORIGINAL OBJECT ----------------
    glPushMatrix();
    glTranslatef(1.5, 0, 0);
    glColor3f(0, 1, 0); // green
    glutWireCube(1.0);
    glPopMatrix();
    // ---------------- REFLECTED OBJECT ----------------
    if (mode == 4)
    {
        glPushMatrix();
        applyReflection(); // reflect across YZ plane
        glTranslatef(1.5, 0, 0);
        glColor3f(1, 0, 0); // red
        glutWireCube(1.0);
        glPopMatrix();
    }
    // ---------------- OTHER TRANSFORMS ----------------
    if (mode != 4)
    {
        glPushMatrix();
        glTranslatef(1.5, 0, 0);
        if (mode == 1)
            glTranslatef(tx, ty, tz);
        else if (mode == 2)
            glScalef(sx, sy, sz);
        else if (mode == 3)
            glRotatef(angle, 1, 1, 1);
        else if (mode == 5)
            applyShear();
        glColor3f(1, 1, 1);
        glutWireCube(1.0);
        glPopMatrix();
    }
    glutSwapBuffers();
}
// ------------------ KEYBOARD ------------------
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 't':
        mode = 1;
        tx += 0.3;
        break;
    case 's':
        mode = 2;
        sx += 0.2;
        sy += 0.2;
        sz += 0.2;
        break;
    case 'r':
        mode = 3;
        angle += 10;
        break;
    case 'f':
        mode = 4;
        break;
    case 'h':
        mode = 5;
        break;
    case 'c': // reset
        tx = ty = tz = 0;
        sx = sy = sz = 1;
        angle = 0;
        mode = 0;
        break;
    case 27:
        exit(0);
    }
    glutPostRedisplay();
}
// ------------------ INIT ------------------
void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0, 1);
}
// ------------------ RESHAPE ------------------
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float)w / h, 1, 100);
    glMatrixMode(GL_MODELVIEW);
}
// ------------------ MAIN ------------------
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Transformations - OpenGL");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
