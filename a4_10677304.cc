//10677304
#include<iostream>
using namespace std;
int hcf(int a, int b)
{
    if(b != 0){
        return hcf(b, a % b);
    } else return a;
}

int main(void)
{
    int num1, num2, result;
    cout << "PLease enter two numbers to find the HCF" <<endl;
    cout << "PLease enter first number" <<endl;
    cin >> num1;
    cout << "PLease enter second number" <<endl;
    cin >> num2;
    result = hcf(num1, num2);
    if (hcf)
        cout << "The HCF of " << num1 << " and " << num2 << " is: " << result
                << endl;
    else
        cout << "Your input is invalid"<<endl;
    return 0;
}
