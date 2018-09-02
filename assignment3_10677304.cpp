#include <iostream>
using namespace std;
int main()
{
    int grade;
    cout << "Please enter your percentage"<< endl;
    cin >> grade;
    if (grade < 60){
        cout <<"You grade is F"<< endl;
    }else if (grade < 65){
        cout <<"Your grade is E"<< endl;
    }else if (grade < 70){
        cout <<"Your grade is D"<< endl;
    }else if (grade < 75){
        cout <<"Your grade is C"<< endl;
    }else if (grade < 80){
       cout <<"Your grade is B"<< endl;
    } else{
    cout <<"Your grade is A"<< endl;;
    }

}
