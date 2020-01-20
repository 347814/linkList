#include <iostream>
using namespace std;

class Student {
 public:
  Student(char*, char*, int, double);
  ~Student();
  char* getName();
  char* getlastname();
  double getGPA();
  int getId();


 private:
  char* name;
  char* lastname;
  double GPA;
  int id;






};
