// Problem #2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

short ReadNum() {
    short num;
    do {
        cout << "Enter the Year : ";
        cin >> num;
    } while (num > 3000);
    return num;
}

bool IsLeapYear(short Year) {
   /* if (Year % 400 == 0) {
        return true;
    }
    else if ((Year % 4 == 0) && (Year % 100 != 0)) {
        return true;
    }
    else {
        return false;
    }*/

    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0 );

}
int main()
{
    short year = ReadNum();
    if (IsLeapYear(year)) {
        cout << "The year " << year << " is a leap year.\n";
    }
    else {
        cout << "The year " << year << " is NOT a leap year.\n";

    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
