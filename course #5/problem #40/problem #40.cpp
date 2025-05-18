// problem #40.cpp : This file contains the 'main' function. Program execution begins and ends there.
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


int GetNumberIndex(int arr[100], int length, int number) {


    for (int i = 0; i < length; i++) {
        if (arr[i] == number) {

            return i;
        }
    }

    return -1;
}

bool isNumberFound(int arr[100], int length, int number) {




    return GetNumberIndex(arr, length, number) != -1;
}



void AddElementToArray(int num, int arr[100], short& length) {

    arr[length] = num;
    length++;

}


void CopyDistinctNumberToArray(int arr1[100], int arr2[100], int length, short& length2) {

    for (int i = 0; i < length; i++) {
        if (!isNumberFound(arr2, length2, arr1[i])) {
            AddElementToArray(arr1[i], arr2, length2);
        }

    }
}
int main()
{

    int arr[100] = {10, 10, 10, 50, 50, 70, 70, 70, 90
}, arr2[100];
    int arrayLength = 9;
    short arr2Length = 0;
    cout << "First  array is: ";
    PrintArray(arr, arrayLength);

    CopyDistinctNumberToArray(arr, arr2, arrayLength, arr2Length);
    cout << "\nArray 2 distinct elements: ";
    PrintArray(arr2, arr2Length);


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
