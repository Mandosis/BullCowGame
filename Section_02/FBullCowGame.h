#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame(); // Constructor
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make a rich return value
	bool CheckGuessValidity(std::string);
	// provide a method for counting bulls & cows, and increasing turn #
private:
	// See constructor for initialization
	int MyCurrentTry;
	int MyMaxTries;
};