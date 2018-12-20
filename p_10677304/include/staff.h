//#include "course.h"

bool checkStaff = true;
struct Staff {   //structure of Staff //
 string name;
 char discipline[50];
 int id;
 Staff *next;
 Course *courses;
}*staffHead,*last;

void addStaff() {   //Adds record of Staff//
 Staff *p;
 p=new Staff;
 cout<<"Enter name of Staff:"<<endl;
 cin>>p->name;
 fflush(stdin);
 cout<<"Enter ID of Staff:"<<endl;
 cin>>p->id;
 fflush(stdin);
 p->next=NULL;

 if(checkStaff) {
  staffHead = p;
  last = p;
  checkStaff = false;
 }
 else {
  last->next=p;
  last=p;
 }
 cout<<endl<<"Staff Record Added"<<endl;
}
void modifyStaff() {   //modifies record of Staff//
 Staff *ptr;
 Staff *prev;
 Staff *current;
 int id;
 cout<<"Enter ID to search:"<<endl;
 cin>>id;
 prev=staffHead;
 current=staffHead;
 while(current->id!=id) {
  prev=current;
  current=current->next;
 }
 ptr=new Staff;
 fflush(stdin);
 cout<<"Enter name of Staff:"<<endl;
 cin>>ptr->name;
 fflush(stdin);
 cout<<"Enter ID of Staff:"<<endl;
 cin>>ptr->id;
 fflush(stdin);
 prev->next=ptr;
 ptr->next=current->next;
 current->next=NULL;
 delete current;
 cout<<endl<<"Staff recored modified"<<endl;
}
void searchStaff() {  //searches record of Staff//
 Staff *prev=NULL;
 Staff *current=NULL;
 int id;
 cout<<"Enter ID to search:"<<endl;
 cin>>id;
 prev=staffHead;
 current=staffHead;
 while(current->id!=id)
 {
  prev=current;
  current=current->next;
    if(current->next==NULL){
        cout<<endl<<"Staff not found"<<endl;
        break;
    }
 }
 cout<<"\n\tName: ";
 cout<<current->name<<endl;
 cout<<"\n\tStaff ID:";
 cout<<current->id;
 cout<<"\n\tDiscipline:";
 cout<<current->discipline<<endl;
}
void delStaff() {   //deletes record of a Staff//
 Staff *ptr=NULL;
 Staff *prev=NULL;
 Staff *current=NULL;
 int id;
 cout<<"Enter ID of Staff to Delete:"<<endl;
 cin>>id;
 prev=staffHead;
 current=staffHead;
 while(current->id!=id)
 {
 prev=current;
 current=current->next;
 if(prev->next==NULL){
    cout<<endl<<"Staff not found"<<endl;
 }
}
 prev->next = current->next;
 current->next=NULL;
 delete current;
 cout<<endl<<"Staff Record Deleted"<<endl;
}

void getAllStaff(){
    Staff *prev=NULL;
    Staff *current=NULL;
    prev=staffHead;
    current=staffHead;
    cout<<"\nStudents Registered\n";
    while(current->next!=NULL) {
        prev=current;
        cout<<current->name<<endl;
        current=current->next;
    }
    cout<<current->name<<endl;
}
