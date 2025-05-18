// Relational Operators.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>;
using namespace std;
int main()
{
    unsigned short a, b;

    cout << "Please enter the first number A ?" << endl;
    cin >> a;
    cout << "Now enter the second number B ?" << endl;
    cin >> b;

    cout << a << " = " << b << " is " << (a == b) << endl;
    cout << a << " != " << b << " is " << (a != b) << endl;
    cout << a << " > " << b << " is " << (a > b) << endl;
    cout << a << " < " << b << " is " << (a < b) << endl;
    cout << a << " >= " << b << " is " << (a >= b) << endl;
    cout << a << " <= " << b << " is " << (a <= b) << endl;
    cout << "\a";
}
