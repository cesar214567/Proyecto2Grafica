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
    }
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
    coords.push_back({0.6f, 0.6f});
    coords.push_back({-1.f, -1.f});
    coords.push_back({-0.6f, 1.f});
    coords.push_back({0.4f, -1.f});

    for (auto temp:coords)
    {
      vertices.push_back(temp.first);
      vertices.push_back(temp.second);
      vertices.push_back(1.f);
    }
    indices.push_back({0, {11, 12}});
    indices.push_back({0, {1, 12}});
    indices.push_back({1, {3, 4}});
    indices.push_back({1, {2, 4}});
    indices.push_back({5, {6, 8}});
    indices.push_back({5, {6, 7}});
    indices.push_back({9, {12, 13}});
    indices.push_back({9, {10, 13}});
  }
  
  void l(){
    coords.push_back({-1.f, 1.f});
    coords.push_back({-0.6f, 1.f});
    coords.push_back({-1f, -1.f});
    coords.push_back({-0.6f, -0.6f});
    coords.push_back({0.4, -0.6f});
    coords.push_back({-0.6f, -1f});
    coords.push_back({0.4f, -1f});
    

    for (auto temp:coords)
    {
      vertices.push_back(temp.first);
      vertices.push_back(temp.second);
      vertices.push_back(1.f);
    }
    indices.push_back({0, {2, 5}});
    indices.push_back({0, {1, 5}});
    indices.push_back({3, {5, 6}});
    indices.push_back({3, {4, 6}});
      
    
  void I(){
    coords.push_back({-0.8.f, 1.f});
    coords.push_back({0.8f, 1.f});
    coords.push_back({-0.8f, -1.f});
    coords.push_back({0.8f, -0.6f});
    coords.push_back({-0.2, -0.6f});
    coords.push_back({0.2f, -1f});
    coords.push_back({-0.2f, -1f});
    coords.push_back({0.2f, 1.f});
    coords.push_back({-0,8f, -1.f});
    coords.push_back({0,8f, -0.6f});
    coords.push_back({-0,8, -0.6f});
    coords.push_back({0,8f, -1f});
    

    for (auto temp:coords)
    {
      vertices.push_back(temp.first);
      vertices.push_back(temp.second);
      vertices.push_back(1.f);
    }
    indices.push_back({0, {2, 3}});
    indices.push_back({0, {3, 1}});
    indices.push_back({4, {6, 7}});
    indices.push_back({4, {5, 7}});
    indices.push_back({8, {10, 11}});
    indices.push_back({8, {11, 9}});
      
      
  void Z(){
    coords.push_back({-0.8.f, 1.f});
    coords.push_back({0.8f, 1.f});
    coords.push_back({-0.8f, 0.6f});
    coords.push_back({0.8f, 0.6f});
    coords.push_back({0.2, 0.6f});
    coords.push_back({-0.8f, -0.6f});
    coords.push_back({-0.2f, -0.6f});
    coords.push_back({0.8f, -0.6f});
    coords.push_back({-0,8f, -1f});
    coords.push_back({0,8f, -1f});
    

    for (auto temp:coords)
    {
      vertices.push_back(temp.first);
      vertices.push_back(temp.second);
      vertices.push_back(1.f);
    }
    indices.push_back({0, {1, 2}});
    indices.push_back({1, {2, 3}});
    indices.push_back({4, {5, 3}});
    indices.push_back({3, {5, 6}});
    indices.push_back({5, {8, 9}});
    indices.push_back({5, {7, 9}});
        
        
  void C(){
    coords.push_back({-1.f, 1.f});
    coords.push_back({0.6f, 1.f});
    coords.push_back({-0.4f, 0.4f});
    coords.push_back({0.6f, 0.4f});
    coords.push_back({-0.4, -0.4f});
    coords.push_back({0.6f, -0.4f});
    coords.push_back({-0.1f, -1f});
    coords.push_back({0.6f, -1f});
    

    for (auto temp:coords)
    {
      vertices.push_back(temp.first);
      vertices.push_back(temp.second);
      vertices.push_back(1.f);
    }
    indices.push_back({0, {6, 9}});
    indices.push_back({0, {8, 4}});
    indices.push_back({8, {2, 1}});
    indices.push_back({2, {1, 3}});
    indices.push_back({4, {5, 4}});
    indices.push_back({5, {9, 7}});
    
    
  void U(){
    coords.push_back({-0.8.f, 1.f});
    coords.push_back({-0.4f, 1.f});
    coords.push_back({0.4f, 1f});
    coords.push_back({0.8f, 1f});
    coords.push_back({-0.8f, -0.4f});
    coords.push_back({-0.4f, -0.4f});
    coords.push_back({0.4f, -0.4f});
    coords.push_back({0.8f, -0.4f});
    coords.push_back({-0.8f, -1f});
    coords.push_back({0.8f, -1f});
    

    for (auto temp:coords)
    {
      vertices.push_back(temp.first);
      vertices.push_back(temp.second);
      vertices.push_back(1.f);
    }
    indices.push_back({0, {4, 5}});
    indices.push_back({0, {1, 5}});
    indices.push_back({2, {6, 7}});
    indices.push_back({2, {3, 7}});
    indices.push_back({4, {8, 9}});
    indices.push_back({4, {9, 7}});
    
    
  void M(){
    coords.push_back({-0.8.f, 1f});
    coords.push_back({0.8f, 1f});
    coords.push_back({-0.8f, 0.6f});
    coords.push_back({0.8f, 0.6f});
    coords.push_back({-0.4f, 0.6f});
    coords.push_back({-0.8f, -1f});
    coords.push_back({-0.4f, -1f});
    coords.push_back({-0.2f, 0.6f});
    coords.push_back({-0.2f, 0.6f});
    coords.push_back({-0.2f, -0.4f});
    coords.push_back({0.2f, -0.4f});
    coords.push_back({0.4f, 0.6f});
    coords.push_back({0.4f, -1f});
    coords.push_back({0.8f, -1f});
    

    for (auto temp:coords)
    {
      vertices.push_back(temp.first);
      vertices.push_back(temp.second);
      vertices.push_back(1.f);
    }
    indices.push_back({0, {2, 3}});
    indices.push_back({0, {1, 3}});
    indices.push_back({2, {5, 6}});
    indices.push_back({2, {4, 6}});
    indices.push_back({7, {9, 10});
    indices.push_back({7, {8, 10}});
    indices.push_back({11, {12, 13}});
    indices.push_back({11, {3, 13}});
                       
                       
  void P(){
    coords.push_back({-0.8.f, 1f});
    coords.push_back({-0.4f, 1f});
    coords.push_back({-0.8f, -1f});
    coords.push_back({-0.4f, -1f});
    coords.push_back({-0.4f, 0.6f});
    coords.push_back({0.6f, 1f});
    coords.push_back({0.6f, 0.6f});
    coords.push_back({-0.4f, 0.4f});
    coords.push_back({-0.4f, 0f});
    coords.push_back({0.6f, 0.4f});
    coords.push_back({0.6f, 0f});
    coords.push_back({0.2f, 0.6f});
    coords.push_back({0.2f, 0.4f});
    

    for (auto temp:coords)
    {
      vertices.push_back(temp.first);
      vertices.push_back(temp.second);
      vertices.push_back(1.f);
    }
    indices.push_back({0, {2, 3}});
    indices.push_back({0, {1, 3}});
    indices.push_back({1, {4, 6}});
    indices.push_back({1, {5, 6}});
    indices.push_back({7, {8, 10});
    indices.push_back({7, {9, 10}});
    indices.push_back({11, {12, 9}});
    indices.push_back({11, {6, 9}});
                       
                       
  void V(){
    coords.push_back({-0.8f, 0.8f});
    coords.push_back({-0.4f, 0.8f});
    coords.push_back({0.4f, 0.8f});
    coords.push_back({0.8f, 0.8f});
    coords.push_back({-0.2f, -1f});
    coords.push_back({0f, -0.4f});
    coords.push_back({0.2f, -1f});
    

    for (auto temp:coords)
    {
      vertices.push_back(temp.first);
      vertices.push_back(temp.second);
      vertices.push_back(1.f);
    }
    indices.push_back({0, {1, 4}});
    indices.push_back({1, {4, 5}});
    indices.push_back({4, {6, 5}});
    indices.push_back({2, {5, 6}});
    indices.push_back({2, {3, 6});
    
                       
  void A(){
    coords.push_back({-0.2f, 1f});
    coords.push_back({0.2f, 1f});
    coords.push_back({-0.8f, -1f});
    coords.push_back({-0.4f, -1f});
    coords.push_back({0.4f, -1f});
    coords.push_back({0.8f, -1f});
    coords.push_back({0f, 0.4f});
    coords.push_back({-0.4f, -0.2f});
    coords.push_back({-0.4f, -0.6f});
    coords.push_back({0.4f, -0.2f});
    coords.push_back({0.4f, -0.6f});

    
    for (auto temp:coords)
    {
      vertices.push_back(temp.first);
      vertices.push_back(temp.second);
      vertices.push_back(1.f);
    }
    indices.push_back({0, {2, 3}});
    indices.push_back({0, {3, 6}});
    indices.push_back({7, {8, 10}});
    indices.push_back({7, {9, 10}});
    indices.push_back({1, {6, 4});
    indices.push_back({1, {4, 5});
                       
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
