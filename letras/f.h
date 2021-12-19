#ifndef A_H
#define A_H

#include <iostream>
#include "../glew.h"
#include <GL/freeglut.h>
#include "../glut_ply.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../stb_image.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../shader.h"
using namespace std;
using duple = pair<float, float>;
using triplet = pair<float, duple>;
class Letter
{
public:
  Shader *shader;
  unsigned int VBO, VAO, EBO;
  vector<duple> coords;
  vector<float> vertices;
  vector<triplet> indices;
  unsigned int *indices, number_vertices,number_indices;
  Letter(Shader* _shader){
    shader =_shader;
  }

  void f(){
    coords.push_back({-1.f, 1.f});
    coords.push_back({-0.6f, 1.f});
    coords.push_back({0.4f, 1.f});
    coords.push_back({-0.6f, 0.6f});
    coords.push_back({0.4, 0.6f});
    coords.push_back({-0.6f, 0.2f});
    coords.push_back({0.f, 0.2f});
    coords.push_back({-0.6f, -0.2f});
    coords.push_back({0.f, -0.2f});
    coords.push_back({-1.f, -1.f});
    coords.push_back({-0.6f, -1.f});
    for (auto temp:coords)
    {
      vertices.push_back(temp.first);
      vertices.push_back(temp.second);
      vertices.push_back(1.f);
      vertices.push_back(1.f);
      vertices.push_back(0.f);
      vertices.push_back(0.f);
    }

    indices.push_back({0, {9, 10}});
    indices.push_back({0, {1, 10}});
    indices.push_back({1, {3, 4}});
    indices.push_back({1, {2, 4}});
    indices.push_back({5, {7, 8}});
    indices.push_back({5, {6, 8}});
  }

  void setup(){
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(float), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(float), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
  }

  void draw(){
    //A1

    // render container
    shader->use();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  }
};
#endif
