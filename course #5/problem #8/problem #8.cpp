// problem #8.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int countFrequncy( int totalNumber, int number) {
    int reminder = 0, counter = 0;
    while (totalNumber > 0) {
        reminder = totalNumber % 10;
        if (reminder == number) {
            counter++;
        }
        totalNumber /= 10;
    }

    return counter;
}
int main()
{
    int totalNumber = ReadPostitiveNumber("Enter the total number : ");
    short digitNum = ReadPostitiveNumber("Enter the number that you want to know it's frequncy : ");
    cout << "\nDigit " << digitNum << " Frequency is " << countFrequncy(totalNumber, digitNum) << " Time (s).\n\n";
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
