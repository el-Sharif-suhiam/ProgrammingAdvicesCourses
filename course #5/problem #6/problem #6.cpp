// problem #6.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void sumOfDigits(int num) {
    int reminder = 0;
    int sum = 0;
    while (num > 0) {
        reminder = num % 10;
        num /= 10;
        sum += reminder;
    }
    cout << "the sum is : " << sum << endl;
}
int main()
{
    sumOfDigits(ReadPostitiveNumber("enter the number you want to sum it digits: "));

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
