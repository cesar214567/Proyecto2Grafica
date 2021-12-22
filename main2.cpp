#include <iostream>
#include "glew.h"
//#include <glad/glad.h>

#include <GL/freeglut.h>
#include "glut_ply.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "stb_image.h"
#include "shader.h"
#include "esfera.h"
#include "camera.h"
#include "letter.h"
//LETRAS
vector<Letter> letras;
float angulo_x, angulo_y, angulo_z;
float escala;

//camera
float camX, camZ,camY;
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;
GLint VAO;



// Initialization routine.
void setup(void) {
  camX = 0.;
  camZ = 0.;
  camY = 0.;

  glClearColor(1.0, 1.0, 1.0, 0.0);
  escala = 0.25f;
  /*angulo_x = 40.;
  tras_x = 0;
  escala = 0.3;
  */
  //matrix_view.lookAt(10, 10, 10, 0, 0, 0, 0, 1, 0);

  glEnableClientState(GL_VERTEX_ARRAY); // Enable vertex array.
  glEnable(GL_DEPTH_TEST);

  float fila1= 1.f;
  float fila2 = 0.35f;
  float fila3 = -0.35f;

  float sangria1 = -0.1f;
  float sangria2 = -0.25f;
  float sangria3 = -0.f;

  Letter F("6.fondo_textura", 0.7f + sangria1, fila1, 0.f);
  F.f();
  F.setup();
  letras.push_back(F);

  Letter E("6.fondo_textura", 1.1f + sangria1, fila1, 0.f);
  E.e();
  E.setup();
  letras.push_back(E);

  Letter L("6.fondo_textura", 1.5f + sangria1, fila1, 0.f);
  L.l();
  L.setup();
  letras.push_back(L);

  Letter I("6.fondo_textura", 1.9f + sangria1, fila1, 0.f);
  I.i();
  I.setup();
  letras.push_back(I);

  Letter Z("6.fondo_textura", 2.4f + sangria1, fila1, 0.f);
  Z.Z();
  Z.setup();
  letras.push_back(Z);

  Letter C("6.fondo_textura", 0.5f + sangria2, fila2, 0.f);
  C.C();
  C.setup();
  letras.push_back(C);

  Letter U("6.fondo_textura", 0.9f + sangria2, fila2, 0.f);
  U.U();
  U.setup();
  letras.push_back(U);

  Letter M("6.fondo_textura", 1.4f + sangria2, fila2, 0.f);
  M.M();
  M.setup();
  letras.push_back(M);

  Letter P("6.fondo_textura", 1.9f + sangria2, fila2, 0.f);
  P.P();
  P.setup();
  letras.push_back(P);

  Letter L2("6.fondo_textura", 2.4f + sangria2, fila2, 0.f);
  L2.l();
  L2.setup();
  letras.push_back(L2);

  Letter E2("6.fondo_textura", 2.8f + sangria2, fila2, 0.f);
  E2.e();
  E2.setup();
  letras.push_back(E2);

  Letter V("6.fondo_textura", 0.8f + sangria3, fila3, 0.f);
  V.V();
  V.setup();
  letras.push_back(V);

  Letter A("6.fondo_textura", 1.2f + sangria3, fila3, 0.f);
  A.A();
  A.setup();
  letras.push_back(A);

  Letter L3("6.fondo_textura", 1.7f + sangria3, fila3, 0.f);
  L3.l();
  L3.setup();
  letras.push_back(L3);

  Letter E3("6.fondo_textura", 2.1f + sangria3, fila3, 0.f);
  E3.e();
  E3.setup();
  letras.push_back(E3);
}

void drawScene(void) {
    int vp[4];
    glGetIntegerv(GL_VIEWPORT, vp);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Camera camera(glm::vec3(camX, camY, camZ));
    glm::mat4 projection = glm::ortho(-0.3f, 3.0f, -3.0f, 3.0f);
    //glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    glm::mat4 view = camera.GetViewMatrix();
    for(auto letra:letras){
      letra.draw(escala, angulo_x, angulo_y, angulo_z, projection, view);
    }

    glutSwapBuffers();
}

// OpenGL window reshape routine.
void resize(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y) {

    switch (key) {
        case 27: exit(0);
        case 'q': angulo_x++; break;
        case 'Q': angulo_x--; break;
        case 'w': angulo_y++; break;
        case 'W': angulo_y--; break;
        case 'e': angulo_z++; break;
        case 'E': angulo_z--; break;
        case 's': escala += 0.1; break;
        case 'S': escala -= 0.1; break;

        case 'c': camX += 1; break;
        case 'C': camX -= 1; break;
        case 'v': camY += 1; break;
        case 'V': camY -= 1; break;
        case 'b': camZ += 1; break;
        case 'B': camZ -= 1; break;
    }
    cout << "x: " << angulo_x << endl;
    cout << "y: " << angulo_y << endl;
    cout << "z: " << angulo_z << endl;
    cout << "escala: " << escala << endl;
    cout << "camx: " << camX << endl;
    cout << "camy: " << camY << endl;
    cout << "camz: " << camZ << endl;
    glutPostRedisplay();
}



// Main routine.
int main(int argc, char **argv) {
  srand(time(NULL));


    glutInit(&argc, argv);

    //glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowSize(SCR_WIDTH, SCR_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Visualizando modelo");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    glewExperimental = GL_TRUE;
    glewInit();
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    /*if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }*/

    setup();
    glutMainLoop();
    return 0;
}
