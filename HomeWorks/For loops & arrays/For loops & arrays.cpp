#include <iostream>
#include <string>
using namespace std;

void ReadArray(short array[100], short& length) {
	cout << "How many numbers do you want to enter? 1 to 100?\n";
	cin >> length;

	for (short i = 0; i < length; i++) {
		cout << "Enter the Number " << i +1 << endl;
		cin >> array[i];
	}
}

void PrintArray(short array[100], short& length) {
	for (short i = 0; i < length; i++) {
		cout << "Number [" << i + 1 << "]" << " : " << array[i] << endl;
	}
}
int calculateSum(short array[100], short& length) {
	int sum = 0;
	for (short i = 0; i < length; i++) {
		sum += array[i];
	}
	return sum;
}
float calcAverage(short array[100], short& length) {
	int sum = 0;
	for (short i = 0; i < length; i++) {
		sum += array[i];
	}
	return float(sum) / float(length);
}

int main()
{
	short array[100], length;
	ReadArray(array,length);

	PrintArray(array, length);

	cout << "\n***************************\n";

	cout << "Sum = " << calculateSum(array, length) << endl;
	cout << "Average = " << calcAverage(array, length) << endl;


}
