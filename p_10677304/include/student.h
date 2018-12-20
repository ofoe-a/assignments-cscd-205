#include "course.h"
#include <vector>

bool checkStudent = true;
struct Student {   //structure of Student //
 char name[50];
 int id;
 Student *next;
 vector<string> course;
 vector<int> courseId;
 vector<int> grades;
}*studentHead,*lastptr;

void addStudent(){   //Adds record of student//
 Student *p;
 p=new Student;
 cout<<"Enter ID of student:"<<endl;
 cin>>p->id;
 fflush(stdin);
 cout<<"Enter name of student:"<<endl;
 cin>>p->name;
 fflush(stdin);
// getAllCourses();
 if(courseHead==NULL){
    cout<<"\nADD COURSES THEN ASSIGN IN MAIN MENU."<<endl;
 }else{
    getAllCourses();
    cout<<"Enter ID of Course to be Assigned: "<<endl;
    int idd;
    cin>>idd;
    Course *d;
    d=getCourse(idd);
    p->courseId.push_back(idd);
    p->course.push_back(d->title);
    p->grades.push_back(0);
 }
 p->next=NULL;
cout<<"Assign to more courses from Menu."<<endl;

 if(checkStudent){
  studentHead = p;
  lastptr = p;
  checkStudent = false;
 }else {
  lastptr->next=p;
  lastptr=p;
 }
 cout<<endl<<"Student Registered."<<endl;
}
void modifyStudent(){   //modifies record of student//{
 Student *ptr;
 Student *prev;
 Student *current;
 int id;
 cout<<"Enter ID to search:"<<endl;
 cin>>id;
 prev=studentHead;
 current=studentHead;
 while(current->id!=id){
  prev=current;
  current=current->next;
 }
 ptr=new Student;
 fflush(stdin);
 cout<<"Enter name of student:"<<endl;
 gets(ptr->name);
 fflush(stdin);
 cout<<"Enter ID of student:"<<endl;
 cin>>id;
 ptr->id=id;
 fflush(stdin);
 prev->next=ptr;
 ptr->next=current->next;
 current->next=NULL;
 delete current;
 cout<<endl<<"Recored Modified"<<endl;
}
void searchStudent(){  //searches record of student//
 Student *prev=NULL;
 Student *current=NULL;
 int id;
 cout<<"Enter ID to search:"<<endl;
 cin>>id;
 prev=studentHead;
 current=studentHead;
 while(current->id!=id){
  prev=current;
  current=current->next;
 }
 cout<<"\n\tName: ";
 cout<<current->name;
 cout<<"\n\tID: ";
 cout<<current->id;
 cout<<"\n\tCourse(s):";
 for(int i=0; i<current->course.size(); ++i){
    if(i==current->course.size()-1){
     cout << current->course[i]<<endl;
    }else{
    cout << current->course[i] << ", ";
    }
 }
}
Student *getStudent(int id){  //searches record of student//
 Student *prev=NULL;
 Student *current=NULL;
 prev=studentHead;
 current=studentHead;
 while(current->id!=id){
  prev=current;
  current=current->next;
 }
    return current;
}
void delStudent(){   //deletes record of a student//
 Student *ptr=NULL;
 Student *prev=NULL;
 Student *current=NULL;
 int id;
 cout<<"Enter ID to Delete:"<<endl;
 cin>>id;
 prev=studentHead;
 current=studentHead;
 while(current->id!=id){
  prev=current;
  current=current->next;
 }
 prev->next = current->next;
 current->next=NULL;
 delete current;
 cout<<endl<<"Record Deleted"<<endl;
}
void getAllStudents(){
    Student *prev=NULL;
    Student *current=NULL;
    prev=studentHead;
    current=studentHead;
    cout<<"\nStudents Registered\n";
    while(current->next!=NULL) {
        prev=current;
        puts(current->name);
        current=current->next;
    }
    puts(current->name);
}
void getAssignedCourses(int id){
    Student *current=getStudent(id);
    cout <<current->name<<" is assigned to the following courses:"<<endl;
    cout <<"ID\t\tCourse Name"<<endl;
    for(int i=0; i<current->course.size(); ++i){
        cout<<" "<<current->courseId[i];
        cout<<"\t\t"<<current->course[i]<<","<<endl;
    }
}
void getAcademicRecord(int id){
    try{
    Student *current=getStudent(id);
    cout <<current->name<<"'s Academic Record is printed below"<<endl;
    cout <<"Course Name\t\tGrade"<<endl;
        for(int i=0; i<current->course.size(); ++i){
            cout<<" "<<current->course[i];
            cout<<"\t\t\t"<<current->grades[i]<<","<<endl;
        }
    }catch(exception e){
        cout<<"Student With ID "<<id<<" Not Found"<<endl;
    }
}

