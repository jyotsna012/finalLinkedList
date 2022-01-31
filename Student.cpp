#include "Student.h"
#include <cstring>

Student::Student(char* nName){

  name = new char[20];
  strcpy(name,nName);

}


Student::~Student(){

  delete name;
  
}

char* Student::getName(){

  return name;

}
