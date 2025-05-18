// problem #41.cpp : This file contains the 'main' function. Program execution begins and ends there.
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


void PrintArray(int arry[100], int length) {
    for (int i = 0; i < length; i++) {
        cout << " " << arry[i];
    }
    cout << endl;
}





void AddElementToArray(int num, int arr[100], short& length) {

    arr[length] = num;
    length++;

}
bool isArrayPlindrom(int arr[100], int length) {
    for (int i = 0; i < length; i++) {
        if (arr[i] != arr[length - i - 1]) {
            return false;
        }
    }
    return true;
}


int main()
{

    int arr[100] = { 10,20,30,30,20,10};
    int arrayLength = 6;
    cout << "First  array is: ";
    PrintArray(arr, arrayLength);
    if (isArrayPlindrom(arr, arrayLength)) {
        cout << "Yes array is Palindrom \n";
    }
    else {
        cout << "No it not Palindrom \n";
    }
   

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
