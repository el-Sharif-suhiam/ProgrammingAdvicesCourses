
#include <iostream>
#include <cmath>
#include <string>

using namespace std;


int ReadPostitiveNumber(string msg) {
	int number;
	do {
		cout << msg << endl;
		cin >> number;
	} while (number <= 0);
	return number;
}


// #1
void printName(string name) {
	cout << "Your name is : " << name << "\n";

}

// #2
string readName() {
	string name;

	cout << "Enter your name ? \n";
	cin >> name;

	return name;
}

// #3

enum stNumberType {odd = 1, even};

int readNumber() {
	int num;
	cout << "Enter the number ?\n";
	cin >> num;
	return num;
}
stNumberType checkNumberType(int num) {
	if (num % 2 == 0)
		return stNumberType::even;
	else
		return stNumberType::odd;
}

void printNumberType(stNumberType n) {
	if (n == stNumberType::even) {
		cout << "your number is even \n";
	}
	else {
		cout << "your number is odd \n";
	}
}

// #4

struct stUserInfo {
	short age;
	bool hasDrivingLicence;
	// #5
	bool hasRecommendation;
};

stUserInfo readInfo() {
	stUserInfo user;
	cout << "Enter your age ?\n";
	cin >> user.age;
	cout << "\nDo you have a driving licence? \n";
	cin >> user.hasDrivingLicence;
	// #5
	cout << "Do you have recommendation ? \n";
	cin >> user.hasRecommendation;

	return user;
}

bool isAccepted(stUserInfo info) {
	// #5
	if (info.hasRecommendation) {
		return true;
	}
	else {
		return (info.age > 21 && info.hasDrivingLicence);
	}
}

void isHired(stUserInfo info) {
	if (isAccepted(info)) {
		cout << "You are Hired \n";
	}
	else {
		cout << "You have been rejected. \n";
	}
}

// #6
struct stName {
	string firstName;
	string LastName;
};

stName readFullName() {
	stName userName;
	cout << "Enter your first name ? \n";
	cin >> userName.firstName;
	cout << "Enter your last name ? \n";
	cin >> userName.LastName;

	return userName;
}
string getFullName(stName name, bool reversed) {
	string fullName = "";
	if(reversed)
		fullName = name.LastName + " " + name.firstName;
	else
		fullName = name.firstName + " " + name.LastName;
	
	return fullName;
}

void printFullName(string fullName) {
	cout << "Your name is : " << fullName << endl;
}

// #7
float calcHalfNum(int num) {
	return (float)num / 2;
}

void PrintHalfNum(int num) {
	string Result = "Half of " + to_string(num) + " is " + to_string(calcHalfNum(num));
	cout << endl << Result << endl;
}

// #8
enum enPassFail {pass = 1, fail};

int readMark() {
	int mark;
	cout << "Enter your mark? \n";
	cin >> mark;

	return mark;
}

enPassFail checkMark(int mark) {
	if (mark >= 50)
		return enPassFail::pass;
	else
		return enPassFail::fail;
}

void printMarkResult(int mark) {
	if (checkMark(mark) == enPassFail::pass)
		cout << "you have pass the test!\n";
	else
		cout << "you have failed!!\n";
}

// #9
void readThreeNumbers(int &num1,int &num2, int &num3) {
	cout << "enter num 1 ?\n";
	cin >> num1;
	cout << "enter num 2 ?\n";
	cin >> num2;
	cout << "enter num 3 ?\n";
	cin >> num3;

}

int sumThreeNums(int num1, int num2, int num3) {
	return num1 + num2 + num3;
}
void printSumResult(int total) {
	cout << "the result is : " << total << endl;
}

// #10
float calcAverage(int num1, int num2, int num3) {
	return (float)sumThreeNums(num1,num2,num3) / 3;
}
// #11
void readThreeMarks(int& num1, int& num2, int& num3) {
	cout << "enter mark 1 ?\n";
	cin >> num1;
	cout << "enter mark 2 ?\n";
	cin >> num2;
	cout << "enter mark 3 ?\n";
	cin >> num3;

}
enPassFail checkAverage(float avg) {
	if (avg >= 50)
		return enPassFail::pass;
	else
		return enPassFail::fail;
}
void printAvgResult(float avg) {
	cout << "Your average is : " << avg << endl;
	if (checkAverage(avg) == enPassFail::pass)
		cout << "you pass \n";
	else
		cout << "you fail \n";
}

// #12
void read2Numbers(int& num1, int& num2) {
	cout << "enter number 1 ?\n";
	cin >> num1;   
	cout << "enter number 2 ?\n";
	cin >> num2;
	

}
int maxOf2numbers(int num1, int num2) {
	if (num1 > num2)
		return num1;
	else
		return num2;
}
void printResult(int num) {
	cout << "result is: " << num << "\n\n";
}

