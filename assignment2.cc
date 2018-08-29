#include<iostream>
using namespace std;
int main(){
int num;
int res=0;
cout<< "Please enter your number to find out if itÕs a prime number" <<endl;
cin >> num;
    //Use for loop
    for(int n= 1; n<= num; n++)
    {
        if (num % n == 0)
        {
            res++;
        }
    }
    if (res==2)
    {
        cout<< "The number is prime"<<endl;
    }
    else{
        cout<< "The number is not prime"<<endl;
    }

}
