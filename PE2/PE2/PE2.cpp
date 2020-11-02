#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int seconds = 31 * 24 * 60 * 60;
    double area = 3.14159 * 3.1 * 3.1;
    int division = 3 / 2;

    cout << "Hello World!\n";
    printf("Seconds in December: %i\n", seconds);
    printf("Area of Circle: %f\n", area);
    printf("3 / 2 produces: %i\n", division);
    cout << "Integer division truncates.\n";

}
