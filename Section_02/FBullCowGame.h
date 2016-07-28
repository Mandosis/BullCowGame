#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset(); // TODO make a rich return value
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string);
private:
	int MyCurrentTry;
	int MyMaxTries = 5;
};