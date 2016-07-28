// Section_02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

int main() {


	PrintIntro();
	PlayGame();
	AskToPlayAgain();

	return 0;
}

void PrintIntro() {
	constexpr int WORD_LENGTH = 5;

	cout << "welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << endl << endl;
}

void PlayGame() {
	constexpr int NUMBER_OF_TURNS = 5;

	for (int it = 0; it < NUMBER_OF_TURNS; it++) {
		string Guess = GetGuess();

		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}
}

string GetGuess() {
	string guess = "";

	cout << "Enter your guess: ";
	getline(cin, guess);

	return guess;
}

bool AskToPlayAgain() {
	cout << "Do you want to play again? ";
	string Response = "";
	getline(cin, Response);

	cout << "Is it y? " << (Response[0] == 'y' || Response[0] == 'Y') << endl;

	return false;
}
