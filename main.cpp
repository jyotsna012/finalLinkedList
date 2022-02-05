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
        next->getStudent()
        cout << "First Name: " << getFName() << endl;
        cout << "Last Name: " << getLName() << endl;
	      cout << " ID: " << getID() << endl;
        cout << " GPA: " << setprecision(2) << getGPA() << endl;
        PRINT(next->getNext()); 
    }
}



