
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ReadPostitiveNumber(string msg) {
    int number;
    do {
        cout << msg << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}



bool isPrefectNumber(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    return num == sum;
}

void PrintResult(int number) {
    if (isPrefectNumber(number)) {
        cout << number << " Is Perfect Number. \n";
    }
    else {
        cout << number << " Is NOT Perfect Number. \n";
    }
}
int main()
{
    PrintResult(ReadPostitiveNumber("Enter the number ? "));
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
