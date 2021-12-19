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
#include "fondo.h"
#include "vaca.h"
#define POINT_LIGHT_POSITIONS 8
#define ESFERAS 6

//camera
float camX, camZ=3,camY;
float angle=0;
Camera camera(glm::vec3(camX, camY, camZ));
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;
bool firstMouse = true;
float lastX = (float)SCR_WIDTH / 2.0;
float lastY = (float)SCR_HEIGHT / 2.0;
GLint VAO;
 //matrix_view;
// positions of the point lights
glm::vec3 pointLightPositions[] = {
    glm::vec3(0.f, 0.f, 0.f),
    glm::vec3(0.f, 0.f, 10.f),
    glm::vec3(0.f, 10.f, 0.f),
    glm::vec3(0.f, 10.f, 10.f),
    glm::vec3(10.f, 0.f, 0.f),
    glm::vec3(10.f, 0.f, 10.f),
    glm::vec3(10.f, 10.f, 0.f),
    glm::vec3(10.f, 10.f, 10.f),

};

unsigned int quadVAO = 0;
unsigned int quadVBO;
void renderQuad()
{
  if (quadVAO == 0)
  {
    // positions
    glm::vec3 pos1(-1.0f, 1.0f, 0.0f);
    glm::vec3 pos2(-1.0f, -1.0f, 0.0f);
    glm::vec3 pos3(1.0f, -1.0f, 0.0f);
    glm::vec3 pos4(1.0f, 1.0f, 0.0f);

    // texture coordinates
    glm::vec2 uv1(0.0f, 1.0f);
    glm::vec2 uv2(0.0f, 0.0f);
    glm::vec2 uv3(1.0f, 0.0f);
    glm::vec2 uv4(1.0f, 1.0f);
    // normal vector
    glm::vec3 nm(0.0f, 0.0f, 1.0f);

    // calculate tangent/bitangent vectors of both triangles
    glm::vec3 tangent1, bitangent1;
    glm::vec3 tangent2, bitangent2;
    // triangle 1
    // ----------
    glm::vec3 edge1 = pos2 - pos1;
    glm::vec3 edge2 = pos3 - pos1;
    glm::vec2 deltaUV1 = uv2 - uv1;
    glm::vec2 deltaUV2 = uv3 - uv1;

    float f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

    tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
    tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
    tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);

    bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
    bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
    bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);

    // triangle 2
    // ----------
    edge1 = pos3 - pos1;
    edge2 = pos4 - pos1;
    deltaUV1 = uv3 - uv1;
    deltaUV2 = uv4 - uv1;

    f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

    tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
    tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
    tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);

    bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
    bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
    bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);

    float quadVertices[] = {
        // positions            // normal         // texcoords  // tangent                          // bitangent
        pos1.x, pos1.y, pos1.z, nm.x, nm.y, nm.z, uv1.x, uv1.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
        pos2.x, pos2.y, pos2.z, nm.x, nm.y, nm.z, uv2.x, uv2.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
        pos3.x, pos3.y, pos3.z, nm.x, nm.y, nm.z, uv3.x, uv3.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,

        pos1.x, pos1.y, pos1.z, nm.x, nm.y, nm.z, uv1.x, uv1.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z,
        pos3.x, pos3.y, pos3.z, nm.x, nm.y, nm.z, uv3.x, uv3.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z,
        pos4.x, pos4.y, pos4.z, nm.x, nm.y, nm.z, uv4.x, uv4.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z};
    // configure plane VAO
    glGenVertexArrays(1, &quadVAO);
    glGenBuffers(1, &quadVBO);
    glBindVertexArray(quadVAO);
    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void *)(8 * sizeof(float)));
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void *)(11 * sizeof(float)));
  }
  glBindVertexArray(quadVAO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
  glBindVertexArray(0);
}

char* readShader(char* aShaderFile)
{
    FILE* filePointer = fopen(aShaderFile, "rb");
    char* content = NULL;
    long numVal = 0;

    fseek(filePointer, 0L, SEEK_END);
    numVal = ftell(filePointer);
    fseek(filePointer, 0L, SEEK_SET);
    content = (char*) malloc((numVal+1) * sizeof(char));
    fread(content, 1, numVal, filePointer);
    content[numVal] = '\0';
    fclose(filePointer);
    return content;
}

static void Error(char *message) {
    printf(message);
}

/* Compila shader */
static void CompileShader (GLuint id) {
    GLint status;
    glCompileShader(id);
    glGetShaderiv(id, GL_COMPILE_STATUS, &status);
    if (!status) {
        GLint len;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
        char* message = (char*) malloc(len*sizeof(char));
        glGetShaderInfoLog(id, len, 0, message);
        Error(message);
        free(message);
    }
}

/* Link−edita shader */
static void LinkProgram (GLuint id) {
    GLint status;
    glLinkProgram(id);
    glGetProgramiv(id, GL_LINK_STATUS, &status);
    if (!status) {
        GLint len;
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &len);
        char* message = (char*) malloc(len*sizeof(char));
        glGetProgramInfoLog(id, len, 0, message);
        Error(message);
        free(message);
    }
}

