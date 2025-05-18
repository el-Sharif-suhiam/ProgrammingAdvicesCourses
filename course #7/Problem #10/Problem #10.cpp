// Problem #10.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
            arr[i][j] = RandomNumber(1, 9);
        }
    }
}

int sumMatrix(int arr[3][3], int col, int row) {
    int sum = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

void PrintMatrix(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %0*d ", 2, arr[i][j]);

        }
        cout << endl;
    }
}


int main()
{
    srand((unsigned)time(NULL));

    int matrix[3][3];
    FillArrayWithRandomNum(matrix, 3, 3);
    cout << "the matrix is: \n\n";
    PrintMatrix(matrix);
    
    cout << "the sum of the matrix is: " <<  sumMatrix(matrix, 3, 3) << endl;
}

