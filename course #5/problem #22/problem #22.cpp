// problem #22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;


int ReadPostitiveNumber(string msg) {
    int number;
    do {
        cout << msg << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}

void ReadArray(int arry[100],int length) {
    for (int i = 0; i < length; i++) {
        string msg = "Element [" + to_string(i +1) + "] :";
        arry[i] = ReadPostitiveNumber(msg);
    }
}
void PrintArray(int arry[100], int length) {

    cout << "Orignal array:";
    for (int i = 0; i < length; i++) {
        cout << " " << arry[i];
    }
    cout << endl;
}

int RepeatTimes(int arry[100], int length,short numberToCheck) {
    short counter = 0;

    for (int i = 0; i < length; i++) {
        if (arry[i] == numberToCheck) {
            counter++;
        }
    }
    return counter;
}
int main()
{
    int arr[100];
    int arrayLength = ReadPostitiveNumber("enter the array length: ");

    ReadArray(arr, arrayLength);
    short numberToCheck = ReadPostitiveNumber("Enter the number you want to check : ");
    PrintArray(arr, arrayLength);
    cout << "\n" << numberToCheck << " is repeated " << RepeatTimes(arr,arrayLength,numberToCheck) << " time(s). \n";

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
