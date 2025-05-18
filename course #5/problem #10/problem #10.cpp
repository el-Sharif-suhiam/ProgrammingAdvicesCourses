// problem #10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;



int ReadPostitiveNumber(string msg) {
    int number;
    do {
        cout << msg << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}


int reverseNumber(int num) {
    int reminder = 0, newNum = 0;
    while (num > 0) {
        reminder = num % 10;
        num /= 10;
        newNum = newNum * 10 + reminder;
    }
    return newNum;
}

void printDigits(int num) {
    int reminder = 0;
    while (num > 0) {
        reminder = num % 10;
        num /= 10;
        cout << reminder << endl;
    }
}

int main()
{
    int number = ReadPostitiveNumber("enter the number : ");
    cout << "\n";
    printDigits(reverseNumber(number));
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
