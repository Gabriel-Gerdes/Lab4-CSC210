// BubbleExampleA.cpp
// bubble sort example using an array implementation
// optimization through the use of a bool "swapped" variable
// source:  StackOverflow.com
// Modified by Jeff Goldstein 11/09/2017

#include <iostream>

using namespace std;

void printArray(int[]);		// prototypes go here
void bubbleSort(int[]);
bool swap(int &, int &);

const int SIZE = 10;		// global constant for size of the array

int main()
{
	int array[]  = {3, 8, 6, 1, 0, 2, 9, 5, 7, 4};

    cout << "The unsorted original array in Example A: " << endl;
    printArray(array);
	bubbleSort(array);

	return 0;
}

void bubbleSort(int array[])
{
    int tests = 0;                           // counts the number of tests done
    int numSwaps = 0;                        // counts the number of actual swaps
	int temp  = 0;
	bool swapped = true;      				 // assume exchanges will happen

	cout << "\nStart sorting the data:" << endl;
	for(int i = 0; i < SIZE && swapped; i++) // outer loop
	{
	    swapped = false;					 //   reset the flag for no exchanges
    	for(int j = 0; j < SIZE - 1; j++)    //   inner loop
		{
 	       	if(array[j] > array[j + 1])		 //     if current element bigger than next
			{
           		swapped = swap(array[j], array[j+1]); //  swap just happened.  set a flag
           		numSwaps++;                  //       increment the number of swaps
        	}
            tests++;                         //       add 1 to tests even if not swapped
    	}
    	printArray(array);					 // show the current array progress
	}
   	cout << " Number of Swaps:  " << numSwaps << endl;
   	cout << " Number of Tests:  " << tests    << endl;
   	cout << " Total operations: " << tests + numSwaps << endl;
}

bool swap(int & a, int & b)
{
    int temp = a;    	//  store a to temp
    a = b; 	            //  assign b to a
    b = temp;           //  re-assign b
    return true;
}

void printArray(int arr[])
{
	for(int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "   ";
	}
	cout << endl;
	cout << "-------------------------------------" << endl;
}
