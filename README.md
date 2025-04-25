
#include <Windows.h>
#include <glut.h>
#include <cmath>


//* Camera movement (DO NOT CHANGE THESE PARAMETERS) *//
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

// Display size
int width = 800;
int height = 600;

float headAngle = 0.0f;
bool headMovingRight = true;

float legAngle = 0.0f;
bool legForward = true;

bool animateLegs = true;
bool animateHead = true;


void mouse(int button, int state, int x, int y);
void motion(int x, int y);
void keyboard(unsigned char key, int x, int y);
void draw();

void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    float camX = radius * sinf(angleY) * cosf(angleX);
    float camY = radius * sinf(angleX);
    float camZ = radius * cosf(angleY) * cosf(angleX);
    gluLookAt(camX, camY, camZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // ----- Start Drawing Horse Robot -----

    
    glColor3f(0.55f, 0.27f, 0.07f); 
    glPushMatrix();
    glScalef(2.5f, 1.0f, 1.0f);
    glutSolidCube(20);
    glPopMatrix();

  
    glPushMatrix();
    glTranslatef(30.0f, 5.0f, 0.0f);
    glRotatef(headAngle, 0, 1, 0);
    glutSolidCube(10);
    glPopMatrix();

    
    glColor3f(0.0f, 0.0f, 0.0f); 
    glPushMatrix();
    glTranslatef(34.5f, 7.5f, 3.5f); 
    glutSolidSphere(1.2, 10, 10);
    glRotatef(headAngle, 0, 1, 0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(34.5f, 7.5f, -3.5f);
    glutSolidSphere(1.2, 10, 10);
    glPopMatrix();

   
    glColor3f(0.4f, 0.2f, 0.0f); 
    glPushMatrix();
    glTranslatef(32.0f, 10.0f, 3.0f); 
    glRotatef(-30, 0, 0, 1);
    glutSolidCone(1.0, 4.0, 10, 10);
    glRotatef(headAngle, 0, 1, 0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(32.0f, 10.0f, -3.0f); 
    glRotatef(-30, 0, 0, 1);
    glutSolidCone(1.0, 4.0, 10, 10);
    glPopMatrix();


   
    float legX[] = { 10, 10, -10, -10 };
    float legZ[] = { 8, -8, 8, -8 };
    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glTranslatef(legX[i], -10.0f, legZ[i]);

      
        if (i % 2 == 0) {
            glRotatef(legAngle, 1, 0, 0); 
        }
        else {
            glRotatef(-legAngle, 1, 0, 0); 
        }

        glTranslatef(0, -5.0f, 0); 

        glScalef(1.0f, 3.0f, 1.0f);
        glutSolidCube(5);
        glPopMatrix();
    }
    glPushMatrix();
    glTranslatef(-30.0f, 5.0f, 0.0f);
    glRotatef(-45, 0, 0, 1);
    glutSolidCone(3, 10, 10, 10);
    glPopMatrix();

   
    glColor3f(0.1f, 0.6f, 0.2f); 
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3f(150, -20, 150);
    glVertex3f(150, -20, -150);
    glVertex3f(-150, -20, -150);
    glVertex3f(-150, -20, 150);
    glEnd();
    glPopMatrix();
  
    glColor3f(0.4f, 0.7f, 1.0f);
    glPushMatrix();
    glBegin(GL_QUADS);

    
    glVertex3f(-150, -20, -150);
    glVertex3f(150, -20, -150);
    glVertex3f(150, 100, -150);
    glVertex3f(-150, 100, -150);

   
    glVertex3f(-150, -20, 150);
    glVertex3f(-150, -20, -150);
    glVertex3f(-150, 100, -150);
    glVertex3f(-150, 100, 150);

    
    glVertex3f(150, -20, -150);
    glVertex3f(150, -20, 150);
    glVertex3f(150, 100, 150);
    glVertex3f(150, 100, -150);

    
    glVertex3f(-150, -20, 150);
    glVertex3f(150, -20, 150);
    glVertex3f(150, 100, 150);
    glVertex3f(-150, 100, 150);

   
    glVertex3f(-150, 100, 150);
    glVertex3f(150, 100, 150);
    glVertex3f(150, 100, -150);
    glVertex3f(-150, 100, -150);

    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.5f, 0.4f, 0.3f);
    glTranslatef(0, -20, -100);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(60, 80, 20, 20);
    glPopMatrix();
   
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(80, 80, -100);
    glutSolidSphere(8, 20, 20);
    glPopMatrix();
    
    glColor3f(0.4f, 0.2f, 0.0f);
    glPushMatrix();
    glTranslatef(50.0f, -20.0f + 10.0f, 50.0f); 
    glScalef(1.0f, 4.0f, 1.0f);  
    glutSolidCube(5.0);         
    glPopMatrix();

    
    glColor3f(0.0f, 0.6f, 0.0f);
    glPushMatrix();
    glTranslatef(50.0f, -20.0f + 20.0f, 50.0f); 
    glutSolidSphere(10.0, 20, 20);
    glPopMatrix();
 
    glColor3f(0.4f, 0.2f, 0.0f);  
    glPushMatrix();
   
    glTranslatef(-60.0f, -20.0f + 10.0f, -40.0f);
    glScalef(1.0f, 4.0f, 1.0f);
    glutSolidCube(5.0f);
    glPopMatrix();

    
    glColor3f(0.0f, 0.6f, 0.0f);  
    glPushMatrix();
    
    glTranslatef(-60.0f, -20.0f + 20.0f, -40.0f);
    glutSolidSphere(10.0f, 20, 20);
    glPopMatrix();
    glFlush();
}
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON)
        leftButtonDown = (state == GLUT_DOWN);
    else if (button == GLUT_RIGHT_BUTTON)
        rightButtonDown = (state == GLUT_DOWN);
    lastX = x;
    lastY = y;
}


