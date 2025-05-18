// Math Functions in C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "iostream"
#include "cmath"

using namespace std;

enum Color {red,green,blue};
enum Months { jun = 1, feb, mar, april, may, june, july , aug, sep, oct, nov, dec};


int main()
{
	Color myColor;
	myColor = Color::blue;
	Months thisMonth = jun;

	cout << " color = " << myColor << endl;
	cout << " month = " << thisMonth << endl;
	cout << " month = " << july << endl;


	// #16
	/*short a, d;
   cout << "Programp to calculate, Rectangle area Through Diagonal and Side Area \nPlease enter a?" << endl;
   cin >> a;
   cout << "Enter d?" << endl;
   cin >> d;
   float Area = a * sqrt(pow(d, 2) - pow(a, 2));

   cout << "the Area is: " << Area << endl;*/
   // corrct 
   ////////////////////////////////////////////////////////

	// #18
	/*short r;
	float Pi = 3.14;
	cout << "Programp to calculate, Circle Area  \nPlease enter r?" << endl;
	cin >> r;
	float Area = Pi * pow(r,2);

	cout << "the Area is: " << ceil(Area) << endl;*/
	//Corrct
	//////////////////////////////////////////////////////

	//# 19

	//short D;
	//float Pi = 3.14;
	//cout << "Programp to calculate, Circle Area Through Diameter  \nPlease enter D?" << endl;
	//cin >> D;
	//float Area = (Pi * pow(D, 2)) / 4;

	//cout << "the Area is: " << ceil(Area) << endl;
	
	//Corrct
	//////////////////////////////////////////////////////////

	// #20

	//short A;
	//float Pi = 3.14;
	//cout << "Programp to calculate,Circle Area Inscribed in a Square  \n\nPlease enter A?" << endl;
	//cin >> A;
	//float Area = Pi * pow((A/2), 2);

	//cout << "the Area is: " << ceil(Area) << endl;
	//
	// Corrct 
	////////////////////////////////////////////////////
	// #21

	//float l,Pi = 3.14;
	//cout << "Programp to calculate, Circle Area Along the Circumference  \n\nPlease enter l?" << endl;
	//cin >> l;
	//float Area = pow(l,2) / (4 * Pi);

	//cout << "the Area is: " << floor(Area) << endl;
	
	// Corrct
	////////////////////////////////////////////////////

	// #22


	//float a,b,Pi = 3.14;
	//cout << "Programp to calculate,  Circle Area Inscribed in an Isosceles Triangle  \n\nPlease enter a?" << endl;
	//cin >> a;
	//cout << "Please enter b ?" << endl;
	//cin >> b;
	//float Area = Pi * (pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b));

	//cout << "the Area is: " << floor(Area) << endl;

	// Corrct
	/////////////////////////////////////////////////////

	//#23


	//float a,b,c,Pi = 3.14;
	//cout << "Programp to calculate, Circle Area circle Described Around an Arbitrary Triangle  \n\nPlease enter a?" << endl;
	//cin >> a;
	//cout << "Please enter b ?" << endl;
	//cin >> b;
	//cout << "Please enter c ?" << endl;
	//cin >> c;
	//float p = (a + b + c) / 2;
	//float Area = Pi * pow(((a*b*c)/(4*sqrt(p*(p-a)*(p-b)*(p-c)))), 2);

	//cout << "the Area is: " << round(Area) << endl;

	// Corrct

	//////////////////////////////////////////////////

	// #31

	//short number;
	//cout << "Program to calculate, Power of 2,3,4  \n\nPlease enter the number?" << endl;
	//cin >> number;
	//
	//cout << "the result is: \n" << round(pow(number, 2)) << "\n\n" << round(pow(number, 3))  << "\n\n" << round(pow(number, 4))  << endl;
	//cout << "The result is: \n";
	//cout << number << "^2" <<  " = " << round(pow(number, 2)) << endl;
	//cout << number << "^3" << " = " << round(pow(number, 3)) << endl;
	//cout << number << "^4" << " = " << round(pow(number , 4)) << endl;
	//// Corrct;
	/////////////////////////////////////////////////////
	
	// #32

	//short number,M;
	//cout << "Program to calculate, Power of M \n\nPlease enter the number?" << endl;
	//cin >> number;
	//cout << "Enter M ?" << endl;
	//cin >> M;
	//cout << "The result is: \n";
	//unsigned int result = pow(number, M);
	//cout << number << "^" << M << " = " << round(result) << endl;
	//
	//Corrct
	////////////////////////////////////////////////
	
	// #42
	/*short days, hours, minutes, seconds;

	cout << "Calculate Task Duration In Seconds, enter days :" << endl;
	cin >> days;
	cout << "hours :" << endl;
	cin >> hours;
	cout << "mintues :" << endl;
	cin >> minutes;
	cout << "seconds :" << endl;
	cin >> seconds;

	int result = (days * 24 * 60 * 60) + (hours * 60 * 60) + (minutes * 60) + seconds;

	cout << round(result) << " seconds " << endl;*/

	// Corrct
	////////////////////////////////////////////////

	// #43
	/*int seconds;
	cout << "program to take seconds and turn it into days, hours, minutes, seconds \n"
		<< "enter the seconds : " << endl;
	cin >> seconds;

	int remainOfSeconds = seconds % 60;
	int minutes = (seconds - remainOfSeconds ) / 60, remainOfMin = minutes % 60;
	int hours = (minutes -remainOfMin ) / 60, remainOfHours = hours % 24;
	unsigned short days = (hours - remainOfHours ) / 24;

	cout << "Result is = " << round(days) << ":" << round(remainOfHours) << ":" << round(remainOfMin) << ":"
		<< round(remainOfSeconds) << endl;*/

	//Corrct

struct person {
	string name;
	short age;
	string country;
	short wight;
};

person alshrif;
alshrif.name = "Alsharif suhaim";
alshrif.age = 27;
alshrif.country = "Libya";
alshrif.wight = 80;
cout << "you are " << alshrif.name << " your age is " << alshrif.age << " , country is " << alshrif.country << " last thing your wight is"
<< alshrif.wight << endl;


return 0;
}
