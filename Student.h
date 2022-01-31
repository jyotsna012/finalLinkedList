/*
 *Student Class File.
 */

#pragma once

class Student{

 public:
  Student();
 
  char* firstName;
  void setFName(char*);
  char* getFName();
 
  char* lastName;
  void setLName(char*);
  char* getLName();
 
  float GPA;
  void setGPA(float);
  float getGPA();
 
  int studentId;
  void setID(int);
  int getID();
 
  ~Student();
};
