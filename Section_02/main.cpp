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

FBullCowGame BCGame;

int main() {
	bool bPlayAgain = false;

	do {
		PrintIntro();
		PlayGame();

		// TODO add post game summary
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
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();

	// TODO change from FOR to WHILE loop once tries are validated
	for (int it = 0; it < MaxTries; it++) {
		std::string Guess = GetGuess(); // TODO check if guess is valid

		// submit valid guess to the game
		// print number of bulls and cows
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

	// TODO summarize game
}

std::string GetGuess() {
	int CurrentTry = BCGame.GetCurrentTry();
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

// Test comment