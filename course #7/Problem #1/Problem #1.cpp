// Problem #1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;
int RandomNumber(int from, int to) {
    int randNum = rand() % (to - from) + from;
    return randNum;
};
int GetRandomNum(int max) {
    return rand() % (max + 1);
}
void FillArrayWithRandomNum(int arr[3][3], int row , int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(3) << arr[i][j];
        }
        cout << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3];
   
    FillArrayWithRandomNum(arr, 3, 3);
    PrintMatrix(arr);
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
