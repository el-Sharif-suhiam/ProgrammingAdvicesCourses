// Problem # 12.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

bool isMatricesTypical(int arr[3][3], int arr2[3][3], int col, int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] != arr2[i][j]) {
                return false;
            }
        }
    }
    return true;
    
}

int main()
{
    int mat1[3][3], mat2[3][3];
    FillArrayWithRandomNum(mat1, 3, 3);
    FillArrayWithRandomNum(mat2, 3, 3);
    cout << "Matrix num 1 : \n";
    PrintMatrix(mat1);
    cout << "Matrix num 2 : \n";
    PrintMatrix(mat2);

    if (isMatricesTypical(mat1,mat2,3,3)) {
        cout << "\nYes, Matrices are typical ...\n\n";
    }
    else {
        cout << "\nNo, Matrices are NOT typical. \n\n";

    }
}
