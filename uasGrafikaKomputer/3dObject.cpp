#include <GL/glut.h>

float angle = 0.0f; // Sudut rotasi

// Fungsi untuk menggambar kubus 3D
void drawCube() {
    glBegin(GL_QUADS);

    // Face depan
    glColor3f(1.0, 0.0, 0.0); // Merah
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);

    // Face belakang
    glColor3f(0.0, 1.0, 0.0); // Hijau
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);

    // Face kiri
    glColor3f(0.0, 0.0, 1.0); // Biru
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);

    // Face kanan
    glColor3f(1.0, 1.0, 0.0); // Kuning
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);

    // Face atas
    glColor3f(1.0, 0.0, 1.0); // Magenta
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);

    // Face bawah
    glColor3f(0.0, 1.0, 1.0); // Cyan
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);

    glEnd();
}

void display() {  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // Reset matrix modelview

    // Mengatur rotasi objek
    glTranslatef(0.0f, 0.0f, -5.0f); // Pindahkan objek jauh dari kamera
    glRotatef(angle, 1.0f, 1.0f, 0.0f); // Rotasi objek

    drawCube();

    glutSwapBuffers();
}

void timer(int value) {
    angle += 0.2f; // Update sudut rotasi
    if (angle > 360) {
        angle -= 360;
    }
    glutPostRedisplay(); // Meminta redraw
    glutTimerFunc(16, timer, 0); // Mengatur timer untuk animasi
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST); // Aktifkan depth test

    // Setup view
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Cube");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, timer, 0); // Set up timer for animation
    glutMainLoop();
    return 0;
}
