#include <iostream>
#include <cstring>
#include <iomanip>
#include "node.h"
#include "Student.h"

using namespace std;

void PRINT(Node* next);
int COUNT(Node* head);

int main(){
	
  Student* s = new Student;
  Node* head = new Node(s);
 
  Student* j = new Student;
  Node* next = new Node(j);
	
  Student* k = new Student;
  Node* next2 = new Node(k);

  head -> setNext(next);
  next -> setNext(next2);
  next2 -> setNext(NULL);

  char name [20];
  strcpy(name,"josie");
  char name2 [20];
  strcpy(name2,"tera");
  head->getStudent()->setFName(name);
  head->getStudent()->setLName(name2);
  head->getStudent()->setID(1);
  head->getStudent()->setGPA(3.984);

  strcpy(name,"josie2");
  strcpy(name2,"tera2");
  next->getStudent()->setFName(name);
  next->getStudent()->setLName(name2);
  next->getStudent()->setID(2);
  next->getStudent()->setGPA(4.985);
	
  strcpy(name,"josie3");
  strcpy(name2,"tera3");
  next2->getStudent()->setFName(name);
  next2->getStudent()->setLName(name2);
  next2->getStudent()->setID(3);
  next2->getStudent()->setGPA(5.985);
	
  PRINT(head);
  cout << COUNT(head) << endl;

}


void PRINT(Node* nextt) {

    if (nextt != NULL) {
        cout << "First Name: " << nextt->getStudent()->getFName() << endl;
        cout << "Last Name: " << nextt->getStudent()->getLName() << endl;
	cout << " ID: " << nextt->getStudent()->getID() << endl;
        cout << " GPA: " << setprecision(2) << nextt->getStudent()->getGPA() << endl;
        PRINT(nextt->getNext());
    }
}

int COUNT(Node* head){
    int count = 0;
    while(head != NULL){
	count = count + 1;
    	head = head -> getNext();
    }	
    return count;
}




