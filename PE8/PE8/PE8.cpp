#include <iostream>

using namespace std;

void changeVariable(int);
void changePointer(int*);
int getLengthArray(int*);
int getLengthPointer(int[]);
int* createStackArray();
int* createHeapArray(int);

int main()
{
    int myVariable = 17;
    cout << "Inside main() - myVariable = " << myVariable << endl;
    changeVariable(myVariable);
    cout << "Inside main() - myVariable = " << myVariable << endl;
    changePointer(&myVariable);
    cout << "Inside main() - myVariable = " << myVariable << endl;

    const int MY_ARRAY_SIZE = 10;
    int myArray[MY_ARRAY_SIZE];
    for (int i = 0; i < MY_ARRAY_SIZE; i++)
        myArray[i] = i;
    myArray[MY_ARRAY_SIZE - 1] = -1;
    int* myArrayPointer = myArray;

    cout << "getLengthArray(myArrayPointer) returns " << getLengthArray(myArrayPointer) << endl;

    cout << "getLengthPointer(myArray) returns " << getLengthPointer(myArray) << endl;

    int* myStackPointer = createStackArray();
    int* myHeapPointer = createHeapArray(5);

    // arrays created in the stack only have their values saved within the scope of the function
    // outside the scope, nothing is stored in those memory locations.
    cout << "myStackPointer: ";
    for (int i = 0; i < 5; i++)
        cout << myStackPointer[i] << ", ";
    cout << endl;

    // arrays created in the heap have their values saved regardless of scope
    // values stored in createHeapArray() can still be read in main()
    cout << "myHeapPointer: ";
    for (int i = 0; i < 5; i++)
        cout << myHeapPointer[i] << ", ";
    cout << endl;

    delete[] myHeapPointer;
    myHeapPointer = nullptr;
}

// changeVariable() alters an integer that is passed by value
// the value only gets changed in the scope of the function and is not updated in main()
void changeVariable(int myVariable)
{
    myVariable = 7;
    cout << "Inside changeVariable() - myVariable = " << myVariable << endl;
}

// changePointer() alters an integer that is passed by reference
// the value gets changed at the memory location so it is updated in main()
void changePointer(int* myPointer)
{
    *myPointer = 33;
    cout << "Inside changePointer() - the data stored at myPointer's memory location = " << *myPointer << endl;
}

int getLengthArray(int myArray[])
{
    int count = 0;
    while (*myArray != -1)
    {
        myArray++;
        count++;
    }

    return count;
}

int getLengthPointer(int* myPointer)
{
    int count = 0;
    while (*myPointer != -1)
    {
        myPointer++;
        count++;
    }

    return count;
}

int* createStackArray()
{
    int myArray[5];
    for (int i = 0; i < 5; i++)
        myArray[i] = i;
    return myArray;
}

int* createHeapArray(int arraySize)
{
    int* myArray = new int[arraySize] {};
    for (int i = 0; i < arraySize; i++)
        myArray[i] = i;
    return myArray;
}