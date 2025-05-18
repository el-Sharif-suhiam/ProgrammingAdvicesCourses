// Problem #3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Problem #2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;
int RandomNumber(int from, int to) {
    int randNum = rand() % (to - from) + from;
    return randNum;
};

void FillArrayWithRandomNum(int arr[3][3], int row, int col) {
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

int SumRows(int arr[3][3], int row, int col) {
    int sum = 0;
    for (int j = 0; j < col; j++) {
        sum += arr[row][j];
    }
    return sum;
}
void FillSumInArray(int arr[3], int matrix[3][3], int row, int col) {
    for (int i = 0; i < row; i++) {
        arr[i] = SumRows(matrix, i, col);
    }
}
void PrintSumMatrixRows(int arr[3], int row) {
    for (int i = 0; i < row; i++) {
       
        cout << "The sum of row number " << i + 1 << " : " << arr[i] << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3];
    int SumArr[3];
    FillArrayWithRandomNum(arr, 3, 3);
    cout << "The Matrix elements is: \n\n";
    PrintMatrix(arr);
    cout << endl;
    FillSumInArray(SumArr, arr, 3, 3);
    PrintSumMatrixRows(SumArr, 3);
    return 0;
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
