// This Pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class clsEmployee {
    int ID;
    string Name;
    float Salary;
public:
    clsEmployee(int ID, string Name, float Salary) {
        this->ID = ID;
        this->Name = Name;
        this->Salary = Salary;
    }

    static void func1(clsEmployee employee) {
        cout << "Id: " << employee.ID << ", Name : " << employee.Name << ", Salary : " << employee.Salary << endl;
    }

    void func2() {
        func1(*this);
    }

};
int main()
{
    clsEmployee employee(52, "Alsharif", 6000);
    employee.func2();

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
