
// Problem #7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;


void FillArrayWithOrderNum(int arr[3][3], int row, int col) {
    short n = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = n++;
        }
    }
}

void transposeMatrix(int OrderedArr[3][3],int Transpose[3][3], short row, short col) {
    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
            Transpose[j][i] = OrderedArr[i][j];
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
    int arr[3][3];
    int transpose[3][3];
    FillArrayWithOrderNum(arr, 3, 3);
    cout << "The 3x3 Matrix with order elements is: \n\n";
    PrintMatrix(arr);
    cout << "\nTrnasposed Martrix is : \n\n";
    transposeMatrix(arr, transpose, 3, 3);
    PrintMatrix(transpose);
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
