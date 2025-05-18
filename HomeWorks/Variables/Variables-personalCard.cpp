#include "iostream";
#include "string";
using namespace std;

struct Salary {
	unsigned short monthly;
	unsigned int yearly;
};
struct Contact {
	string city;
	string country;
	int phone;
};
//enum Gender {Male, Female};
//enum Status {Single, Married};
struct Person {
	string name;
	short age;
	Contact contact;
	Salary salary;
	char gender ;
	bool isMarried;
};

void readData(Person &guest) {

	cout << "please enter your full name: " << endl;
	getline(cin, guest.name);

	cout << "your age: " << endl;
	cin >> guest.age;

	cin.ignore();

	cout << "your city: " << endl;
	getline(cin, guest.contact.city);

	cout << "your country: " << endl;
	getline(cin, guest.contact.country);

	cout << "your Phone number : " << endl;
	cin >> guest.contact.phone;
	cin.ignore();

	cout << "enter yout monthly salary: " << endl;
	cin >> guest.salary.monthly;

	guest.salary.yearly = guest.salary.monthly * 12;

	cout << "your Gender male (M for Male, F for Female) " << endl;
	cin >> guest.gender;

	cout << "last thing are you married  ? " << endl;
	cin >> guest.isMarried;
	/*guest.gender = Gender::Male;
	guest.isMarried = Status::Single;*/
}

void ShowInfo(Person guest) {

	cout << "**********************************" << endl;
	cout << "Name: " << guest.name << endl;
	cout << "Age: " << guest.age << " years." << endl;
	cout << "City: " << guest.contact.city << endl;
	cout << "Country: " << guest.contact.country << endl;
	cout << "Phone: " << guest.contact.phone << endl;
	cout << "Monthly Salary: " << guest.salary.monthly << endl;
	cout << "Yearly Salary: " << guest.salary.yearly << endl;
	cout << "Gender: " << guest.gender << endl;
	cout << "Married: " << (guest.isMarried ? "Yes" : "No") << endl;
	cout << "**********************************" << endl;

}
int main() {
	

	Person guest;
	readData(guest);
	ShowInfo(guest);


	// second homework
	//cout << "\n\n\n\n" << endl;
	//int firstNum;
	//int secondNum; 
	//int thirdNum;

	//cout << "now i want you to enter three numbers to sum them :" << endl;
	//cout << "first one : " << endl;
	//cin >> firstNum;

	//cout << "second number: " << endl;
	//cin >> secondNum;
	//
	//cout << "third number: " << endl;
	//cin >> thirdNum;
	//
	//cout << "\n\n";
	//cout << firstNum << " + \n" ;
	//cout << secondNum << " + \n";
	//cout << thirdNum << "\n";
	//cout << "\n------------------\n\n";
	//cout << "Total = " << firstNum + secondNum + thirdNum;


	//// third homework 
	//cout << "\n\n\n\n";

	//cout << "enter your age to guess it after 5 years: " << endl;
	//unsigned short age;
	//cin >> age;
	//cout << "After 5 years you will be " << age + 5 << " years old." << endl;
	cout << "\a";
}