/*
 *Student Class File.
 */

#pragma once

class Student{
 public:
  Student(char*);
  char* getName();
  ~Student();
 private:
  char* name; // name of student
};