static void CreateShaderProgram (char* vertexShaderFile, char* fragmentShaderFile, GLuint &p_id) {
    char*	vertexShader   = readShader(vertexShaderFile);
    char*	fragmentShader = readShader(fragmentShaderFile);

    /* vertex shader */
    GLuint v_id = glCreateShader(GL_VERTEX_SHADER);
    if (v_id == 0)
        Error("Could not create vertex shader object");

    glShaderSource(v_id, 1, (const char**) &vertexShader, 0);
    CompileShader(v_id);

    /* fragment shader */
    GLuint f_id = glCreateShader(GL_FRAGMENT_SHADER);
    if (f_id == 0)
        Error("Could not create fragment shader object");

    glShaderSource(f_id, 1, (const char**) &fragmentShader, 0);
    CompileShader(f_id);

    /* program */
    p_id = glCreateProgram();
    if (p_id == 0)
        Error("Could not create program object");
    glAttachShader(p_id, v_id);
    glAttachShader(p_id, f_id);
    LinkProgram(p_id);

}





// Initialization routine.
void setup(void) {
  camX = 20.;
  camZ = 20.;
  glClearColor(1.0, 1.0, 1.0, 0.0);

  /*angulo_x = 40.;
  tras_x = 0;
  escala = 0.3;
  */
  //matrix_view.lookAt(10, 10, 10, 0, 0, 0, 0, 1, 0);

  glEnableClientState(GL_VERTEX_ARRAY); // Enable vertex array.
  glEnable(GL_DEPTH_TEST);
  //CreateShaderProgram("basico_textura.vs","basico_textura.fs", p1_id);

  //CreateShaderProgram("basico_textura_luces.vs", "basico_textura_luces.fs", p1_id);
  //CreateShaderProgram("./basico1.vs", "./basico1.fs", p2_id);
  shader_esferas = new Shader("./1.esferas_textura_luz.vs", "./1.esferas_textura_luz.fs");

  shader_esferas->bindAttributeLocation(vertex_id, "aPos");
  shader_esferas->bindAttributeLocation(normal_id, "aNormal");

  cout << "aPos: " << vertex_id << endl;
  cout << "aNormal: " << normal_id << endl;



}


