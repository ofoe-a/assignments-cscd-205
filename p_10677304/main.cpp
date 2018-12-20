#include<iostream>
#include<fstream>
#include<Windows.h>
#include<cctype>
#include<conio.h>
#include "include\student.h"
#include "include\staff.h"

void student_menu(){
    char x;
    system("cls");
    cout << "\nSTUDENT MENU\n" << endl;
    cout << "1)ADD NEW STUDENT" << endl;
    cout << "2)EDIT STUDENT DETAIL" << endl;
    cout << "3)DELETE STUDENT" << endl;
    cout << "4)SEARCH FOR STUDENT" << endl;
    x=getch();
    switch(x){
        case '1':	system("cls");addStudent(); break;
        case '2':	system("cls"); modifyStudent(); break;
        case '3':	system("cls"); delStudent();break;
        case '4':	system("cls"); searchStudent(); break;
        default:	cout<<"\a"; exit(0); break;
    }
}
void staff_menu(){
    char x;
    system("cls");
    cout << "\nSTAFF MENU\n" << endl;
    cout << "1)ADD NEW STAFF" << endl;
    cout << "2)EDIT STAFF DETAIL" << endl;
    cout << "3)DELETE STAFF" << endl;
    cout << "4)SEARCH STAFF" << endl;
    x=getch();
    switch(x){
        case '1':	system("cls");addStaff(); break;
        case '2':	system("cls"); modifyStaff(); break;
        case '3':	system("cls"); delStaff();break;
        case '4':	system("cls"); searchStaff(); break;
        default:	cout<<"\a"; exit(0); break;
    }
}
void course_menu(){
    char x;
    system("cls");
    cout << "\nCOURSE MENU\n" << endl;
    cout << "1)ADD NEW COURSE" << endl;
    cout << "2)EDIT COURSE DETAIL" << endl;
    cout << "3)DELETE COURSE" << endl;
    cout << "4)SEARCH COURSE" << endl;
    cout << "5)All COURSES" << endl;
    x=getch();
    switch(x){
        case '1':	system("cls");addCourse(); break;
        case '2':	system("cls"); modifyCourse(); break;
        case '3':	system("cls"); getAllCourses();delCourse();break;
        case '4':	system("cls"); searchCourse(); break;
        case '5':	system("cls"); getAllCourses(); break;
        default:	cout<<"\a"; exit(0); break;
    }
}

void assignStudentCourse(){
    Student *ptr;
    int id;
    cout<<"Enter ID of Student: "<<endl;
    cin>>id;
    ptr=getStudent(id);
    getAllCourses();
    fflush(stdin);
    if(courseHead==NULL){
        cout<<"\nADD COURSE THEN ASSIGN IN MAIN MENU."<<endl;
    }else {
        cout<<"Enter ID of Course to be Assigned: "<<endl;
        Course *d=NULL;
        int id;
        cin>>id;
        try{
            d=getCourse(id);
            ptr->course.push_back(d->title);
            ptr->courseId.push_back(d->id);
            ptr->grades.push_back(0);
        }catch(exception e){
        }
    }
//    gets(current->discipline);
    fflush(stdin);
    cout<<endl<<"Course assigned to Student"<<endl;
}
int index(vector<int> v,int key){
	bool found = false;

	for (int i = 0; i < v.size(); i++)
		if (v[i] == key) {
			found = true;
			return i;
	}

	if (!found) {
		cout << "Element not found";
	}
}
int index(vector<string> v,string key){
	bool found = false;

	for (int i = 0; i < v.size(); i++)
		if (v[i] == key) {
			found = true;
			break;
	}

	if (!found) {
		cout << "Element not found";
	}
}
void recordGrade(){
    system("cls");
    Student *ptr;
    int x;
    cout<<"Enter ID of Student: "<<endl;
    cin>>x;
    ptr=getStudent(x);
    getAssignedCourses(ptr->id);
    fflush(stdin);
    if(courseHead==NULL){
        cout<<"\nASSIGN STUDENT TO COURSE THEN TRY AGAIN."<<endl;
    }else {
        cout<<"Enter ID of Course to Grade: "<<endl;
        cin>>x;
        x=index(ptr->courseId,x);
        try{
            cout<<"Enter grade assigned: "<<endl;
            int y;
            cin>>y;
            ptr->grades.insert(ptr->grades.begin()+x,y);
            cout<<ptr->grades[x];
        }catch(exception e){
        }
    }
    fflush(stdin);
    cout<<endl<<"Grade assigned to Student"<<endl;
}
void printRecord(){
    system("cls");
    int x;
    cout<<"Enter ID of Student: "<<endl;
    cin>>x;
    getAcademicRecord(x);
    fflush(stdin);
    cout<<endl<<"Course assigned to Student"<<endl;
}

void entry_menu() {
    char ch;
    int num;
    system("cls");
    cout<<"\t\t\t\t\t ********************************* \t\t\t"<<endl;
    cout<<"\t\t\t\t\t ****STUDENT MANAGEMENT SYSTEM**** \t\t\t"<<endl;
    cout<<"\t\t\t\t\t ********************************* \t\t\t"<<endl;
    cout << "\nENTRY MENU " << endl<< endl;
    cout << "1)ADD/ EDIT/ DELETE COURSES" << endl;
    cout << "2)ADD/ EDIT/ DELETE STUDENT" << endl;
    cout << "3)ADD/ EDIT/ DELETE STAFF" << endl;
    cout << "4)ASSIGN STUDENT TO COURSE(S)" << endl;
    cout << "5)RECORD GRADE" << endl;
    cout << "6)PRINT ACADEMIC RECORD OF STUDENT" << endl;
    cout << "7)EXIT" << endl;

    ch=getch();
    switch(ch) {
        case '1':	course_menu(); break;
        case '2':	student_menu(); break;
        case '3':	staff_menu(); break;
        case '4':	assignStudentCourse(); break;
        case '5':	recordGrade(); break;
        case '6':	printRecord(); break;
        case '7':	exit(0);
        default:	cout<<"\a"; entry_menu(); break;
    }
}

bool continuity(){
    char sentinel;
    cout << "\n\n\nWould you like to perform another action?\n1.Yes\n2.No"<<endl;
    sentinel=getch();
    if(sentinel == '1'){return true;}else{return false;}
}

int main(){
    bool sentinel = false;
    do {
        system("cls");
        entry_menu();
        sentinel = continuity();
    }while(sentinel);
    return 0;
}
