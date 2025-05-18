// Problem #20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
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
            printf(" %0*d ", 2, arr[i][j]);

        }
        cout << "\n\n";
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
void printInterseptNums(int arr[3][3], int arr2[3][3], int row, int col) {
    cout << "the intersepct numbers is : ";
    int number;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            number = arr[i][j];
            if (isNumberInMatrix(number, arr2, row, col))
                cout << setw(3) << number << " ";
        }
    }
    cout << endl;
}

bool isPalindrome(int arr[3][3], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col / 2; j++) {
            if (arr[i][j] != arr[i][col - 1 - j])
                return false;
        }
    }
    return true;
}

int GetMinNum(int arr[3][3], int row, int col) {
    int min = arr[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (min > arr[i][j]) {
                min = arr[i][j];
            }
        }
    }
    return min;
}
int GetMaxNum(int arr[3][3], int row, int col) {
    int max = arr[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (max < arr[i][j]) {
                max = arr[i][j];
            }
        }
    }
    return max;
}
int main()
{
    int mat1[3][3]{ {1,2,1},{5,5,5},{7,3,7} };

    //FillArrayWithRandomNum(mat1, 3, 3);


    cout << "Matrix num 1 : \n";
    PrintMatrix(mat1);

    if (isPalindrome(mat1, 3, 3))
        cout << "Yes: Matrix is Palindrome.\n\n";
    else
        cout << "No: Matrix is NOT Palindrome. \n\n";

}
