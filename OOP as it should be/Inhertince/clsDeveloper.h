#pragma once
#include <iostream>
#include "clsEmployee.h"

using namespace std;
class clsDeveloper : public clsEmployee {
    string _MainProgrammingLang;

public:
    clsDeveloper(int id, string fname, string lname, string email, string phone, string title, string department, int salary, string programmingLang) :
        clsEmployee(id, fname, lname, email, phone, title, department, salary) {
        _MainProgrammingLang = programmingLang;
    }

    void SetMainProgrammingLanguage(string program) {
        _MainProgrammingLang = program;
    }

    string MainProgrammingLanguage() {
        return _MainProgrammingLang;
    }
    void Print() {
        cout << "\nInfo:";
        cout << "\n____________________________________________";
        cout << "\nID                        : " << ID();
        cout << "\nFirstName                 : " << FirstName();
        cout << "\nLastName                  : " << LastName();
        cout << "\nFull Name                 : " << FullName();
        cout << "\nEmail                     : " << Email();
        cout << "\nPhone                     : " << Phone();
        cout << "\nTitle                     : " << Title();
        cout << "\nDepartment                : " << Department();
        cout << "\nSalary                    : " << Salary();
        cout << "\nMain Programming Language :" << MainProgrammingLanguage();
        cout << "\n_____________________________________________\n";
    }

};
