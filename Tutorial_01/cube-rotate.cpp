#include <GLUT/glut.h>

//func
void setCamera();
void drawCP();
void drawPoints();
void drawCrtice();

GLfloat light_diffuse[] = {1.0, 0.0, .0, 0.0}; /* Red diffuse light. */
GLfloat light_position[] = {0.0, 0.0, 1.0, 0.0}; /* Infinite light location. */

GLfloat n[6][3] = {/* Normals for the 6 faces of a cube. */
  {-1.0, 0.0, 0.0},
  {0.0, 1.0, 0.0},
  {1.0, 0.0, 0.0},
  {0.0, -1.0, 0.0},
  {0.0, 0.0, 1.0},
  {0.0, 0.0, -1.0}
};
GLint faces[6][4] = {/* Vertex indices for the 6 faces of a cube. */
  {0, 1, 2, 3},
  {3, 2, 6, 7},
  {7, 6, 5, 4},
  {4, 5, 1, 0},
  {5, 6, 2, 1},
  {7, 4, 0, 3}
};
GLfloat v[8][3]; /* Will be filled in with X,Y,Z vertexes. */
void
drawBox(void) {
  int i;

  for (i = 0; i < 6; i++) {
    glBegin(GL_QUADS);
    glNormal3fv(&n[i][0]);
    glVertex3fv(&v[faces[i][0]][0]);
    glVertex3fv(&v[faces[i][1]][0]);
    glVertex3fv(&v[faces[i][2]][0]);
    glVertex3fv(&v[faces[i][3]][0]);
    glEnd();
  }
}

void
display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  drawBox();
  drawCP();
  glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
  glRotatef(0.2, 0, 5, 0);
  glutPostRedisplay();
  glutSwapBuffers();}

void
init(void) {
  /* Setup cube vertex data. */
  v[0][0] = v[1][0] = v[2][0] = v[3][0] = -1;
  v[4][0] = v[5][0] = v[6][0] = v[7][0] = 1;
  v[0][1] = v[1][1] = v[4][1] = v[5][1] = -1;
  v[2][1] = v[3][1] = v[6][1] = v[7][1] = 1;
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = 1;
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = -1;

  /* Enable a single OpenGL light. */
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0);
 glEnable(GL_LIGHTING);

  /* Use depth buffering for hidden surface elimination. */
  glEnable(GL_DEPTH_TEST);
  setCamera();}

void drawLines() {
  glBegin(GL_LINES);

  for (int i = 10; i != 0; i--) {

   // po x osi
    glVertex2f(-i, -0.1);
    glVertex2f(-i, 0.1);
    glVertex2f(i, -0.1);
    glVertex2f(i, 0.1);
    //po y osi
    glVertex2f(-0.1, -i);
    glVertex2f(0.1, -i);
    glVertex2f(-0.1, i);
    glVertex2f(0.1, i);

    //po z osi
      glColor3f(1.0f, 0.0f, 0.0f); //seems it doesnt register
    glVertex3f(0, -0.3, -i);
    glVertex3f(0, 0.3, -i);
    glVertex3f(0, -0.3, i);
    glVertex3f(0, 0.3, i);}
  glEnd();}

void drawCP() {

  //drawPoints();
  drawLines();
  glBegin(GL_LINES);
  glLineWidth(100);
  glVertex2f(-10.0f, 0);
  glVertex2f(10.0f, 0);
  glVertex2f(0.0f, 10);
  glVertex2f(0.0f, -10);
  glEnd();




}

void setCamera() {
  /* Setup the view of the cube. */
  glMatrixMode(GL_PROJECTION);

  gluPerspective(/* field of view in degree */ 50.0, /* aspect ratio */ 1, /* Z near */ 1, /* Z far */ 100.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  /* Setup the view of the cube. */
  gluLookAt(0, 0, 10 /*pozicija kamere*/, 0, 0, 0/* u koju tocku gleda ta kamera*/, 0, 1, 0 /*moran jos viti ca je to*/);


}

int
main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutCreateWindow("red 3D lighted cube");
  glutDisplayFunc(display);
  init();
 // glutTimerFunc(10, rotate, 10);
  glutMainLoop();
  return 0; /* ANSI C requires main to return int. */
}