void drawScene(void) {
    int vp[4];
    glGetIntegerv(GL_VIEWPORT, vp);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glUseProgram(p1_id);
    shader_esferas->use();
    //glUniform3fv(glGetUniformLocation(p1_id, "viewPos"), 1, &camara_posicion[0]);
    //glUniform1f(glGetUniformLocation(p1_id, "shininess"), 32.0f);
    shader_esferas->setVec3("viewPos", camera.Position);
    shader_esferas->setFloat("shininess", 32.0f);

    //setPOINTLIGHTS
    for (int i = 0; i < POINT_LIGHT_POSITIONS;i++){
      setPointLight(pointLightPositions[i], shader_esferas);
    }
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    glm::mat4 view = camera.GetViewMatrix();

    fondo->draw();
    fondo2->draw();


    /*glm::vec3 lightPos(0.5f, 1.0f, 0.3f);

    shader_fondo->use();
    unsigned int diffuseMap = loadTexture("resources/textures/brickwall.jpg");
    unsigned int normalMap = loadTexture("resources/textures/brickwall_normal.jpg");

    shader_fondo->use();
    shader_fondo->setMat4("projection", projection);
    shader_fondo->setMat4("view", view);
    // render normal-mapped quad
    glm::mat4 model = glm::mat4(1.0f);
    shader_fondo->setMat4("model", model);
    shader_fondo->setVec3("viewPos", camera.Position);
    shader_fondo->setVec3("lightPos", lightPos);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, diffuseMap);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, normalMap);
    //renderQuad();
    model = glm::mat4(1.0f);
    model = glm::translate(model, lightPos);
    model = glm::scale(model, glm::vec3(0.1f));
    shader_fondo->setMat4("model", model);
    //renderQuad();
    */




    // point light 1
    //lightingShader.setVec3("pointLights[0].position", pointLightPositions[0]);
    //glUniform3fv(glGetUniformLocation(p1_id, "pointLights[0].position"), 1, &pointLightPositions[0][0]);
    //shader_esferas->setVec3("pointLights[0].position", 1, &pointLightPositions[0][0]);
    //glUniform3f(glGetUniformLocation(p1_id, "pointLights[0].ambient"), 0.05f, 0.05f, 0.05f);
    //shader_esferas->setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);

    //glUniform3f(glGetUniformLocation(p1_id, "pointLights[0].diffuse"), 0.8f, 0.8f, 0.8f);
    //shader_esferas->setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
    //glUniform3f(glGetUniformLocation(p1_id, "pointLights[0].specular"), 1.0f, 1.0f, 1.0f);
    //shader_esferas->setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);

    // point light 2

    //lightingShader.setVec3("pointLights[1].position", pointLightPositions[1]);
    //glUniform3fv(glGetUniformLocation(p1_id, "pointLights[1].position"), 1, &pointLightPositions[1][0]);
    //lightingShader.setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
    //glUniform3f(glGetUniformLocation(p1_id, "pointLights[1].ambient"), 0.05f, 0.05f, 0.05f);
    //lightingShader.setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
    //glUniform3f(glGetUniformLocation(p1_id, "pointLights[1].diffuse"), 0.8f, 0.8f, 0.8f);
    //glUniform3f(glGetUniformLocation(p1_id, "pointLights[1].specular"), 1.0f, 1.0f, 1.0f);

    //view = glm::translate(view, glm::vec3(0.,0., -10.));

    //Mi implementacion
    view = glm::lookAt(glm::vec3(camX, camY, camZ), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

    GLboolean transpose = GL_FALSE;

    for (int i=0;i<ESFERAS;i++){
      objetos[i].draw(view,projection,transpose);
    }
    cout << "xd" << endl;
    //vaca->draw(view, projection);
    cout << "paso" << endl;

    // LUNA
    /*glm::mat4 matrix_model = glm::mat4(1.0f);
    matrix_model = glm::translate(matrix_model, glm::vec3(tras_x, 0, 0));
    matrix_model = glm::scale(matrix_model, glm::vec3(escala, escala, escala));
    matrix_model = glm::rotate(matrix_model, glm::radians(angulo_x), glm::vec3(1, 0, 0));

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, luna_texture);


    //glVertexAttribPointer(vertex_id, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), model.Vertices);
    glEnableVertexAttribArray(vertex_id);
    //glVertexAttribPointer(normal_id, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), model.Normales);
    glEnableVertexAttribArray(normal_id);

    glUniformMatrix4fv(matrix_model_id, 1, transpose, glm::value_ptr(matrix_model));
    glUniformMatrix4fv(matrix_view_id, 1, transpose, glm::value_ptr(view));
    glUniformMatrix4fv(matrix_projection_id, 1, transpose, glm::value_ptr(projection));

    ////glDrawArrays(GL_TRIANGLES, 0, model.cantVertices);
    //glDrawElements(GL_TRIANGLES, model.cantIndices * 3, GL_UNSIGNED_INT, (const void *) model.Indices);

    glBindVertexArray(luna_vao);
    glDrawElements(GL_TRIANGLES, NumIndices, GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(vertex_id);
    glDisableVertexAttribArray(normal_id);

    // TIERRA
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tierra_texture);

    //glVertexAttribPointer(vertex_id, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), model.Vertices);
    glEnableVertexAttribArray(vertex_id);
    //glVertexAttribPointer(normal_id, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), model.Normales);
    glEnableVertexAttribArray(normal_id);

    matrix_model = glm::mat4(1.0f);
    matrix_model = glm::translate(matrix_model, glm::vec3(10, 0, 0));
    matrix_model = glm::scale(matrix_model, glm::vec3(escala, escala, escala));
    matrix_model = glm::rotate(matrix_model, glm::radians(angulo_x), glm::vec3(1,0,0));

    glUniformMatrix4fv(matrix_model_id, 1, transpose, glm::value_ptr(matrix_model));
    glUniformMatrix4fv(matrix_view_id, 1, transpose, glm::value_ptr(view));
    glUniformMatrix4fv(matrix_projection_id, 1, transpose, glm::value_ptr(projection));

    ////glDrawArrays(GL_TRIANGLES, 0, model.cantVertices);
    //glDrawElements(GL_TRIANGLES, model.cantIndices * 3, GL_UNSIGNED_INT, (const void *) model.Indices);

    glBindVertexArray(tierra_vao);
    glDrawElements(GL_TRIANGLES, NumIndices, GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(vertex_id);
    glDisableVertexAttribArray(normal_id);
    */

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
        case '1':
          objeto_elegido = 0;
          cout << 1 << endl;
          break;
        case '2':
          objeto_elegido = 1;
          cout << 2 << endl;
          break;
        case '3':
          objeto_elegido = 2;
          cout << 3 << endl;
          break;
        case '4':
          objeto_elegido = 3;
          cout << 4 << endl;
          break;
        case '5':
          objeto_elegido = 4;
          cout << 5 << endl;
          break;

        case 'q': objetos[objeto_elegido].angulo_x++; break;
        case 'Q': objetos[objeto_elegido].angulo_x--; break;
        case 'w': objetos[objeto_elegido].angulo_y++; break;
        case 'W': objetos[objeto_elegido].angulo_y--; break;
        case 'e': objetos[objeto_elegido].angulo_z++; break;
        case 'E': objetos[objeto_elegido].angulo_z--; break;
        case 's': objetos[objeto_elegido].escala += 0.1; break;
        case 'S': objetos[objeto_elegido].escala -= 0.1; break;
        case 'x': objetos[objeto_elegido].tras_x += 0.1; break;
        case 'X': objetos[objeto_elegido].tras_x -= 0.1; break;
        case 'y': objetos[objeto_elegido].tras_y += 0.1; break;
        case 'Y': objetos[objeto_elegido].tras_y -= 0.1; break;
        case 'z': objetos[objeto_elegido].tras_z += 0.1; break;
        case 'Z': objetos[objeto_elegido].tras_z -= 0.1; break;
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
    model.Load(archivo);


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
