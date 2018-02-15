#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>

void initFunc();
void funReshape(int w, int h);
void funDisplay();
void drawTriangulo();
void drawPuntos();

using namespace std;

// Variables globales
int w = 500;
int h = 500;

int main(int argc, char** argv) {

 // Inicializamos GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(w,h);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Sesion 2");
    
 // Inicializamos GLEW
    GLenum err = glewInit();
    if(GLEW_OK != err) printf("Error: %s\n", glewGetErrorString(err));
    printf("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    const GLubyte *oglVersion = glGetString(GL_VERSION);
    printf("This system supports OpenGL Version: %s\n", oglVersion);
    
 // Inicializaciones específicas
    initFunc();
    
 // Configuración CallBacks
    glutReshapeFunc(funReshape);
    glutDisplayFunc(funDisplay);
    
 // Bucle principal
    glutMainLoop();
    
    return 0;
}

void initFunc() {
    
 // Modelo de sombreado
    glShadeModel(GL_FLAT);
    //glShadeModel(GL_SMOOTH);
    
}

void funReshape(int wnew, int hnew) {
    
 // Configuración del Viewport
    glViewport(0, 0, wnew, hnew);

 // Captura de w y h
    w = wnew;
    h = hnew;
    
}

void funDisplay() {
    
 // Borramos el buffer de color
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
 // Para configurar la matriz matriz P
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
 // Matriz de Proyección P (Cámara)
    GLfloat aspectRatio = (GLfloat)w/(GLfloat)h;    
    GLfloat fovy = 50.0f, nplane = 0.1f, fplane = 20.0f;
    gluPerspective(fovy,aspectRatio,nplane,fplane);

 // Dibujamos un triángulo
    drawTriangulo();
    
 // Dibujamos dos puntos
    drawPuntos();

 // Intercambiamos los buffers
    glutSwapBuffers();
    
}

void drawTriangulo() {
    
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, -2.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f( 0.5, -0.5, -2.0f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f( 0.0f,  0.5f, -2.0f);
    glEnd();

}

void drawPuntos() {

    glPointSize(10);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);
        glVertex3f( 0.0f, 0.0f, -3.0f);
        glVertex3f( 0.5f, 0.5f, -3.0f);
    glEnd();

}