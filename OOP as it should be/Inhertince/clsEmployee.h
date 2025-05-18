#pragma once
#include <iostream>
#include "clsPerson.h"
using namespace std;

class clsEmployee : public clsPerson {
private:
    int _Salary;
    string _Department;
    string _Title;
public:

    clsEmployee(int id, string fName, string lName, string email, string phone, string title, string department, int salary)
        : clsPerson(id, fName, lName, email, phone) {
        _Salary = salary;
        _Department = department;
        _Title = title;
    }
    void SetSalary(int salary) {
        _Salary = salary;
    }
    int Salary() {
        return _Salary;
    }
    void SetDepartment(string department) {
        _Department = department;
    }
    string Department() {
        return _Department;
    }
    void SetTitle(string title) {
        _Title = title;
    }
    string Title() {
        return _Title;
    }


    void Print() {
        cout << "\nInfo:";
        cout << "\n__________________________";
        cout << "\nID         : " << ID();
        cout << "\nFirstName  : " << FirstName();
        cout << "\nLastName   : " << LastName();
        cout << "\nFull Name  : " << FullName();
        cout << "\nEmail      : " << Email();
        cout << "\nPhone      : " << Phone();
        cout << "\nTitle      : " << Title();
        cout << "\nDepartment : " << Department();
        cout << "\nSalary     : " << Salary();
        cout << "\n__________________________\n";
    }
};


