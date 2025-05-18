// Calculater Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class clsCalculator {
private:
    int _Result = 0;
    int _LastNum = 0;
    string _LastOp = "Nothing";
    int IsZero(int num) {
        return num == 0 ? 1 : num;
    }
    void _UpdateMembers(int LastNum, string Op) {
        _LastNum = LastNum;
        _LastOp = Op;
    }
public:
    void Clear() {
        _Result = 0;
        _UpdateMembers(0, "clear");
    };

    void Add(int num) {
        _Result += num;
        _UpdateMembers(num, "Adding");
    }
    void Subtract(int num) {
        _Result -= num;
        _UpdateMembers(num, "Subtracting");
    }
    void Multiply(int num) {
        _Result *= num;
        _UpdateMembers(num, "Multiplying");
    }
    void Divide(int num) {
        num = IsZero(num);
        _Result /= num;
        _UpdateMembers(num, "Dividing");
    }

    void PrintResult() {
        cout << "Result After " << _LastOp << " " << _LastNum << " is: " << _Result << endl;
    }

};

int main()
{
    clsCalculator Calc1;
    Calc1.Add(10);
    Calc1.PrintResult();

    Calc1.Multiply(6);
    Calc1.PrintResult();

    Calc1.Subtract(10);
    Calc1.PrintResult();

    Calc1.Add(70);
    Calc1.PrintResult();

    Calc1.Divide(0);
    Calc1.PrintResult();

    Calc1.Divide(6);
    Calc1.PrintResult();

    Calc1.Clear();
    Calc1.PrintResult();

    Calc1.Multiply(10);
    Calc1.PrintResult();
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
