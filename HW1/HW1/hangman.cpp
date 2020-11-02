#include <iostream>
#include <cstring>
#include "hangman.h"

using namespace std;

// Displays the hangman ASCII Depending
// on how many guesses are remaining
void showGallows(int guessesRemaining)
{
	switch (guessesRemaining) 
	{
		case 7:
			cout << "\t______" << endl;
			cout << "\t|" << endl;
			cout << "\t|" << endl;
			cout << "\t|" << endl;
			cout << "\t|\n" << endl;
			break;
		case 6:
			cout << "\t______" << endl;
			cout << "\t|  |" << endl;
			cout << "\t|" << endl;
			cout << "\t|" << endl;
			cout << "\t|\n" << endl;
			break;
		case 5:
			cout << "\t______" << endl;
			cout << "\t|  |" << endl;
			cout << "\t|  o" << endl;
			cout << "\t|" << endl;
			cout << "\t|\n" << endl;
			break;
		case 4:
			cout << "\t______" << endl;
			cout << "\t|  |" << endl;
			cout << "\t|  o" << endl;
			cout << "\t|  |" << endl;
			cout << "\t|\n" << endl;
			break;
		case 3:
			cout << "\t______" << endl;
			cout << "\t|  |" << endl;
			cout << "\t|  o" << endl;
			cout << "\t| /|" << endl;
			cout << "\t|\n" << endl;
			break;
		case 2: 
			cout << "\t______" << endl;
			cout << "\t|  |" << endl;
			cout << "\t|  o" << endl;
			cout << "\t| /|\\" << endl;
			cout << "\t|\n" << endl;
			break;
		case 1: 
			cout << "\t______" << endl;
			cout << "\t|  |" << endl;
			cout << "\t|  o" << endl;
			cout << "\t| /|\\" << endl;
			cout << "\t| /\n" << endl;
			break;
		case 0:
			cout << "\t______" << endl;
			cout << "\t|  |" << endl;
			cout << "\t|  o" << endl;
			cout << "\t| /|\\" << endl;
			cout << "\t| / \\\n" << endl;
			cout << "Game Over! The word was \'exclamation\'" << endl;
			break;
	}
}

// Prints the correct and incorrect guesses
int showSolveDisplay(char word[], const int W_SIZE, char guess[], const int G_SIZE)
{
	bool wordMatch[11] = { false }; // boolean array to track which letters of the word have been guessed
	bool gCheck = false; // boolean to check the validity of the current guess
	bool playing = true; // becomes false when the word has been solved or the player loses
	char badGuess[26]; // array that stores incorrect guesses
	int badCount = 0; // tracks the number of incorrect guesses
	
	// Fills the array with false values
	for (int i = 0; i < W_SIZE - 1; i++)
		wordMatch[i] = false;
	
	// Compares each guess with every letter in the word and stores the truth value
	for (int y = 0; y < G_SIZE; y++)
	{
		for (int x = 0; x < W_SIZE; x++)
		{
			if (guess[y] == word[x]) 
			{
				wordMatch[x] = true;
				gCheck = true;
			}
		}

		// if its an incorrect guess and a lower case char
		// store incorrect guess and increment count
		if (!gCheck && (guess[y] > 60 && guess[y] < 123)) 
		{
			badGuess[badCount] = guess[y];
			badCount++;
		}
		gCheck = false;
	}


	// Displays the wrong guesses
	cout << "Wrong guesses: ";
	cout << badCount << " [";
	for (int k = 0; k < badCount; k++)
	{
		cout << badGuess[k];
	}
	cout << "]" << endl;

	// displays the correctly guessed letters
	// exits the function when the word is completed
	playing = false;
	cout << "Word to solve: ";
	for (int m = 0; m < W_SIZE; m++)
	{
		if (wordMatch[m]) 
		{
			cout << word[m];
		}
		else
		{
			cout << "_";
			playing = true; // always playing until the word is solved
		}
	}
	if (!playing)
		return -1;

	cout << endl;
	return badCount;
}

void inputGuess(char guess, char* guesses, int gCount, const int G_SIZE)
{
	bool guessing = true;
	bool badGuess = false;

	// keeps the user in a loop to protect against repeated guesses
	while (guessing) 
	{
		guessing = false;
		badGuess = false;
		cout << "What letter do you guess next? ";
		cin >> guess;
		for (int i = 0; i < G_SIZE; i++) 
		{
			if (guess == guesses[i])
				badGuess = true;
		}
		if (badGuess) 
		{
			cout << "\'" << guess << "\'" << " has already been guessed." << endl;
			guessing = true;
		}
			
	}
	
	// displays the users' guess and increments the number of guesses
	cout << "Guess: " << guess << endl;
	guesses[gCount] = guess;
	gCount++;
}