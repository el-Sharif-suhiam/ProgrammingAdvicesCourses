// problem #30.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int RandomNumber(int from, int to) {

    int randomNum = rand() % (to - from + 1) + from;

    return randomNum;
}

void PrintArray(int arry[100], int length) {
    for (int i = 0; i < length; i++) {
        cout << " " << arry[i];
    }
    cout << endl;
}

void fillArrayWithRandom(int arr[100], int length) {
    for (short i = 0; i < length; i++) {
        arr[i] = RandomNumber(1, 100);
    }
}

void sumTwoArray(int arr1[100], int arr2[100], int arr3[100], int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        arr3[i] = arr1[i] + arr2[i];
    }
}


int main()
{
    srand((unsigned)time(NULL));
    //int primeNumbers = 0;
    int arr[100], arr2[100];
    int arrayLength = ReadPostitiveNumber("enter the array length: ");
    fillArrayWithRandom(arr, arrayLength);
    cout << "First  array is: \n";
    PrintArray(arr, arrayLength);

    fillArrayWithRandom(arr2, arrayLength);
    cout << "\nSecond array is: \n";
    PrintArray(arr2, arrayLength);

    int arr3[100];

    sumTwoArray(arr, arr2, arr3, arrayLength);

    cout << "\nSum of array1 and array2 elements is: \n";
    PrintArray(arr3, arrayLength);



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
