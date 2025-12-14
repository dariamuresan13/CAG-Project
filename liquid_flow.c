#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

static GLfloat flow1 = 0.0;
static GLfloat flow2 = 0.0;
static GLfloat flow3 = 0.0;
static GLfloat flow4 = 0.0;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    glColor3f(1.0, 0.40, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-45.0, -40.0);
    glVertex2f(-25.0, -40.0);
    glVertex2f(-25.0, 40.0);
    glVertex2f(-45.0, 40.0);
    glEnd();

    glColor3f(0.0, 0.50, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-45.0, -40.0);
    glVertex2f(-25.0, -40.0);
    glVertex2f(-25.0, 40.0 - flow1);
    glVertex2f(-45.0, 40.0 - flow1);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

void flowDisplay(void)
{
    flow1 += 0.005;
    flow2 += 0.02;

    if (flow1 > 75.0)
    {
        flow1 = 75.0;
    }

    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1500, 600);
    glutInitWindowPosition(20, 100);
    glutCreateWindow("Liquid Flow");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(flowDisplay);
    glutMainLoop();
    return 0;
}
