// Problem #9.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
};

void PrintMatrix(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %0*d ", 2, arr[i][j]);

        }
        cout << endl;
    }
}
void PrintMiddleRow(int arr[3][3], int row) {
    int mid = row / 2;
    for (int i = 0; i < row; i++) {
        printf(" %0*d ", 2, arr[mid][i]);

    }
    cout << endl;

};
void PrintMiddleCol(int arr[3][3], int col) {
    int mid = col / 2;
    for (int i = 0; i < col; i++) {
        printf(" %0*d ", 2, arr[i][mid]);

    };
    cout << endl;
};
//void GetMiddle(int arr[3][3], int midRow[3], int midCol[3]) {
//    for (int i = 0; i < 3; i++) {
//        midRow[i] = arr[1][i];
//        midCol[i] = arr[i][1];
//    }
//}
int main()
{
    int arr[3][3];
    cout << "The Matrix is : \n\n";
    FillArrayWithRandomNum(arr, 3, 3);
    PrintMatrix(arr);
   /* GetMiddle(arr, midRow, midCol);*/
    cout << "\nThe middle Row is : \n";
    PrintMiddleRow(arr,3);
    cout << "\nThe middle Col is : \n";
    PrintMiddleCol(arr,3);
}

