// Section_02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h";

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

int main() {
	bool bPlayAgain = false;

	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0;
}

void PrintIntro() {
	constexpr int WORD_LENGTH = 5;

	std::cout << "welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl << std::endl;
}

void PlayGame() {
	FBullCowGame BCGame;
	constexpr int NUMBER_OF_TURNS = 5;

	for (int it = 0; it < NUMBER_OF_TURNS; it++) {
		std::string Guess = GetGuess();

		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess() {
	std::string guess = "";

	std::cout << "Enter your guess: ";
	std::getline(std::cin, guess);

	return guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? (Y/n) ";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}
