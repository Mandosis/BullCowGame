// Section_02.cpp : Defines the entry point for the console application.
//

/** 
 * This is the console executable, that makes use of the BullCow class
 * this acts as the view in a MVC pattern, and is responsible for all
 * user interaction. For game logic see the FbullCowGame class.
 */

#include "stdafx.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h";

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame;

int main() 
{
	bool bPlayAgain = false;

	do {
		PrintIntro();
		PlayGame();

		// TODO add post game summary
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0;
}

void PrintIntro() 
{

	std::cout << "welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?" << std::endl << std::endl;
}

void PlayGame() 
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// TODO change from FOR to WHILE loop once tries are validated
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << "\n\n";

		std::cout << std::endl;
	}

	// TODO summarize game
}

FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			break;
		}

		std::cout << std::endl;

	} while (Status != EGuessStatus::OK);

	return Guess;
}

bool AskToPlayAgain() 
{
	PrintGameSummary();

	std::cout << "Do you want to play again with the same hidden word? (Y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}

void PrintGameSummary() {
	if (BCGame.IsGameWon())
	{
		std::cout << "You won!\n";
	}
	else
	{
		std::cout << "Better luck next time!\n";
	}
}
