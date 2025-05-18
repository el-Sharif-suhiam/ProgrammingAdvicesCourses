
#include <iostream>
using namespace std;


void rangeFunc(int from, int to) {
	int num;
	cout << "enter number from " << from << " to " << to << " : \n";
	cin >> num;

	while (num < from || num > to) {
		cout << "wrong number try again: \n";
		cin >> num;
	}
	cout << "correct number \n";
}

// #26 
int getUsernumber() {
	int n;
	cout << "please enter N ?\n";
	cin >> n;
	return n;
}

void printN(int N) {

	int i = 1;
	while (i <= N) {
		cout << i << endl;
		i++;
	}
}

// #27
void printReversN(int N) {
	int i = N;
	while (i >= 1) {
		cout << i << endl;
		i--;
	}
}

// #28
int sumOddNums(int N) {
	int sum = 0, i = 1;
	while (i <= N) {
		sum += i;
		i += 2;
	}
	return sum;
}

// #29

int sumEvenNums(int N) {
	int sum = 0, i = 0;
	while (i <= N) {
		sum += i;
		i += 2;
	}
	return sum;
}

// #30
int getPositiveNumber() {
	int n;
	cout << "please enter positive number ?\n";
	cin >> n;
	while (n < 0) {
		cout << "wrong number , please enter a positive one ?\n";
		cin >> n;
	}
	return n;
}

int FactorialOfN(int N) {
	
		int fact = 1, i = N;
		while (i >= 1) {
			fact *= i;
			i--;
		}
		return fact;
	
}

int powerOfM(int M,int N) {
	int i = 0, P = 1;
	while (i != N) {
		P *= M;
		i++;
	}
	return P;
}

int SumUntil99() {
	int num, sum = 0;
	cout << "enter numbers to sum , and when you finish enter -99: \n";
	cin >> num;
	while (num != -99) {
		sum += num;
		cin >> num;
	}
	return sum;
}

void fromAtoZ() {
	short i = 65;
	while (i <= 90) {
		cout << char(i) << "\n";
		i++;
	}
}

void atm() {
	int balance = 7500, rightPIN = 1234, n, i =0;
	do {
		cout << "enter your pin code?\n";
		cin >> n;
		if (n == rightPIN) {
			cout << "Your Balance is: " << balance << endl;
			break;
		}
		cout << "wrong pin try again, you still have " << 3 - i << " try \n";
		i++;

	} while (i < 3);
	/*cout << "enter your pin code?\n";
	cin >> n;

	if (n == rightPIN) {
		cout << "Your Balance is: " << balance << endl;
	}
	else {
		while (i < 3) {
			cout << "wrong pin try again, you still have " << 3 - i << " try \n";
			cin >> n;
			if (n == rightPIN) {
				cout << "Your Balance is: " << balance << endl;
				break;
			}
				i++;
		}*/
		if (n !=  rightPIN && i == 3) {
			cout << "your card has been rejected;\n";
		}
	
}

int range(int from, int to) {
	int num;
	do {
		cout << "enter number from " << from << " to " << to << endl;
		cin >> num;
	} while (num < from || num > to);
	return num;
}


// break homework

void find20() {
	int arr[10] = {10,20,44,55,33,22,99,88,99,100};
	short i = 0;
	while(i < 10) {
		if (arr[i] == 20) {
			break;
		}
		i++;
	};
	cout << "20 position is: " << i << endl;
}
int sumNums() {
	short i = 0, sum = 0 , n;
	do {
		cout << "enter the number ? " << endl;
		cin >> n;
		if (n > 50) {
			continue;
		}
		sum += n;
		i++;
	}while(i < 5)
}
int main()
{
   /*
	short i = 1;
	while (i <= 5) {
		cout << i << endl;
		i++;
	}*/


	/*int number;
	cout << "please enter positive number ?\n";
	cin >> number;
	while (number < 0)
	{
		cout << "wrong number, enter positive number again ?\n";
		cin >> number;
	}

	cout << "you entered right number, your number is " << number << endl;*/

	//rangeFunc(18, 60);


	// #26
	/*cout << "This program is to print numbers from 1 to N\n";
	printN(getUsernumber());*/

	// #27
	/*cout << "This program is to print numbers from N to 1\n";
	printReversN(getUsernumber());*/

	//// #28 
	/*cout << "This program is to Print Sum Odd Numbers from 1 to N\n";
	cout << "The result is: " << sumOddNums(getUsernumber()) << endl;*/

	//// #29
	/*cout << "This program is to Print Sum Even Numbers from 1 to N\n";
	cout << "The result is: " << sumEvenNums(getUsernumber()) << endl;*/

	////#30
	/*cout << "This program is to Print Factorial of N!\n";
	cout << "The result is: " << FactorialOfN(getPositiveNumber()) << endl;*/

	// #32
	//cout << "This program is to Print Power of M\n";
	//cout << "The result is: " << powerOfM(2,getPositiveNumber()) << endl;
	
	// #37
	//cout << "result " << SumUntil99() << endl;

	// #46
	//fromAtoZ();

	// #50
	atm();

	//cout << "result : " << range(18, 50) << endl;
	//find20();
}