using namespace std;

bool checkCourse = true;
struct Course {   //structure of Course //
 string title;
 int id;
 Course *next;
}*courseHead,*lastCourse;

void addCourse() {   //Adds record of Course//
 Course *p;
 p=new Course;
 cout<<"Enter ID of Course:"<<endl;
 cin>>p->id;
 fflush(stdin);
 cout<<"Enter title of Course:"<<endl;
 cin>>p->title;
 fflush(stdin);
 p->next=NULL;

 if(checkCourse) {
  courseHead = p;
  lastCourse = p;
  checkCourse = false;
 } else {
  lastCourse->next=p;
  lastCourse=p;
 }
 cout<<endl<<"Recored Entered"<<endl;
}

void modifyCourse() {   //modifies record of Course//{
 Course *ptr;
 Course *prev;
 Course *current;
 int id;
 cout<<"Enter ID to search:"<<endl;
 cin>>id;
 prev=courseHead;
 current=courseHead;
 while(current->id!=id){
  prev=current;
  current=current->next;
 }
 ptr=new Course;
 fflush(stdin);
 cout<<"Enter title of Course:"<<endl;
 cin>>ptr->title;
 fflush(stdin);
 cout<<"Enter ID of Course:"<<endl;
 cin>>id;
 ptr->id=id;
 fflush(stdin);
 prev->next=ptr;
 ptr->next=current->next;
 delete current;
 cout<<endl<<"Recored Modified"<<endl;
}
void searchCourse() {  //searches record of Course//
 Course *prev=NULL;
 Course *current=NULL;
 int id;
 cout<<"Enter ID to search:"<<endl;
 cin>>id;
 prev=courseHead;
 current=courseHead;
 while(current->id!=id)
 {
  prev=current;
  current=current->next;
 }
 cout<<"\nTitle: ";
 cout<<current->title<<endl;
 cout<<"\nID:";
 cout<<current->id;
}
Course *getCourse(int id) {  //searches record of student//
 Course *prev=NULL;
 Course *current=NULL;
 prev=courseHead;
 current=courseHead;
 while(current->id!=id){
  prev=current;
  current=current->next;
 }
 return current;
}
void delCourse() {   //deletes record of a Course//
 Course *ptr=NULL;
 Course *prev=NULL;
 Course *current=NULL;
 int id;
 cout<<"Enter ID to Delete:"<<endl;
 cin>>id;
 prev=courseHead;
 current=courseHead;
 while(current->id!=id)
 {
  prev=current;
  current=current->next;
 }
 prev->next = current->next;
 current->next=NULL;
 delete current;
 cout<<endl<<"Record Deleted"<<endl;
}

void getAllCourses(){
    Course *prev=NULL;
    Course *current=NULL;
    prev=courseHead;
    current=courseHead;
    cout<<"\nCourses available\n";
    cout<<"ID\t\t Title\n";
    while(current->next!=NULL) {
        prev=current;
        cout<<" "<<current->id;
        cout<<"\t\t"<<current->title<<","<<endl;
        current=current->next;
    }
    if(courseHead!=NULL){
        cout<<" "<<current->id<<"\t\t"<<current->title<<endl;
    }else{
        cout<<"\nNO COURSES REGISTERED YET."<<endl;
    }
}


