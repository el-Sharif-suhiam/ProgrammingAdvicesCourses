// Problem #16.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void PrintMatrix(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %0*d ", 1, arr[i][j]);

        }
        cout << endl;
    }
    cout << endl;
}


int CountNumberInMatrix(int number, int arr[3][3], int row, int col) {
    int counter = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            if (arr[i][j] == number) {
                counter++;
            }

        }

    }
    return counter;
}
//
//bool isSparceMatrix(int arr[3][3], int row, int col) {
//    int zeroCounter = 0;
//    int nonZeroCounter = 0;
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++) {
//
//            if (arr[i][j] == 0) {
//                zeroCounter++;
//            }
//            else if (arr[i][j] > 0) {
//                nonZeroCounter++;
//            }
//
//        }
//
//    }
//    return zeroCounter > nonZeroCounter;
//}


bool isSparceMatrix(int arr[3][3], int row, int col) {
    short MatrixCount = row * col;
    return (CountNumberInMatrix(0, arr, 3, 3) >= (MatrixCount / 2));
}
int main()
{
    int mat1[3][3]{ {9,0,12},{0,9,1},{0,0,9} };
    cout << "Matrix num 1 : \n";
    PrintMatrix(mat1);
    if (isSparceMatrix(mat1, 3, 3)) {
        cout << "Yes: It is Saprse.\n\n";
    }
    else {
        cout << "No: It is NOT Sparse.\n\n";
    }


}
