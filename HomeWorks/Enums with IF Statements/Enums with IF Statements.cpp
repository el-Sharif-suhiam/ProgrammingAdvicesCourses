
#include <iostream>
#include <string>

using namespace std;

enum enColors { red = 1, blue, yellow, green };
enum enCountryChoice { Jorden =1, Libya, Algeria, Oman, Egypt, Iraq, Other};

void changeColor() {

	cout << "******************************\n";
	cout << "Please chose the number of your color? \n";
	cout << "(1) Red\n";
	cout << "(2) Blue\n";
	cout << "(3) Green\n";
	cout << "(4) Yellow\n";
	cout << "********************************************\n\n";
	cout << "Your Choice? " << endl;
	short x;
	cin >> x;
	short color = (enColors)x;
	switch (color) {
	case enColors::blue:
		system("color 1F");

		break;
	case enColors::green:
		system("color 6F");

		break;
	case enColors::red:
		system("color 4F");

		break;
	case enColors::yellow:
		system("color 2F");

		break;

	default:
		system("color 9F");

		break;

	}
	//
	//	if (color == enColors::red) {
	//		system("color 4F");
	//	}
	//	else if (color == enColors::blue) {
	//		system("color 1F");
	//
	//	}
	//	else if (color == enColors::yellow) {
	//		system("color 2F");
	//
	//	}
	//	else if (color == enColors::green) {
	//		system("color 6F");
	//
	//	}
	//	else {
	//		system("color 9F");
	//
	//	}
	//}
}

void chooseCountry() {

	cout << "******************************\n";
	cout << "Please choose the number of your country? \n";
	cout << "(1) Jordan\n";
	cout << "(2) Libya\n";
	cout << "(3) Algeria\n";
	cout << "(4) Oman\n";
	cout << "(5) Egypt\n";
	cout << "(6) Iraq\n";
	cout << "(7) Other\n";

	cout << "********************************************\n\n";
	cout << "Your Choice? " << endl;

	short userInput;
	enCountryChoice country;
	cin >> userInput;
	country = (enCountryChoice)userInput;

	switch (country)
	{
	case Jorden:
		cout << "Your Country is Jorden." << endl;
		break;
	case Libya:
		cout << "Your Country is Libya." << endl;
		break;
	case Algeria:
		cout << "Your Country is Algeria." << endl;
		break;
	case Oman:
		cout << "Your Country is Oman." << endl;
		break;
	case Egypt:
		cout << "Your Country is Egypt." << endl;
		break;
	case Iraq:
		cout << "Your Country is Iraq." << endl;
		break;
	case Other:
		cout << "Your Country is Other." << endl;
		break;
	default:
		cout << "Your Country is unknown." << endl;
		break;
	}

	/*if (country == enCountryChoice::Jorden) {
		cout << "Your Country is Jorden." << endl;
	}
	else if (country == enCountryChoice::Algeria) {
		cout << "Your Country is Algeria." << endl;

	}
	else if (country == enCountryChoice::Egypt) {
		cout << "Your Country is Egypt." << endl;

	}
	else if (country == enCountryChoice::Iraq) {
		cout << "Your Country is Iraq." << endl;

	}
	else if (country == enCountryChoice::Libya) {
		cout << "Your Country is Libya." << endl;

	}
	else if (country == enCountryChoice::Oman) {
		cout << "Your Country is Oman." << endl;

	}
	else if (country == enCountryChoice::Other) {
		cout << "Your Country is Other." << endl;

	}
	else {
		cout << "Your Country is unknown." << endl;

	}*/
}
int main()
{
	changeColor();
	//chooseCountry();
}
