#include "node.h"
#include "Student.h"
#include <iostream>

Node::Node(Student* s)
{
  student = s;
  next = NULL;
}

Node::~Node()
{
  delete student;
}

Node* Node::getNext()
{
  return next;
}
Student* Node::getStudent()
{
  return student;
}

void Node::setNext(Node* n)
{
  next = n;
}
