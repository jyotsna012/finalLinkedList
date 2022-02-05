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



