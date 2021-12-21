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
float angle=0;
Camera camera(glm::vec3(camX, camY, camZ));
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;
GLint VAO;



// Initialization routine.
void setup(void) {
  camX = 0.;
  camZ = 0.;
  camY = 0.;

  glClearColor(1.0, 1.0, 1.0, 0.0);
  escala = 3.f;
  /*angulo_x = 40.;
  tras_x = 0;
  escala = 0.3;
  */
  //matrix_view.lookAt(10, 10, 10, 0, 0, 0, 0, 1, 0);

  glEnableClientState(GL_VERTEX_ARRAY); // Enable vertex array.
  glEnable(GL_DEPTH_TEST);
  glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
  glm::mat4 view = camera.GetViewMatrix();
  for (int i=0;i<2;i++){
    Letter letter("6.fondo_textura", 0.f, 0.f, 0.f);
    letter.f();
    letter.setup(projection,view);
    letras.push_back(letter);
  }
}


void drawScene(void) {
    int vp[4];
    glGetIntegerv(GL_VIEWPORT, vp);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glUseProgram(p1_id);
    for(auto letra:letras){
      letra.draw(escala,angulo_x,angulo_y,angulo_z);
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
