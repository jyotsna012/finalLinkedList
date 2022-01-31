#include <iostream>
#include <cstring>
#include <cmath>
#include "node.h"
#include "Student.h"

using namespace std;

Node* head = NULL;
Node* prev = NULL;

int deleteID;
float sum = 0;
int num = 0;

void addStudent();

int main(){


}

void addStudent(){
  //set up the student with all of the data fields
  Student* s = new Student();
  cout << "Please enter the first name" << endl;
  char fname[20];
  cin.get(fname,20);
  cin.get();
  s->setFName(fname);
  cout << "Please enter the student's last name" << endl;
  char lname[20];
  cin.get(lname,20);
  cin.get();
  s->setLName(lname);
  cout << "Please enter the students id number" << endl;
  int sID;
  cin >> sID;
  cin.get();
  s->setID(sID);
  cout << "Please enter the student's GPA" << endl;
  float sgpa;
  cin >>  sgpa;
  cin.get();
  s->setGPA(sgpa);
  
  Node* n = new Node(s);
  Node* temp = new Node();
  temp = head;
  int key = n -> getID();
  
  while(temp -> getNext() != NULL && temp -> getNext() -> getID() < key){
    temp = temp -> getNext();
  }
  
  n -> next = temp -> getNext();
  temp -> getNext() = n;
  
}

