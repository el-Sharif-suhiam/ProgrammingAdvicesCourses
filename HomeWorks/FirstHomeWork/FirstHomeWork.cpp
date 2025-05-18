#include <iostream>
using namespace std ;

void displayMyCard() {
	cout << "****************************" << endl;
	cout << "Name: Alshrif Fraj Suhaim \n";
	cout << "Age: 27\n";
	cout << "City: Brega\n";
	cout << "Country: Libya.\n";
	cout << "****************************" << endl;
}

void squirStars() {
	cout << "***************\n";
	cout << "***************\n"; 
	cout << "***************\n";
	cout << "***************\n";
}

void about() {
	cout << "I Love Programming!\n" << endl;
	cout << "I Promise to be the best developer ever!\n" << endl;
	cout << "I know it will take some time to practice, but I\n will achieve my goal.\n" << endl;
	cout << "Best Regards.\n" << "Alsharif Suhaim" << endl;

}

void Hmsg()
{
	cout << "*          *\n*          *\n*          *\n*          *\n*          *\n************\n*          *\n*          *\n*          *\n*          *\n*          *\n";

}
int main() {
	
	displayMyCard();
	cout << "\n\n\n\n";
	cout << "Number 2: \n";
	squirStars();
	cout << "\n\n\n\n";
	cout << "Number 3: \n";
	about();
	cout << "\n\n\n\n";
	cout << "Number 4: \n \n";
	Hmsg();
	unsigned short num = 333;
	float fot = 10.54E12;
	cout << num << endl;
	cout << fot << endl;
	cout << sizeof(short);
	return 0;
}