#include <iostream>
#include <fstream>
#include <cstdlib>

using Namespace std;

struct Student
{
    int IDnum[5];
    string Name[5];
    int Age[5];
    string Gender[5];
    double Score[5];
    string grade[5];

};
int main()

{

    double total_scores=0;
    int  TotAge=0;

    int maleCount=0;

    int femaleCount=0;

    double avgScore=0;

    double avgAge=0;

    int numbOfStuds;

    numbOfStuds=5;

    double score;

    Student calc;

    for (int i=0; i<numbOfStuds; i++)

    {
       cout << "Enter your ID: ";
       cin >> calc.IDnum[i];
       cout << "\n Enter your Name: ";
       cin >> calc.Name[i];
       cout << "\n Enter your age: ";
       cin >> calc.Age[i];
       cout << "\n Enter your Gender: ";
       cin >> calc.Gender[i];
       cout << "Enter your Score: ";
       cin >> calc.Score[i];

       if (calc.Score[i]>80 && calc.Score[i]<=100)
       {
           calc.grade[i]="A";
       }

       else if (calc.Score[i] >=70 && calc.Score[i] <80)
       {
          calc.grade[i]="B";
       }
       else if (calc.Score[i]>=60 && calc.Score[i] <70)
       {
          calc.grade[i]="C";
       }
       else if(calc.Score[i]>=50 && calc.Score[i]<60)
       {
           calc.grade[i]="D";
       }
       else if(calc.Score[i] >=40 &&calc.Score[i]<50 )
       {
           calc.grade[i]="E";
       }
       else
       {
           calc.grade[i]="F";
       }


       cout << endl;

                  if (calc.Gender[i]=="male")
           {
               maleCount++;
           }
           else if( calc.Gender[i]=="female")
           {
               femaleCount++;
           }


    }


cout << "*********************************" <<endl;
cout << " ID" << "      " << "Name " << "       " << "Age" << "             " << "Gender " << "         " << "Score" << "        " << "Grade " << endl;

cout << "********************************" << endl;
    for (int i=0;i <numbOfStuds; i++)
    {

        total_scores=total_scores+calc.Score[i];

           TotAge= TotAge+calc.Age[i];

          avgScore= total_scores/numbOfStuds;

           avgAge= TotAge/numbOfStuds;

            cout << calc.IDnum[i] << "\t" << calc.Name[i] << "\t" << calc.Age[i] << "\t" << calc.Gender[i];
        cout << "\t" << calc.Score[i] << "\t" << calc.grade[i] ;

       cout << endl;
    }



    cout << "The average age is:  " << avgAge << endl;

    cout << "The average score is: " << avgScore << endl;

    cout << "The number of females are: " << femaleCount << endl;

    cout << "The number of males are: " << maleCount << endl;

    ofstream A_student;
    A_student.open("Mystudents.txt", ios:: app);

    A_student<< "*********************************" <<endl;

    A_student << " ID" << "  " << "Name " << "     " << "Age" << "      " << "Gender " << "     " << "Score" << "       " << "Grade " << endl;

    A_student <<  "********************************" << endl;

     for (int i=0;i <numbOfStuds; i++)
    {

          total_scores=total_scores+calc.Score[i];

           TotAge= TotAge+calc.Age[i];

          avgScore= total_scores/numbOfStuds;

           avgAge= TotAge/numbOfStuds;

            A_student << calc.IDnum[i] << "\t" << calc.Name[i] << "\t" << calc.Age[i] << "\t" << calc.Gender[i];
        A_student << "\t" << calc.Score[i] << "\t" << calc.grade[i] ;

       A_student << endl;
    }

     A_student << "The average age is:  " << avgAge << endl;

    A_student << "The average score is: " << avgScore << endl;

   A_student << "The number of females are: " << femaleCount << endl;

    A_student << "The number of males are: " << maleCount << endl;

    A_student.close();




    return 0;
}

