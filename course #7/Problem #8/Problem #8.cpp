// Problem #8.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void MultiplyMatrix(int mat1[3][3], int mat2[3][3], int multiply[3][3], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            multiply[i][j] = mat1[i][j] * mat2[i][j];
        }
    }
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
    int mat1[3][3], mat2[3][3], multMat[3][3];
    cout << "First Matrix : \n";
    FillArrayWithRandomNum(mat1, 3, 3);
    PrintMatrix(mat1);
    cout << "Second Matrix : \n";
    FillArrayWithRandomNum(mat2, 3, 3);
    PrintMatrix(mat2);
    cout << "The multiply is : \n\n";
    MultiplyMatrix(mat1, mat2, multMat, 3, 3);
    PrintMatrix(multMat);

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
