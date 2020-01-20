#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "student.h"

using namespace std;

/*
File: node header
*/

class Node {
 public://functions
  Node(Student* newstudent);
  ~Node();
  Student* getStudent();
  void setNext(Node* newnext);
  Node* getNext();
 private://vars
  Student* student;
  Node* next;
};
#endif
