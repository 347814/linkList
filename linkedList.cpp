//DHRUVA SOGAL STARTED 12/19/2019
#include<iostream>
#include<iomanip>
#include"node.h" //includes student
#include<string.h>
using namespace std;
void add(Student* newstudent, Node* &head, Node* current);
void deleteStudent(Node* head, Node* current, int key);
void printStudents(Node* head, Node* current);
void averageGPA(Node* head, Node* current, double total, double count);
int main(){
  bool running  = true;
  int key = 0;
  int total =0;
  int count = 0;
  Node* head = NULL;
  Node* p = NULL;
  while(running == true){
  cout<<"ADD for add, PRINT for print, DELETE for delete, AVERAGE for average GPA, or QUIT to quit"<<endl;
  char* command = new char[90];
  cin.getline(command,90);

  if(strcmp(command, "ADD") == 0){
    char* readName = new char[90];
    char* readLastName = new char[90];
    char* studentname = new char[90];
    char* lastName = new char[90];
    int studentid;
    double studentGPA;
    cout<<"Enter Student First Name"<<endl;
    cin.getline(readName, 90);
    cout<<"Enter Last Name"<<endl;
    cin.getline(readLastName, 90);
    cout<<"Enter ID"<<endl;
    cin>>studentid;
    cout<<"Enter GPA"<<endl;
    cin>>studentGPA;
    strcpy(studentname, readName);
    strcpy(lastName, readLastName);
    Student* newStudent = new Student(studentname, lastName, studentid, studentGPA);
    cout<<newStudent->getlastname()<<endl;
    add(newStudent, head, head);

  }

  else if(strcmp(command, "DELETE")==0){
   int key;
   cout<<"Enter ID of the student you wish to delete"<<endl;
   cin>>key;
   deleteStudent(head, head, key);


  }
  else if(strcmp(command, "PRINT") == 0){
    printStudents(head, head);

  }
  else if(strcmp(command, "AVERAGE") == 0){
    averageGPA(head, head, total, count);
  }
  else if(strcmp(command, "QUIT") == 0){
    running = false;
  }


  }
}






void add (Student* newstudent, Node* &head, Node* current){
  if(current == NULL){ //if empty student list
    head = new Node(newstudent);
    cout<<"First Student Added"<<endl;
  } //end if current == NULL

  else{ //not first in list
    if(head->getNext() == NULL){ //if second thing in list
      if(current->getStudent()->getId() < newstudent->getId()){
	current->setNext(new Node(newstudent));
      }//close if current id < newstudnet11 id

    else if(current->getStudent()->getId() > newstudent->getId()){
      head = new Node(newstudent);
      head->setNext(current);

    }//close else if current id > newstudent id


  }//close if head->getNext() == NULL

  //seg fault section
  else{ //head next !== NULL
     if(current->getStudent()->getId() > newstudent->getId()){
	head = new Node(newstudent);
	head->setNext(current);
	cout<<"student added"<<endl;

     } //end if current > new id


     else if(current->getNext() == NULL){
       current->setNext(new Node(newstudent)); //defrencing NULL pointer causing seg fault?
       cout<<"added on end of list"<<endl;
     }//end if next == NULL



     //this is bug-free
     else if(newstudent->getId() > current->getStudent()->getId() && newstudent->getId() < current->getNext()->getStudent()->getId()){
       Node* temp = new Node(newstudent);
       temp->setNext(current->getNext());
       current->setNext(temp);
       cout<<"added in between"<<endl;
       }//end if in between




     else{
       add(newstudent, head, current->getNext());
       cout<<"add recursively called"<<endl;

     }


  }//end else head next !== NULL










  }//end if current not equal to NULL



}
void deleteStudent(Node* head, Node* current, int key){ //call with head as both head and current and p as current next
  if(head == NULL){
    cout<<"Empty Student List"<<endl;

  }
  else if(head->getStudent()->getId()==key){
    head = head->getNext();
    delete current;
    delete current->getStudent();


  }
  else if(current->getNext()->getStudent()->getId() == key && current->getNext() == NULL){
    current->setNext(NULL);
    delete current->getNext();

  }
  else if(current->getNext()->getStudent()->getId() == key){
    //current set next get next next delete next
    current->setNext(current->getNext()->getNext());
    delete current->getNext();
  }
  else{
    deleteStudent(head, current->getNext(), key);


  //}


}
}
void printStudents(Node* head, Node* current){ //call with head as both parameters
  if(current == NULL){
    cout<<"No students in list"<<endl;
  }
  else{


      cout<<current->getStudent()->getName();
      cout<<" ";
      cout<<current->getStudent()->getlastname();
      cout<<",";
      cout<<current->getStudent()->getId();
      cout<<",";
      cout<<fixed<<setprecision(2)<<current->getStudent()->getGPA()<<endl;

    if(!(current->getNext()==NULL)){
      printStudents(head, current->getNext());
    }

  }





}
void averageGPA(Node* head, Node* current, double total, double count){
  if(current == NULL){
    cout<<"No students in list"<<endl;

}
  else{
    total += current->getStudent()->getGPA();
    count++;

  if(!(current->getNext()==NULL)){
    averageGPA(head, current->getNext(), total, count);

  }
     else{
       double averageGPA = total/count;
       cout<<"Average GPA is:"<<endl;
       cout<<fixed<<setprecision(2)<<averageGPA<<endl;

     }
  }
}