void motion(int x, int y) {
    float dx = (x - lastX) * 0.01f;
    float dy = (y - lastY) * 0.01f;
    if (leftButtonDown) {
        angleY += dx;
        angleX += dy;
        if (angleX > 1.5f) angleX = 1.5f;
        if (angleX < -1.5f) angleX = -1.5f;
    }
    if (rightButtonDown) {
        radius += dy * 20.0f;
        if (radius < -200.0f) radius = -200.0f;
        if (radius > 200.0f) radius = 200.0f;
    }
    lastX = x;
    lastY = y;
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case ' ': 
        angleX = DEFAULT_ANGLE_X;
        angleY = DEFAULT_ANGLE_Y;
        radius = DEFAULT_RADIUS;
        break;
    case 'w': 
    case 'W':
        animateLegs = !animateLegs;
        break;
    case 'r': 
    case 'R':
        animateHead = !animateHead;
        break;
    default:
        return;
    }
    glutPostRedisplay();
}

void update(int value) {
    
    if (animateHead) {
        if (headMovingRight) {
            headAngle += 1.0f;
            if (headAngle > 20.0f) headMovingRight = false;
        }
        else {
            headAngle -= 1.0f;
            if (headAngle < -20.0f) headMovingRight = true;
        }
    }

    
    if (animateLegs) {
        if (legForward) {
            legAngle += 1.5f;
            if (legAngle > 30.0f) legForward = false;
        }
        else {
            legAngle -= 1.5f;
            if (legAngle < -30.0f) legForward = true;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(30, update, 0);
}
int main() {
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Group605 - Horse Robot");

    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)width / (float)height, 1.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_COLOR_MATERIAL);

    
    GLfloat lightDir[] = { 1.0f, 1.0f, 1.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightDir);

    GLfloat lightPos[] = { -50.0f, 50.0f, 50.0f, 1.0f };
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos);

    glutTimerFunc(30, update, 0); 

    
    glutDisplayFunc(draw);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(30, update, 0);

    glutMainLoop();
    return 0;
    //hello
}




