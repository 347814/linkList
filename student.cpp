#include<iostream>
#include "student.h"
using namespace std;
Student :: Student(char* newName, char* lastName, int newid, double newGPA){
  name = new char[90];
 lastname = new char[90];
 name = newName;
 lastname = lastName;
 id = newid;
 GPA = newGPA;
 




}
char* Student:: getName(){
  return name;

}
char* Student:: getlastname(){
  return lastname;

}
double Student:: getGPA(){
  return GPA;

}
int Student::getId(){
  return id;
}
Student::~Student(){
  delete (name);
  delete (lastname);

}