// #13
int maxOf3numbers(int num1, int num2, int num3) {
	if (num1 > num2) {
		if (num1 > num3)
			return num1;
		else
			return num3;
	}
	else {
		if (num2 > num3)
			return num2;
		else
			return num3;
	}
}

// #14
void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
void printNums(int x, int y) {
	cout << "first Num is: " << x << "\n";
	cout << "second Num is: " << y << "\n\n";
}

// #16

float calcRectangleArea(int a, int b) {
	float area = float(a * sqrt(pow(b, 2) - pow(a, 2)));
	return area;
};

void printArea(float area,string shape) {
	cout << "The Area of " << shape << " is: " << area << endl;
}

// #17
float calcTriangleArea(int a, int h) {
	float area = float((a / 2) * h);
	return area;
}

// #18
float calcCircleArea(int r , float Pi) {
	float area = float(Pi * pow(r, 2));
	return area;
}

// #19
float calcCircleAreaByDiameter(int D, float Pi) {
	float area = float((Pi * pow(D, 2))/4);
	return area;
}


// #25
int readAge() {
	short age;
	cout << "Enter your age ? \n";
	cin >> age;
	return age;
}

bool validateNumberInRange(int from, int to, int num) {
	
	return (num >= from && num <= to);
}

int readUntilAgeBetween(int from, int to) {
	short age = 0;
	do {
		age = readAge();
	} while (!validateNumberInRange(from, to, age));
	return age;
}

void printAge(int Age) {
	cout << "Your Age is : " << Age << endl;
}

// #26 
void print1ToN(int num) {
	for (int i = 1; i <= num ; i++) {
		cout << i << '\n';
	}
}

// #27

int sumOddNum(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i += 2) {
		sum += i;
	}
	return sum;
}

// PIN

string readPINCode() {
	string pin;
	cout << "Enter your pin code: \n";
	cin >> pin;
	return pin;
}

bool LogIn() {
	string pincode;
	short tries = 3;
	do {
		tries--;
		pincode = readPINCode();
		if (pincode == "1234") {
			return 1;
		}
		else {
			cout << "\nWrong PIN you have " << tries << " more tries \n";
			system("color 4F");
		}
	} while (tries >= 1&& pincode != "1234" );
	return 0;
}
int main()
{
  
	// #1
	//printName("Alshrif");
	
	// #2
	//printName(readName());

	//#3
	//printNumberType(checkNumberType(readNumber()));

	//#4 && #5
	//isHired(readInfo());
	
	// #6
	//printFullName(getFullName(readFullName(),true));

	// #7
	//PrintHalfNum(readNumber());

	//#8
	//printMarkResult(readMark());
	
	//#9
	int num1, num2, num3;
	//readThreeNumbers(num1, num2, num3);
	/*printSumResult(sumThreeNums(num1, num2, num3));*/
	
	// #10
	//printSumResult(calcAverage(num1, num2, num3));

	// #11
	//readThreeMarks(num1, num2, num3);
	//printAvgResult(calcAverage(num1, num2, num3));
	
	// #12
	/*read2Numbers(num1, num2);
	printResult(maxOf2numbers(num1, num2));*/

	// #13
	/*readThreeNumbers(num1, num2, num3);
	printResult(maxOf3numbers(num1, num2, num3));*/

	// #14
	//read2Numbers(num1, num2);
	//printNums(num1, num2);
	//swap(num1, num2);
	//printNums(num1, num2);

	// #16
	/*cout << "program to calculate rectangle area through diagonal and side area : \n";
	read2Numbers(num1, num2);
	printArea(calcRectangleArea(num1, num2), "rectangle");*/

	// #17
	/*cout << "program to calculate Triangle area : \n";
	read2Numbers(num1, num2);
	printArea(calcTriangleArea(num1, num2), "triangle");*/

	// #18
	/*cout << "program to calculate Circle area : \n";
	printArea(calcCircleArea(readNumber(),3.141592653),"circle");*/

	// #19
	/*cout << "program to calculate Circle area with Diameter : \n";
	printArea(calcCircleAreaByDiameter(readNumber(), 3.141592653), "circle");*/

	// #20 same as before

	// #25
	//printAge(readUntilAgeBetween(18, 55));
	

	//#26
	//cout << "from 1 to number you choose : " << endl;
	//print1ToN(readNumber());


	// #28
	//printResult(sumOddNum(ReadPostitiveNumber("sum the odd numbers from 1 to n ")));
	
	
	
	if (LogIn()) {
		system("color 2F");
		cout << "\nYour Account Balance is " << 7500 << "\n";
	}
	else {
		cout << "\nYour card blocked call the bank for help. \n";
	}
	
	return 0;
}