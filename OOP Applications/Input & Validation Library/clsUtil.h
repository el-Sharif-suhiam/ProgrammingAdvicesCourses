#pragma once
#include <iostream>
#include <cstdlib>
#include "clsDate.h"
using namespace std;

class clsUtil
{


public:
	static void Srand() {
		srand((unsigned)time(NULL));
	};
	static int RandomNumber(int From, int To)
	{
		//Function to generate a random number 
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	};
	static enum enCharType {
		SamallLetter = 1, CapitalLetter = 2,
		Digit = 3, SpecialCharacter = 4 ,MixChars =5
	};

	static char GetRandomCharacter(enCharType CharType)
	{
		if (CharType == MixChars) {
			CharType = (enCharType)RandomNumber(1, 3);
		}
		switch (CharType)
		{
		case enCharType::SamallLetter:
		{
			return char(RandomNumber(97, 122));
			break;
		}
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharType::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
		case enCharType::MixChars:
			return char(RandomNumber(48, 122));
		}
	}

	static string GenerateWord(enCharType CharType, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++)
		{
			Word = Word + GetRandomCharacter(CharType);
		}
		return Word;
	};

	static string GenerateKey(enCharType Chartype)
	{
		string Key = "";
		Key = GenerateWord(Chartype, 4) + "-";
		Key = Key + GenerateWord(Chartype, 4) + "-";
		Key = Key + GenerateWord(Chartype, 4) + "-";
		Key = Key + GenerateWord(Chartype, 4);
		return Key;
	}

	static void GenerateKeys(short NumberOfKeys, enCharType Chartype)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey(Chartype) << endl;
		}
	}

	// swap 
	static void Swap(int& A, int& B)
	{
		int Temp;
		Temp = A;
		A = B;
		B = Temp;
	};

	static void Swap(double& A, double& B) {
		double Temp;
		Temp = A;
		A = B;
		B = Temp;
	};

	static void Swap(clsDate& A, clsDate& B) {
		clsDate::SwapDates(A, B);
	};

	static void Swap(string& A, string& B) {
		string Temp;
		Temp = A;
		A = B;
		B = Temp;
	};


	static void ShuffleArray(int arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1],
				arr[RandomNumber(1, arrLength) - 1]);
		}
	};
	static void ShuffleArray(string arr[], int arrLength) {
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1],
				arr[RandomNumber(1, arrLength) - 1]);
		}
	};

	static void FillArrayWithRandomNumbers(int arr[], int arrLength, int from, int to)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(from, to);
	};

	static void FillArrayWithRandomWords(string arr[], int arrLength, enCharType charType, int wordLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(charType, wordLength);
	};

	static void FillArrayWithRandomKeys(string arr[], int arrLength, enCharType charType) {
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey(charType);
	};
	static string Tabs(short tabNum) {
		string tab = "";
		for (short i = 0; i < tabNum; i++)
			tab+= "\t";

		return tab;
	};
	

	static string EncryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	};

	static string DecryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	};
};

