// problem #36.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


int ReadPostitiveNumber(string msg) {
    int number;
    do {
        cout << msg << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}

void PrintArray(int arry[100], int length) {
    for (int i = 0; i < length; i++) {
        cout << " " << arry[i];
    }
    cout << endl;
}

void AddElementToArray(int arr[100],short &length) {
    int num = ReadPostitiveNumber("enter the number");
    arr[length] = num;
    length++;
        
}

void InputUserInArry(int arr[100], short& length) {
    bool addmore;

    do {
        AddElementToArray(arr, length);
        cout << "Do you want to add more numbers? [0]:No,[1]:yes? ";
        cin >> addmore;
    } while (addmore);
    
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100];
    short arrayLength = 0;
    

    InputUserInArry(arr, arrayLength);
        cout << "\nArray Length: " << arrayLength << endl;
        cout << "Array Elements: " << endl;
        PrintArray(arr, arrayLength);
    


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
