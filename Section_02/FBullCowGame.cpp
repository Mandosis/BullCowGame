#include "stdafx.h"
#include "FBullCowGame.h"

void FBullCowGame::Reset() {

}

int FBullCowGame::GetMaxTries() {
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() {
	return 0;
}

bool FBullCowGame::IsGameWon() {
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string) {
	return false;
}
