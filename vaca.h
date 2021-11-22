#ifndef VACA_H
#define VACA_H

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
#include "shader.h"

using namespace std;

class Vaca
{
public:
  Shader *shader;
  GLuint vbo, vao, ebo;
  Model_PLY model;
  float angulo_x, angulo_y, angulo_z;
  float tras_x, tras_y, tras_z;
  float escala;
  Vaca(string shader_filename)
  {
    angulo_x = 0.;
    angulo_y = 0.;
    angulo_z = 0.;
    tras_x = float_random(10.0f);
    tras_y = float_random(5.0f);
    tras_z = float_random(10.0f);
    escala = float_random(1.0f);
    shader = new Shader((shader_filename + ".vs").c_str(), (shader_filename + ".fs").c_str());
    shader->use();
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    GLuint vbos[3];
    glGenBuffers(3, vbos);
    glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
    glBufferData(GL_ARRAY_BUFFER, model.cantVertices * sizeof(float) * 3, model.Vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(POSITION_ATTRIBUTE, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
    glEnableVertexAttribArray(POSITION_ATTRIBUTE);

    glBindBuffer(GL_ARRAY_BUFFER, vbos[1]);
    glBufferData(GL_ARRAY_BUFFER, model.cantVertices * sizeof(float) * 3, model.Normales, GL_STATIC_DRAW);
    glVertexAttribPointer(NORMAL_ATTRIBUTE, 3, GL_FLOAT, GL_TRUE, 0, (void *)0);
    glEnableVertexAttribArray(NORMAL_ATTRIBUTE);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbos[3]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.cantIndices * sizeof(GLuint) * 3, model.Indices, GL_STATIC_DRAW);
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  }
  void draw(glm::mat4 view, glm::mat4 projection)
  {
    shader->use();
    shader->bindAttributeLocation(p2_vertex_id, "aPos");
    shader->bindAttributeLocation(p2_normal_id, "aNormal");

    glEnableVertexAttribArray(p2_vertex_id);
    glEnableVertexAttribArray(p2_normal_id);


    glm::mat4 matrix_model = glm::mat4(1.0f);
    matrix_model = glm::translate(matrix_model, glm::vec3(tras_x, tras_y, tras_z));
    matrix_model = glm::scale(matrix_model, glm::vec3(escala, escala, escala ));
    matrix_model = glm::rotate(matrix_model, glm::radians(angulo_x), glm::vec3(1, 0, 0));
    matrix_model = glm::rotate(matrix_model, glm::radians(angulo_y), glm::vec3(0, 1, 0));
    matrix_model = glm::rotate(matrix_model, glm::radians(angulo_z), glm::vec3(0, 0, 1));

    shader->setMat4("matrix_model", matrix_model);
    shader->setMat4("matrix_view", view);
    shader->setMat4("matrix_projection", projection);
    //glBindVertexArray(vao);

    //glVertexAttribPointer(p2_vertex_id, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), model.Vertices);
    //glVertexAttribPointer(p2_normal_id, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), model.Normales);
    cout<<model.cantIndices<<endl;
    //glDrawElements(GL_TRIANGLES, model.cantIndices * 3, GL_UNSIGNED_INT, (const void *)model.Indices);
    cout << "hola" << endl;
    glDrawElements(GL_TRIANGLES, model.cantIndices * 3, GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(p2_vertex_id);
    glDisableVertexAttribArray(p2_normal_id);
  }
};

#endif
