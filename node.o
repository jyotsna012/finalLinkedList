#include "node.h"
#include "student.h"

Node::Node(Student* s)
{
  student = s;
  next = nullptr;
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
