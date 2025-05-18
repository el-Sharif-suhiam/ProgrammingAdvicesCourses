// Inhertince.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "clsPerson.h"
#include "clsEmployee.h"
#include "clsDeveloper.h"
#include "clsRedmi.h"
using namespace std;




// abstract class / interface class


int main()
{
    clsEmployee employee(5,"Alsharif","Suhaim","a@email.com", "464646464", "jr.developer", "web dev", 3000);
    clsDeveloper developer(5, "Asraf", "Suhaim", "gg@email.com", "464646464", "jr.developer", "web dev", 3000, "JavaScript, C++");
   
    developer.Print();

    clsPerson* person = &developer;
    person->Print();
    
    clsPerson* per2 = new clsDeveloper(5, "Asraf222", "Suhaimdd", "gg@email.com", "222226464", "jr.developer",  "dev", 8000, "c#");
    cout << per2->FullName() <<endl;

    // interface 

    clsRedmi xiaomi10;
    xiaomi10.Dialup(56459546);
    system("pause >0");
}
