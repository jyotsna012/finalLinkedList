#include <iostream>
#include <cstring>
#include <iomanip>
#include "node.h"
#include "Student.h"

using namespace std;

void PRINT(Node* next);
int COUNT(Node* head);
void AVERAGE(Node* head, int nCount, double sum); 
void DELETE(Node* &head, Node* c, Node* p, int ID);
void ADD(char *firstN, char *lastN, int IID, float GP, Node* &head);
void SORT(Node* &tS, Node* &cN, Node* &head);


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
  head->getStudent()->setID(4);
  head->getStudent()->setGPA(3.984);

  strcpy(name,"josie2");
  strcpy(name2,"tera2");
  next->getStudent()->setFName(name);
  next->getStudent()->setLName(name2);
  next->getStudent()->setID(7);
  next->getStudent()->setGPA(4.985);
	
  strcpy(name,"josie3");
  strcpy(name2,"tera3");
  next2->getStudent()->setFName(name);
  next2->getStudent()->setLName(name2);
  next2->getStudent()->setID(10);
  next2->getStudent()->setGPA(5.985);
	
while(true){
    int input;
    cout << "Type 1 for add, 2 for print, 3 for delete, 4 for average, or 5 for quit" << endl;
    cin >> input;
    cin.get();
	
    if(input == 1){
		cout << "Please enter the student's first name" << endl;
  		char fN[20];
  		cin.get(fN,20);
  		cin.get();
		cout << "Please enter the student's last name" << endl;
  		char lN[20];
  		cin.get(lN,20);
  		cin.get();
		cout << "Please enter the students id number" << endl;
  		int sI;
  		cin >> sI;
  		cin.get();
		cout << "Please enter the student's GPA" << endl;
  		float G;
 		cin >> G;
	  	cin.get();
		ADD(fN, lN, sI, G, head);
    }
    if(input == 2){
	PRINT(head);
    }
    if(input == 3){
	int IIDD;
	cout << "enter the id of student to delete" << endl;
	cin >> IIDD;
	DELETE(head, head, NULL, IIDD);

    }
    if(input == 4){
	int numNodes = COUNT(head);
	AVERAGE(head, numNodes, 0); 
    }
    if(input == 5){
      break;
    }
  }
  return 0;  	
	
}

void ADD(char *firstN, char *lastN, int IID, float GP, Node* &head){

  Student* s = new Student();
  s->setFName(firstN);
  s->setLName(lastN);
  s->setID(IID);
  s->setGPA(GP);
  Node* n = new Node(s);
	
  if(head==NULL){
    head = n;
    return;

  }
  SORT(n, head, head);  
}

void SORT(Node* &tS, Node* &cN, Node* &head){
	
  cout<<"its working aa"<<endl;
  Node* previous = NULL;

  if(tS->getStudent()->getID() < cN->getStudent()->getID() && head==cN){
      tS->setNext(cN);
      head = tS;
      return;
  }
  
  if(tS->getStudent()->getID() < cN->getStudent()->getID() && head != cN){
    previous->setNext(tS);
    tS->setNext(cN);
    return;
  }

 if(cN->getNext()==NULL){
	cN->setNext(tS); 
	return;
   }
	
  else{
    previous = cN;
    Node* nextNode = cN->getNext();
    SORT(tS,nextNode, head);
}
}


void PRINT(Node* nextt) {

    if (nextt != NULL) {
        cout << "First Name: " << nextt->getStudent()->getFName() << endl;
        cout << "Last Name: " << nextt->getStudent()->getLName() << endl;
	cout << " ID: " << nextt->getStudent()->getID() << endl;
        cout << " GPA: " << nextt->getStudent()->getGPA() << endl;
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

void AVERAGE(Node* head, int nCount, double sum) {
	if (head != NULL) {
	double temp = head -> getStudent() -> getGPA();
        sum = sum + temp;
        AVERAGE(head->getNext(), nCount, sum);
        //cout << "sum: " << sum << endl;
    }
    else {
        cout << "avg: " << (double)(sum/nCount) << endl;
    }
}

void DELETE(Node* &head, Node* c, Node* p, int ID) {
    if (head == NULL) {
        return;
    }
 
    if(c->getNext() == NULL && c->getStudent()->getID() != ID){
	    
	    cout<<"sorry, no student with matching id" << endl;
	    
    }
	
    if (c->getStudent()->getID() == ID && p == NULL) {
            head = c->getNext();
	    return;
    }else if(c->getStudent()->getID() == ID) {
	    Node* temp = c->getNext();
            p->setNext(temp);
       	    delete c;
            return;
    }
    if (c->getNext() != NULL) {
        DELETE(head, c->getNext(), c, ID);
    }
}



