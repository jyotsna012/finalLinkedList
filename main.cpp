#include <iostream>
#include <cstring>
#include <iomanip>
#include "node.h"
#include "Student.h"

using namespace std;

void ADD(Node*& head, Node* prev, Student* student);
void PRINT(Node* next);
void AVERAGE(Node* head, float currentSum, int nodeCount);
void DELETE(Node*& head, Node* current, Node* prev, int ID);

int main(){
  
  Node* head = NULL;
  Node* next = NULL;
  Node* next2 = NULL;

  head -> setNext(next);
  next -> setNext(next2);
  next2 -> setNext(NULL);
	
  head->getStudent()->setFName("Josie");
  head->getStudent()->setLName("Tera");
  head->getStudent()->setID("405456");
  head->getStudent()->setGPA("4.987");

  next->getStudent()->setFName("Josie1");
  next->getStudent()->setLName("Tera1");
  next->getStudent()->setID("4054561");
  next->getStudent()->setGPA("4.9871");
	
  next2->getStudent()->setFName("Josie12");
  next2->getStudent()->setLName("Tera12");
  next2->getStudent()->setID("40545612");
  next2->getStudent()->setGPA("4.98712");
	
  PRINT(head);

}


void PRINT(Node* next) {
    if (next != NULL) {
        next->getStudent();
        cout << "First Name: " << next->getStudent()->getFName() << endl;
        cout << "Last Name: " << next->getStudent()->getLName() << endl;
	cout << " ID: " << next->getStudent()->getID() << endl;
        cout << " GPA: " << setprecision(2) << next->getStudent()->getGPA() << endl;
        PRINT(next->getNext()); 
    }
}



