#include <GL/glut.h>

float angle = 0;
GLuint tex;

// Simple checker texture
void texture()
{
    unsigned char img[8][8][3];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            int c = ((i + j) % 2) * 255;
            img[i][j][0] = img[i][j][1] = img[i][j][2] = c;
        }

    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 8, 8, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

// Lighting
void light()
{
    GLfloat pos[] = {2, 2, 2, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

// Cube
void cube()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);

    glBegin(GL_QUADS);

    glNormal3f(0, 0, 1);
    glTexCoord2f(0, 0);
    glVertex3f(-1, -1, 1);
    glTexCoord2f(1, 0);
    glVertex3f(1, -1, 1);
    glTexCoord2f(1, 1);
    glVertex3f(1, 1, 1);
    glTexCoord2f(0, 1);
    glVertex3f(-1, 1, 1);

    glEnd();

    glDisable(GL_TEXTURE_2D);
}

// Display
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(4, 4, 6, 0, 0, 0, 0, 1, 0);
    glRotatef(angle, 1, 1, 0);

    cube();

    glutSwapBuffers();
}

// Keyboard
void key(unsigned char k, int x, int y)
{
    if (k == 'r')
        angle += 10;
    if (k == 27)
        exit(0);
    glutPostRedisplay();
}

// Init
void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0, 1);
    light();
    texture();
}

// Reshape
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float)w / h, 1, 100);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Shading + Texture");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);

    glutMainLoop();
}