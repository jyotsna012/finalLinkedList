//Jyotsna Tera
//Creating a database to add students using linked lists
//Feb 6th 2021

#include <iostream>
#include <cstring>
#include <iomanip>
#include "node.h"
#include "Student.h"

using namespace std;

//function prototypes
void PRINT(Node* next);
int COUNT(Node* head);
void AVERAGE(Node* head, int nCount, double sum); 
void DELETE(Node* &head, Node* c, Node* p, int ID);
void ADD(char *firstN, char *lastN, int IID, float GP, Node* &head);
void SORT(Node* &tS, Node* &cN, Node* &head, Node* &previous);


int main(){
//will keep running until user quits
while(true){
    int input;
    cout << "Type 1 for add, 2 for print, 3 for delete, 4 for average, or 5 for quit" << endl;
    cin >> input;
    cin.get();
     //asks user for details of student 
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
    //prints linked list	
    if(input == 2){
	PRINT(head);
    }
    //deletes an item based on ID	
    if(input == 3){
	int IIDD;
	cout << "enter the id of student to delete" << endl;
	cin >> IIDD;
	DELETE(head, head, NULL, IIDD);

    }
    //displays the average of linked list	
    if(input == 4){
	int numNodes = COUNT(head);
	AVERAGE(head, numNodes, 0); 
    }
    //exits function
    if(input == 5){
      break;
    }
  }
  return 0;  	
	
}
//function to add
void ADD(char *firstN, char *lastN, int IID, float GP, Node* &head){

  //creates new student based on info
  Student* s = new Student();
  s->setFName(firstN);
  s->setLName(lastN);
  s->setID(IID);
  s->setGPA(GP);
  //asigns student to new node
  Node* n = new Node(s);

  //if no items then student will be first item in list
  if(head==NULL){
    head = n;
    return;

  }
  Node* previous = NULL;
  //calls the sort function
  SORT(n, head, head, previous);  
}

void SORT(Node* &tS, Node* &cN, Node* &head, Node* &previous){
  	
  //if node to sort id smaller than head it iwll become the head	
  if(tS->getStudent()->getID() < cN->getStudent()->getID() && head==cN){
      tS->setNext(cN);
      head = tS;
      return;
  }
  
  //while traversing the list, when the place for the node occurs, the node will be placed
  if(tS->getStudent()->getID() < cN->getStudent()->getID() && head != cN){
    previous->setNext(tS);
    tS->setNext(cN);
    return;
  }

 //if at the end the node does not find right place, it is put to the end at the list
 if(cN->getNext()==NULL){
	cN->setNext(tS); 
	return;
   }

//when list is still remaining and nothing has matched, it will move to the next node in the list
  else{
    previous = cN;
    Node* nextNode = cN->getNext();
    //calls the function untill a condition above is met
    SORT(tS,nextNode, head, previous);
}
}


void PRINT(Node* nextt) {
//if node is not null it will print contents
    if (nextt != NULL) {
        cout << "First Name: " << nextt->getStudent()->getFName() << endl;
        cout << "Last Name: " << nextt->getStudent()->getLName() << endl;
	cout << " ID: " << nextt->getStudent()->getID() << endl;
        cout << " GPA: " << nextt->getStudent()->getGPA() << endl;
	//function is called again with the next node
        PRINT(nextt->getNext());
    }
}

//function to count how many studnets in list and return the number
int COUNT(Node* head){
    int count = 0;
    while(head != NULL){
	count = count + 1;
    	head = head -> getNext();
    }	
    return count;
}

//finds average
void AVERAGE(Node* head, int nCount, double sum) {
	//as long a head is not equal to null
	if (head != NULL) {
	 //the gpa is added to the total sum
	double temp = head -> getStudent() -> getGPA();
        sum = sum + temp;
	//this gets repeated with the next node
        AVERAGE(head->getNext(), nCount, sum);
        //cout << "sum: " << sum << endl;
    }
    //when head is null, recursion stops and value is printed.
    else {
        cout << "avg: " << (double)(sum/nCount) << endl;
    }
}

//function to delete
void DELETE(Node* &head, Node* c, Node* p, int ID) {
    //checks to see list is not empty
    if (head == NULL) {
        return;
    }
    
    //if it is at end of list and no matching id, it informs user that no students with matching id is present. 
    if(c->getNext() == NULL && c->getStudent()->getID() != ID){
	    
	    cout<<"sorry, no student with matching id" << endl;
	    
    }
	
    //if id matches the first student, the head becomes secind students
    if (c->getStudent()->getID() == ID && p == NULL) {
            head = c->getNext();
	    return; 
	 //when id matches a student, it is deleted from list
    }else if(c->getStudent()->getID() == ID) {
	    Node* temp = c->getNext();
            p->setNext(temp);
       	    delete c;
            return;
    }
	//as long as the next node is not null, the function will repeat with the next node
    if (c->getNext() != NULL) {
        DELETE(head, c->getNext(), c, ID);
    }
}



