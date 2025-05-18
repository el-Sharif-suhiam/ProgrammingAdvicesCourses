// Problem #14.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
            printf(" %0*d ", 1, arr[i][j]);

        }
        cout << endl;
    }
}

bool isScalarMatrix(int arr[3][3], int col, int row) {
    int scalNum = arr[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            if (i == j && arr[i][j] != scalNum) {
                return false;
            }
            if (i != j && arr[i][j] != 0) {
                return false;
            }
        }

    }
    return true;

}

int main()
{
    int mat1[3][3]{ {9,0,0},{0,1,0},{0,0,9} };
    cout << "Matrix num 1 : \n";
    PrintMatrix(mat1);


    if (isScalarMatrix(mat1, 3, 3)) {
        cout << "\nYes, Matrix is scalar ...\n\n";
    }
    else {
        cout << "\nNo, Matrix is NOT scalar. \n\n";

    }
}
