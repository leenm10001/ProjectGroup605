#include <Windows.h>
#include <glut.h>
#include <cmath>

//***** Camera movement (DO NOT CHANGE THESE PARAMETERS) *****//
            // Default values
const float DEFAULT_RADIUS = 100.0f;
const float DEFAULT_ANGLE_X = 0.0f;
const float DEFAULT_ANGLE_Y = 0.0f;
// Camera angles for rotation
float angleX = 0.0f;
float angleY = 0.0f;
// Mouse tracking
float lastX = -100;
float lastY = -100;
bool leftButtonDown = false;
bool rightButtonDown = false;
// Camera distance from center
float radius = 100.0f;
//----------end of Camera movement----------------------------//

// you can add and update variables here
int width = 800;
int height = 600;






void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    //***** Convert spherical to Cartesian coordinates (DO NOT CHANGE)
    float camX = radius * sinf(angleY) * cosf(angleX);
    float camY = radius * sinf(angleX);
    float camZ = radius * cosf(angleY) * cosf(angleX);
    //***** End of Cartesian coordinates

    gluLookAt(camX, camY, camZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);



    //************Start drawing here *****************
    // use the teapot and the base plane to test your lightening and depth then  remove this part and draw your own object 
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(0, -12.5, 0);
    glutSolidTeapot(10.0);  // test object 
    glPopMatrix();

    // BASE PLANE ( YOU CAN CHANGE IT
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(50, -20, 50);
    glVertex3f(50, -20, -50);
    glVertex3f(-50, -20, -50);
    glVertex3f(-50, -20, 50);
    glEnd();





    glFlush();
}

// **** Current interactions  
// Mouse left-click to move around the object
// Mouse right-click to zoom in/out 
// Space to reset the view 


//***** Interaction : Mouse button press ( DO NOT CHANGE THIS METHOD)
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON)
        leftButtonDown = (state == GLUT_DOWN);
    else if (button == GLUT_RIGHT_BUTTON)
        rightButtonDown = (state == GLUT_DOWN);
    lastX = x;
    lastY = y;
}

//***** Interaction : Mouse motion  ( DO NOT CHANGE THIS METHOD)
void motion(int x, int y) {
    float dx = (x - lastX) * 0.01f;
    float dy = (y - lastY) * 0.01f;
    if (leftButtonDown) {
        angleY += dx;
        angleX += dy;
        //  vertical angle
        if (angleX > 1.5f) angleX = 1.5f;
        if (angleX < -1.5f) angleX = -1.5f;
    }
    if (rightButtonDown) {
        radius += dy * 20.0f; // Zoom in/out faster
        // zoom range between -200 & 200 
        if (radius < -200.0f) radius = -200.0f;
        if (radius > 200.0f) radius = 200.0f;
    }
    lastX = x;
    lastY = y;
    glutPostRedisplay(); //requests a redraw of the window
}


// Keyboard kyes handlers (this method handles "SPACE" key to reset the view , you can add more keys to the same method for animation)
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case ' ':
        angleX = DEFAULT_ANGLE_X;
        angleY = DEFAULT_ANGLE_Y;
        radius = DEFAULT_RADIUS;
        break;
    default:
        return;
    }
    glutPostRedisplay(); //requests a redraw of the window.

}

int main() {
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(width, height);
    glutCreateWindow("Write Your Group number");


    // Setup perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)width / (float)height, 1.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glutDisplayFunc(draw);


    // ****** Interaction : handlers ( DO NOT CHANGE)
    glutMouseFunc(mouse);  //  mouse button click/release handler
    glutMotionFunc(motion); // Register a callback for mouse motion while a button is held down (dragging)
    glutKeyboardFunc(keyboard);  // Register keyboard handler
    // ****** end of interaction


    glutMainLoop();
}
