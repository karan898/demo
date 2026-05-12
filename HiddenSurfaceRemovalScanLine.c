
PRACTICAL 12 SCANLINE FOR HIDDEN SURFACE REMOVAL
#include <GL/glut.h>
#include <float.h>

#define W 500
#define H 500

    float zbuf[W][H];

// Near (green)
float t1[3][3] = {{150, 350, 0.2}, {100, 150, 0.2}, {300, 150, 0.2}};
// Far (red)
float t2[3][3] = {{200, 300, 0.8}, {150, 100, 0.8}, {350, 100, 0.8}};

// Z-buffer init
void initZ()
{
    for (int i = 0; i < W; i++)
        for (int j = 0; j < H; j++)
            zbuf[i][j] = FLT_MAX;
}

// Plot pixel with depth
void pixel(int x, int y, float z)
{
    if (x >= 0 && x < W && y >= 0 && y < H && z < zbuf[x][y])
    {
        zbuf[x][y] = z;
        glVertex2i(x, y);
    }
}

// Back-face culling (simplified)
int visible(float v[3][3])
{
    float dx1 = v[1][0] - v[0][0], dy1 = v[1][1] - v[0][1];
    float dx2 = v[2][0] - v[0][0], dy2 = v[2][1] - v[0][1];
    return (dx1 * dy2 - dy1 * dx2) > 0;
}

// Scan-line fill
void fill(float v[3][3])
{
    int ymin = v[0][1], ymax = v[0][1];

    for (int i = 1; i < 3; i++)
    {
        if (v[i][1] < ymin)
            ymin = v[i][1];
        if (v[i][1] > ymax)
            ymax = v[i][1];
    }

    for (int y = ymin; y <= ymax; y++)
    {
        int x1 = W, x2 = 0;

        for (int i = 0; i < 3; i++)
        {
            int j = (i + 1) % 3;
            float xA = v[i][0], yA = v[i][1];
            float xB = v[j][0], yB = v[j][1];

            if ((yA <= y && yB > y) || (yB <= y && yA > y))
            {
                int x = xA + (y - yA) * (xB - xA) / (yB - yA);
                if (x < x1)
                    x1 = x;
                if (x > x2)
                    x2 = x;
            }
        }

        for (int x = x1; x <= x2; x++)
            pixel(x, y, v[0][2]);
    }
}

// Display
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    initZ();

    glBegin(GL_POINTS);

    if (visible(t2))
    {
        glColor3f(1, 0, 0);
        fill(t2);
    }
    if (visible(t1))
    {
        glColor3f(0, 1, 0);
        fill(t1);
    }

    glEnd();
    glFlush();
}

// Init
void init()
{
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, W, 0, H);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(W, H);
    glutCreateWindow("Hidden Surface");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
