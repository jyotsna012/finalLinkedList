#include "Student.h"
#include <cstring>

Student::Student(){

}

void Student::setFName(char* nName){
  firstName = new char[20];
  strcpy(firstName,nName);
}

void Student::setLName(char* nName){
  lastName = new char[20];
  strcpy(lastName,nName);
}

void Student::setID(int nID){
  studentId = nID;
}

void Student::setGPA(float newGPA){
  GPA = newGPA;
}

char* Student::getFName(){
  return firstName;
}

char* Student::getLName(){
  return lastName;
}

int Student::getID(){
  return studentId;
}

float Student::getGPA(){
  return GPA;
}

Student::~Student(){

  delete firstName;
  delete lastName;
  
}
