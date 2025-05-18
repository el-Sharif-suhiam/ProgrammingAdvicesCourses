

#include <iostream>
#include <string>
using namespace std;


struct stPerson {
	string firstName;
	string lastName;
	unsigned short age;
	unsigned long int phone;
};

void readOnePerson(stPerson &person) {
	cout << "Enter your first name ? \n";
	cin >> person.firstName;
	cout << "Enter your last name ? \n";
	cin >> person.lastName;
	cout << "Enter your age ? \n";
	cin >> person.age;
	cout << "Enter your phone Number ? \n";
	cin >> person.phone;
}

void readAll(stPerson persons[100], short &length) {
	cout << "enter the number of users that you want to add? from 1 to 100\n";
	cin >> length;
	for (short i = 0; i < length; i++) {
		cout << "Person " << i +1 << " Info:" << endl;
		readOnePerson(persons[i]);
		
	}
};

void printData(stPerson &person) {
	cout << "***********************\n";
	cout << "First Name: " << person.firstName << endl;
	cout << "Last Name: " << person.lastName << endl;
	cout << "Age: " << person.age << endl;
	cout << "Phone Number: " << person.phone << endl;
	cout << "***********************" << endl;
}

void printAll(stPerson persons[100], short length) {
	for (short i = 0; i < length; i++) {
		printData(persons[i]);
	}
}


void ReadGrades(float grades[3]) {

	cout << "Please enter the Grade1 ? " << endl;
	cin >> grades[0];

	cout << "Please enter the Grade2 ? " << endl;
	cin >> grades[1];

	cout << "Please enter the Grade3 ? " << endl;
	cin >> grades[2];

	cout << "*************************************\n";
}

float avg(float x[3]) {
	return (x[0] + x[1] + x[2]) / 3;
}

void printAvg(float avg) {
	cout << "The average of grades is " << avg << endl;
}




int main()
{

	stPerson users[100];
	short length;
	readAll(users,length);
	printAll(users,length);
	//unsigned short test[2];
	//float grades[6];
	//ReadGrades(grades);
	//printAvg(avg(grades));
	//cout << test[6];

}
