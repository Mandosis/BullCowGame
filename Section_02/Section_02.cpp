// Section_02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void printIntro();
string getGuessAndPrintBack();

int main() {

	constexpr int NUMBER_OF_TURNS = 5;

	printIntro();

	for (int it = 0; it < NUMBER_OF_TURNS; it++) {
		getGuessAndPrintBack();
		cout << endl;
	}

	return 0;
}

void printIntro() {
	constexpr int WORD_LENGTH = 5;

	cout << "welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << endl << endl;
}

string getGuessAndPrintBack() {
	string guess = "";

	cout << "Enter your guess: ";
	getline(cin, guess);

	cout << "Your guess was: " << guess << endl;

	return guess;
}