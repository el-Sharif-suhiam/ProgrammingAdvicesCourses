// Problem #17.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int ReadPositiveNumber(string msg) {
    int num;
    do {
        cout << msg << endl;
        cin >> num;
    } while (num < 0);
    return num;
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


bool isNumberInMatrix(int number, int arr[3][3], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            if (arr[i][j] == number) {
                return true;
            }

        }

    }
    return false;
}

int main()
{
    int mat1[3][3];
    FillArrayWithRandomNum(mat1, 3, 3);
    cout << "Matrix num 1 : \n";
    PrintMatrix(mat1);
    int countNum = ReadPositiveNumber("Enter the number to count in matrix : ");

    if (isNumberInMatrix(countNum, mat1, 3, 3)) {
        cout << "Yes it is there \n\n";
    }
    else {
        cout << "No it is NOT there. \n\n";
    }

}
