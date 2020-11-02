#include <iostream>

using namespace std;

int itSeats(int number);
int recSeats(int number);
int formSeats(int number);

int main()
{
    cout << itSeats(3) << endl;
    cout << recSeats(3) << endl;
    cout << formSeats(3);
}

int itSeats(int number)
{
    int numHands = 0;
    while (number > 0)
    {
        if (number % 2 == 0) // even seat for Neptunian
            numHands += 4;
        else                 // odd seat for Omicronian
            numHands += 3;
        
        number--;
    }

    return numHands;
}

int recSeats(int number) 
{
    // base case
    if (number == 1)
        return 3;

    // recursive case
    if (number % 2 == 0) // even seat for Neptunian
        return 4 + recSeats(number - 1);
    else                 // odd seat for Omicronian
        return 3 + recSeats(number - 1);
}

int formSeats(int number)
{
    if (number % 2 == 0)
        return (number / 2) * 4 + (number / 2) * 3;
    else
        return 3 + ((number - 1) / 2) * 4 + ((number - 1) / 2) * 3;
}
