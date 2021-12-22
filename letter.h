#ifndef LETTER_H
#define LETTER_H

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
#define GLM_ENABLE_EXPERIMENTAL

#include <glm/gtx/string_cast.hpp>
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
  vector<int> indices2;
  string shader_filename;
  float tras_x, tras_y, tras_z;

  Letter(string _shader_filename, float _tras_x, float _tras_y, float _tras_z)
  {
    shader_filename = _shader_filename;
    tras_x = _tras_x;
    tras_y = _tras_y;
    tras_z = _tras_z;
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


    indices.push_back({0, {9, 10}});
    indices.push_back({0, {1, 10}});
    indices.push_back({1, {3, 4}});
    indices.push_back({1, {2, 4}});
    indices.push_back({5, {7, 8}});
    indices.push_back({5, {6, 8}});
  }

  void e(){
    coords.push_back({-1.f, 1.f});
    coords.push_back({-0.6f, 1.f});
    coords.push_back({0.4f, 1.f});
    coords.push_back({-0.6f, 0.6f});
    coords.push_back({0.4, 0.6f});
    coords.push_back({-0.6f, 0.2f});
    coords.push_back({0.4f, 0.2f});
    coords.push_back({-0.6f, -0.2f});
    coords.push_back({0.4f, -0.2f});
    coords.push_back({-0.6f, -0.6f});
    coords.push_back({0.4f, -0.6f});
    coords.push_back({-1.f, -1.f});
    coords.push_back({-0.6f, -1.f});
    coords.push_back({0.4f, -1.f});


    indices.push_back({0, {11, 12}});
    indices.push_back({0, {1, 12}});
    indices.push_back({1, {3, 4}});
    indices.push_back({1, {2, 4}});
    indices.push_back({5, {6, 8}});
    indices.push_back({5, {7, 8}});
    indices.push_back({9, {12, 13}});
    indices.push_back({9, {10, 13}});
  }

  void l(){
    coords.push_back({-1.f, 1.f});
    coords.push_back({-0.6f, 1.f});
    coords.push_back({-1.f, -1.f});
    coords.push_back({-0.6f, -0.6f});
    coords.push_back({0.4, -0.6f});
    coords.push_back({-0.6f, -1.f});
    coords.push_back({0.4f, -1.f});


    indices.push_back({0, {2, 5}});
    indices.push_back({0, {1, 5}});
    indices.push_back({3, {5, 6}});
    indices.push_back({3, {4, 6}});
  }

  void i(){
    coords.push_back({-0.8f, 1.f});
    coords.push_back({0.8f, 1.f});
    coords.push_back({-0.8f, 0.6f});
    coords.push_back({0.8f, 0.6f});
    coords.push_back({-0.2, 0.6f});
    coords.push_back({0.2f, 0.6f});
    coords.push_back({-0.2f, -0.6f});
    coords.push_back({0.2f, -0.6f});
    coords.push_back({-0.8f, -0.6f});
    coords.push_back({0.8f, -0.6f});
    coords.push_back({-0.8f, -1.f});
    coords.push_back({0.8f, -1.f});


    indices.push_back({0, {2, 3}});
    indices.push_back({0, {3, 1}});
    indices.push_back({4, {6, 7}});
    indices.push_back({4, {5, 7}});
    indices.push_back({8, {10, 11}});
    indices.push_back({8, {11, 9}});
  }

  void Z(){
    coords.push_back({-0.8f, 1.f});
    coords.push_back({0.8f, 1.f});
    coords.push_back({-0.8f, 0.6f});
    coords.push_back({0.8f, 0.6f});
    coords.push_back({0.2f, 0.6f});
    coords.push_back({-0.8f, -0.6f});
    coords.push_back({-0.2f, -0.6f});
    coords.push_back({0.8f, -0.6f});
    coords.push_back({-0.8f, -1.f});
    coords.push_back({0.8f, -1.f});


    indices.push_back({0, {1, 2}});
    indices.push_back({1, {2, 3}});
    indices.push_back({4, {5, 3}});
    indices.push_back({3, {5, 6}});
    indices.push_back({5, {8, 9}});
    indices.push_back({5, {7, 9}});
  }

  void C(){
    coords.push_back({-1.f, 1.f});
    coords.push_back({0.6f, 1.f});
    coords.push_back({-0.4f, 0.4f});
    coords.push_back({0.6f, 0.4f});
    coords.push_back({-0.4, -0.4f});
    coords.push_back({0.6f, -0.4f});
    coords.push_back({-1.f, -1.f});
    coords.push_back({0.6f, -1.f});
    coords.push_back({-0.4, 1.f});
    coords.push_back({-0.4, -1.f});

    indices.push_back({0, {6, 9}});
    indices.push_back({0, {8, 9}});
    indices.push_back({8, {2, 1}});
    indices.push_back({2, {1, 3}});
    indices.push_back({4, {5, 9}});
    indices.push_back({5, {9, 7}});

  }
  void U(){
    coords.push_back({-0.8f, 1.f});
    coords.push_back({-0.4f, 1.f});
    coords.push_back({0.4f, 1.f});
    coords.push_back({0.8f, 1.f});
    coords.push_back({-0.8f, -0.4f});
    coords.push_back({-0.4f, -0.4f});
    coords.push_back({0.4f, -0.4f});
    coords.push_back({0.8f, -0.4f});
    coords.push_back({-0.8f, -1.f});
    coords.push_back({0.8f, -1.f});



    indices.push_back({0, {4, 5}});
    indices.push_back({0, {1, 5}});
    indices.push_back({2, {6, 7}});
    indices.push_back({2, {3, 7}});
    indices.push_back({4, {8, 9}});
    indices.push_back({4, {9, 7}});
  }

  void M(){
    coords.push_back({-0.8f, 1.f});
    coords.push_back({0.8f, 1.f});
    coords.push_back({-0.8f, 0.6f});
    coords.push_back({0.8f, 0.6f});
    coords.push_back({-0.4f, 0.6f});
    coords.push_back({-0.8f, -1.f});
    coords.push_back({-0.4f, -1.f});
    coords.push_back({-0.2f, 0.6f});
    coords.push_back({0.2f, 0.6f});
    coords.push_back({-0.2f, -0.4f});
    coords.push_back({0.2f, -0.4f});
    coords.push_back({0.4f, 0.6f});
    coords.push_back({0.4f, -1.f});
    coords.push_back({0.8f, -1.f});


    indices.push_back({0, {2, 3}});
    indices.push_back({0, {1, 3}});
    indices.push_back({2, {5, 6}});
    indices.push_back({2, {4, 6}});
    indices.push_back({7, {9, 10}});
    indices.push_back({7, {8, 10}});
    indices.push_back({11, {12, 13}});
    indices.push_back({11, {3, 13}});
    }

  void P(){
    coords.push_back({-0.8f, 1.f});
    coords.push_back({-0.4f, 1.f});
    coords.push_back({-0.8f, -1.f});
    coords.push_back({-0.4f, -1.f});
    coords.push_back({-0.4f, 0.6f});
    coords.push_back({0.6f, 1.f});
    coords.push_back({0.6f, 0.6f});
    coords.push_back({-0.4f, 0.4f});
    coords.push_back({-0.4f, 0.f});
    coords.push_back({0.6f, 0.4f});
    coords.push_back({0.6f, 0.f});
    coords.push_back({0.2f, 0.6f});
    coords.push_back({0.2f, 0.4f});


    indices.push_back({0, {2, 3}});
    indices.push_back({0, {1, 3}});
    indices.push_back({1, {4, 6}});
    indices.push_back({1, {5, 6}});
    indices.push_back({7, {8, 10}});
    indices.push_back({7, {9, 10}});
    indices.push_back({11, {12, 9}});
    indices.push_back({11, {6, 9}});
  }

  void V(){
    coords.push_back({-0.8f, 0.8f});
    coords.push_back({-0.4f, 0.8f});
    coords.push_back({0.4f, 0.8f});
    coords.push_back({0.8f, 0.8f});
    coords.push_back({-0.2f, -1.f});
    coords.push_back({0.f, -0.4f});
    coords.push_back({0.2f, -1.f});

    indices.push_back({0, {1, 4}});
    indices.push_back({1, {4, 5}});
    indices.push_back({4, {6, 5}});
    indices.push_back({2, {5, 6}});
    indices.push_back({2, {3, 6}});
  }

  void A(){
    coords.push_back({-0.2f, 1.f});
    coords.push_back({0.2f, 1.f});
    coords.push_back({-0.8f, -1.f});
    coords.push_back({-0.4f, -1.f});
    coords.push_back({0.4f, -1.f});
    coords.push_back({0.8f, -1.f});
    coords.push_back({0.f, 0.4f});
    coords.push_back({-0.4f, -0.2f});
    coords.push_back({-0.4f, -0.6f});
    coords.push_back({0.4f, -0.2f});
    coords.push_back({0.4f, -0.6f});


    indices.push_back({0, {2, 3}});
    indices.push_back({0, {3, 6}});
    indices.push_back({7, {8, 10}});
    indices.push_back({7, {9, 10}});
    indices.push_back({1, {6, 4}});
    indices.push_back({1, {4, 5}});
    indices.push_back({0, {1, 6}});
  }

  void copy_vertices(){
    for (auto temp : coords)
    {
      vertices.push_back(temp.first);
      vertices.push_back(temp.second );
      vertices.push_back(1.f);
    }
  }
  void copy()
  {
    for (auto index : indices)
    {
      indices2.push_back(index.first);
      indices2.push_back(index.second.first);
      indices2.push_back(index.second.second);
    }
  }
  void setup()
  {
    copy_vertices();
    copy();
    coords.clear();
    indices.clear();
    for (auto it : vertices)
    {
      cout << it << " ";
    }
    cout<<endl;
    for (auto it: indices2){
      cout << it<< " ";
    }
    cout<<endl;
    cout << vertices.size() * sizeof(float) << endl;
    cout << indices2.size() * sizeof(float) << endl;
    shader = new Shader((shader_filename + ".vs").c_str(), (shader_filename + ".fs").c_str());

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices2.size() * sizeof(float), &indices2[0], GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
  }

  void print(){
    cout << "vertices: " << vertices.size() << endl;
    cout << "indices: " << indices2.size() << endl;

  }



  void draw(float escala, float angulo_x, float angulo_y, float angulo_z, glm::mat4 view, glm::mat4 projection)
  {
    glm::mat4 matrix_model = glm::mat4(1.0f);
    matrix_model = glm::translate(matrix_model, glm::vec3(tras_x, tras_y, tras_z));
    matrix_model = glm::scale(matrix_model, glm::vec3(escala, escala, escala));
    matrix_model = glm::rotate(matrix_model, glm::radians(angulo_x), glm::vec3(1, 0, 0));
    matrix_model = glm::rotate(matrix_model, glm::radians(angulo_y), glm::vec3(0, 1, 0));
    matrix_model = glm::rotate(matrix_model, glm::radians(angulo_z), glm::vec3(0, 0, 1));
    glm::vec4 temp(vertices[0], vertices[1],vertices[2],1.f);
    cout<< glm::to_string(projection * view * matrix_model * temp);
    // render container
    shader->use();
    shader->setVec3("color", glm::vec3(255.0f, 0.0f, 0.0f));
    shader->setMat4("matrix_model", matrix_model);
    shader->setMat4("matrix_view", view);
    shader->setMat4("matrix_projection", projection);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices2.size(), GL_UNSIGNED_INT, 0);

  }
};
#endif
