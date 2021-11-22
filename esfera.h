#include <iostream>
#include "glew.h"
#include <GL/freeglut.h>
#include "glut_ply.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "stb_image.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;
Shader *shader_esferas = nullptr;

GLuint matrix_model_id, matrix_view_id, matrix_projection_id;
GLint p2_vertex_id = 0, p2_normal_id = 1;
GLuint p2_matrix_model_id, p2_matrix_view_id, p2_matrix_projection_id;
int slices = 100;
int stacks = 100;
int NumIndices = (slices * stacks + slices) * 6;


GLuint SolidSphere(float radius, int slices, int stacks)
{
  using namespace glm;
  using namespace std;
  const float pi = 3.1415926535897932384626433832795f;
  const float _2pi = 2.0f * pi;
  vector<vec3> positions;
  vector<vec3> normals;
  vector<vec2> textureCoords;
  for (int i = 0; i <= stacks; ++i)
  {
    // V texture coordinate.
    float V = i / (float)stacks;
    float phi = V * pi;
    for (int j = 0; j <= slices; ++j)
    {
      // U texture coordinate.
      float U = j / (float)slices;
      float theta = U * _2pi;
      float X = cos(theta) * sin(phi);
      float Y = cos(phi);
      float Z = sin(theta) * sin(phi);
      positions.push_back(vec3(X, Y, Z) * radius);
      normals.push_back(vec3(X, Y, Z));
      textureCoords.push_back(vec2(U, V));
    }
  }
  // Now generate the index buffer
  vector<GLuint> indicies;
  for (int i = 0; i < slices * stacks + slices; ++i)
  {
    indicies.push_back(i);
    indicies.push_back(i + slices + 1);
    indicies.push_back(i + slices);
    indicies.push_back(i + slices + 1);
    indicies.push_back(i);
    indicies.push_back(i + 1);
  }

  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  GLuint vbos[4];
  glGenBuffers(4, vbos);

  glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
  glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(vec3), positions.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(POSITION_ATTRIBUTE, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
  glEnableVertexAttribArray(POSITION_ATTRIBUTE);

  glBindBuffer(GL_ARRAY_BUFFER, vbos[1]);
  glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(vec3), normals.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(NORMAL_ATTRIBUTE, 3, GL_FLOAT, GL_TRUE, 0, (void *)0);
  glEnableVertexAttribArray(NORMAL_ATTRIBUTE);

  glBindBuffer(GL_ARRAY_BUFFER, vbos[2]);
  glBufferData(GL_ARRAY_BUFFER, textureCoords.size() * sizeof(vec2), textureCoords.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(TEXCOORD0_ATTRIBUTE, 2, GL_FLOAT, GL_FALSE, 0, (void *)0);
  glEnableVertexAttribArray(TEXCOORD0_ATTRIBUTE);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbos[3]);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size() * sizeof(GLuint), indicies.data(), GL_STATIC_DRAW);
  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  return vao;
}



class Esfera {
  public:
  float angulo_x,angulo_y,angulo_z;
  float tras_x, tras_y, tras_z;
  float escala;
  int num_Indices;//se asigna on the go
  float radius;
  unsigned int texture;
  GLint vao;
  string filename;

  void setTexture(string filename){
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
      glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
      std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
  }

  void setup(string filename){
    angulo_x = 0.;
    angulo_y = 0.;
    angulo_z = 0.;
    tras_x = float_random(10.0f);
    tras_y = float_random(5.0f);
    tras_z = float_random(10.0f);
    escala = float_random(1.0f);
    radius = float_random(1.5f) + 2;
    cout<<tras_x<<" "<<tras_y<<" "<<tras_z<<endl;
    vao = SolidSphere(radius, slices, stacks);
    setTexture(filename);
  }

  void draw(glm::mat4 view, glm::mat4 projection, GLboolean transpose)
  {
    glm::mat4 matrix_model = glm::mat4(1.0f);
    matrix_model = glm::translate(matrix_model, glm::vec3(tras_x, tras_y, tras_z));
    matrix_model = glm::scale(matrix_model, glm::vec3(escala, escala, escala));
    matrix_model = glm::rotate(matrix_model, glm::radians(angulo_x), glm::vec3(1, 0, 0));
    matrix_model = glm::rotate(matrix_model, glm::radians(angulo_y), glm::vec3(0, 1, 0));
    matrix_model = glm::rotate(matrix_model, glm::radians(angulo_z), glm::vec3(0, 0, 1));
    shader_esferas->use();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    //glVertexAttribPointer(vertex_id, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), model.Vertices);
    glEnableVertexAttribArray(vertex_id);
    //glVertexAttribPointer(normal_id, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), model.Normales);
    glEnableVertexAttribArray(normal_id);

    shader_esferas->setMat4("matrix_model", matrix_model);
    shader_esferas->setMat4("matrix_view", view);
    shader_esferas->setMat4("matrix_projection", projection);
    /*glUniformMatrix4fv(matrix_model_id, 1, transpose, glm::value_ptr(matrix_model));
    glUniformMatrix4fv(matrix_view_id, 1, transpose, glm::value_ptr(view));
    glUniformMatrix4fv(matrix_projection_id, 1, transpose, glm::value_ptr(projection));
    */
    ////glDrawArrays(GL_TRIANGLES, 0, model.cantVertices);
    //glDrawElements(GL_TRIANGLES, model.cantIndices * 3, GL_UNSIGNED_INT, (const void *) model.Indices);

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, NumIndices, GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(vertex_id);
    glDisableVertexAttribArray(normal_id);
  }
};
