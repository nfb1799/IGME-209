/*  Nik Barbero
*   Section 01
*   Exam 1
*/

#include <iostream>

using namespace std;

void AverageScore(float*, int);
void HighScore(float*, int);
void LowScore(float*, int);

int main()
{
    int numberOfScores;

    //Asks the user for the size of the float array
    cout << "Enter the number of scores to use: ";
    cin >> numberOfScores;

    float* scores = new float[numberOfScores]; //Creates a float array on the heap of specified size
    
    //Asks the user to enter each float value into the array
    for (int i = 0; i < numberOfScores; i++)
    {
        cout << "Enter a score: ";
        cin >> scores[i];
    }

    //Prints the average score
    AverageScore(scores, numberOfScores);

    //Prints the high score
    HighScore(scores, numberOfScores);

    //Prints the low score
    LowScore(scores, numberOfScores);

    //Deletes the array from the heap and reassigns the pointer to nullptr
    delete[] scores;
    scores = nullptr;
   
}

//Sorts through a user's array and prints out the average value
void AverageScore(float* scores, int countScores)
{
    float sum = 0;
    for (int i = 0; i < countScores; i++)
    {
        sum += scores[i]; //Creates a running sum of each value in the array
    }
    cout << "Average Score is " << sum / countScores << endl;
}

//Sorts through a user's array and prints out the highest value
void HighScore(float* scores, int countScores)
{
    float highScore = scores[0];
    for (int i = 0; i < countScores; i++)
    {
        //If the current score is higher than the highest update the high score
        if (scores[i] > highScore)
            highScore = scores[i];
    }
    cout << "High Score is " << highScore << endl;
}

//Sorts through a user's array and prints out the lowest value
void LowScore(float* scores, int countScores)
{
    float lowScore = scores[0];
    for (int i = 0; i < countScores; i++)
    {
        //If the current score is lower than the lowest update the low score
        if (scores[i] < lowScore)
            lowScore = scores[i];
    }
    cout << "Low Score is " << lowScore << endl;
}