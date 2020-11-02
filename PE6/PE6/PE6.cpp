#include <iostream>
#include <time.h>

using namespace std;

void generateRandom(int);
char* reverseString(char[]);

int main()
{
    char input[256];
    cout << "Please enter a string. I will reverse it for you." << endl;
    cin >> input;
    cout << reverseString(input);
}

void generateRandom(int numberOfRandoms)
{
    srand(time(NULL));
    int num;

    for (int i = 0; i < numberOfRandoms; i++)
    {
        num = rand();
        cout << "Random " << i + 1 << ": " << num << endl;
    }
}

/*
* This function does not work because newString is not having anything written to it 
* in line 42. Because of this, the return ends up being an empty character array
* and nothing is printed to the console. Setting a debug breakpoint after the
* reveserseString() call in main() reveals that input gets updated to an empty array.
*/
char* reverseString(char inputString[])
{
    char newString[256] = "";
    int length = strlen(inputString);
    for (int i = 0; i < length; i++)
    {
        char c = inputString[i];
        newString[length - i] = c;
    }
    strcpy_s(inputString, 128, newString);
    return inputString;
}