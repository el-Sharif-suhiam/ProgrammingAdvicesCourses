// Problem #4.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}
short DaysInYear(short year) {
    return IsLeapYear(year) ? 366 : 365;
}
short HoursInYear(short year) {
    return DaysInYear(year) * 24;
}
int MinInYear(short year) {
    return HoursInYear(year) * 60;
}
int SecInYear(short year) {
    return MinInYear(year) * 60;
}
int main()
{
    short year = ReadNum();
    cout << "\nNumber of Days    in year [" << year << "] is : " << DaysInYear(year) << endl;
    cout << "Number of Hours   in year [" << year << "] is : " << HoursInYear(year) << endl;
    cout << "Number of Minutes in year [" << year << "] is : " << MinInYear(year) << endl;
    cout << "Number of Seconds in year [" << year << "] is : " << SecInYear(year) << endl;

    return 0;
}
