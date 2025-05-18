
#include <iostream>
#include <string>
using namespace std;


void mySumProcedure() {
    unsigned short num1, num2;
    cout << "Please enter Number1?" << endl;
    cin >> num1;
    cout << "Please enter Number2?" << endl;
    cin >> num2;
    cout << "*************************" << endl;
    cout << num1 + num2;
}

int mySumFunction() {
    unsigned short num1, num2;
    cout << "Please enter Number1?" << endl;
    cin >> num1;
    cout << "Please enter Number2?" << endl;
    cin >> num2;
    cout << "*************************" << endl;
    return num1 + num2;
}

int main()
{
    //mySumProcedure();
    int result = mySumFunction();
    cout << "result is: " << result;
}
