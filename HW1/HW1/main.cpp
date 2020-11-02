#include <iostream>
#include <string>
#include "hangman.h"

using namespace std;

int main() 
{
	const int GUESS_SIZE = 26;
	char guesses[GUESS_SIZE];
	char guess = 'a';
	const int WORD_SIZE = 12;
	char word[WORD_SIZE] = "exclamation";
	int numGuesses = 0;
	int remGuesses = 7;

	cout << "Welcome to the game!\nYour word has " << WORD_SIZE - 1 << " letters in it.\n\n";
	showGallows(remGuesses);

	// loops until player has 0 guesses left or solves the word
	// remGuesses = 8 when word is solved -- showSolveDisplay returns -1
	while (remGuesses > 0 && remGuesses < 8)
	{
		inputGuess(guess, guesses, numGuesses, GUESS_SIZE);
		numGuesses++;
		remGuesses = 7 - showSolveDisplay(word, WORD_SIZE, guesses, GUESS_SIZE);
		showGallows(remGuesses);
	}
	if (remGuesses != 0)
		cout << "\n\nCongratulations! You solved the word!" << endl;
}