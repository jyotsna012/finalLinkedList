
/*
 *File for node class. Contains a pointer to a student and a node. Contains functions 
 *to access student and node
 *Max Shi
 */

#include "student.h"
class Node
{
  public:
    Node(Student* s);
    ~Node();
    Node* getNext();
    Student* getStudent();
    void setNext(Node* n);
  private:
    Student* student; //pointer to student
    Node* next; //pointer to next node
};
