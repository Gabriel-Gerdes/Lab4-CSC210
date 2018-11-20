// BubbleExampleNonOptimum.cpp (descending order)
// bubble sort example using an array implementation
// no optimization; n squared order of operations
// source:  StackOverflow.com
// Modified by Jeff Goldstein

#include <iostream>

using namespace std;

void printArray(int[]);		// prototypes go here
void bubbleSort(int[]);

const int SIZE = 10;		// global constant for size of the array

int main()
{
	int array[]  = {3, 8, 6, 1, 0, 2, 9, 5, 7, 4};

    cout << "The unsorted original array (non-optimum): " << endl;
	printArray(array);
	cout << "\nStart sorting the data (descending):" << endl;
	bubbleSort(array);

	return 0;
}

void bubbleSort(int array[])
{
    int tests = 0;                          // counts the number of tests done
    int numSwaps = 0;                       // counts the number of actual swaps
	int temp  = 0;

	for(int i = 0; i < SIZE; i++)           // outer loop
	{
    	for(int j = 0; j < SIZE - 1; j++)   //   inner loop
		{
 	       	if(array[j] < array[j + 1])		//     if current element less than next
			{
    	        temp = array[j];    		//       store current data to temp
           		array[j] = array[j + 1]; 	//       exchange the positions of the data
           		array[j + 1] = temp;
           		numSwaps++;                 //       increment the number of swaps
        	}
        	else                            //     otherwise
                tests++;                    //       increment the number of tests without swap
            //printArray(array);
    	}
    	printArray(array);					//   show the current array progress
	}
   	cout << " Number of Swaps:  " << numSwaps << endl;
   	cout << " Number of Tests:  " << tests    << endl;
   	cout << " Total operations: " << tests + numSwaps << endl;
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
