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
 
  double GPA;
  void setGPA(double);
  double getGPA();
 
  int studentId;
  void setID(int);
  int getID();
 
  ~Student();
};
