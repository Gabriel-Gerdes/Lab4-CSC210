// mainLab4.cpp (a good start)
// This program tests various operations of a linked stack
//
// Written by ...Gabriel Gerdes & Noah Teeter
//

#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include "LinkedStack.cpp"            // more implementation is necessary

using namespace std;

void titleOrig();
void converter();
void readData(LinkedStackType<int> & );
void printOrigOrder(LinkedStackType<int> );
void printSortStack(LinkedStackType<int> );
void printBaseStack(LinkedStackType<string> &, int, int);

ifstream fin ("Input.txt");         // input file
ofstream fout("Output.txt");        // Output file for complete report
ofstream fou2("InputS.txt");        // Output file that is sorted
ifstream fin2("InputS.txt");        // Sorted input file

int main()
{
	LinkedStackType<int> iStack;    // stack object accepting int inputs
	readData(iStack);               // read the data into the stack (pass by ref)
	titleOrig();					// prints the title
	printOrigOrder(iStack);         // demonstrates printing data in orig order as read
    iStack.sortLinkedStack();       // call the class sort function
    printSortStack(iStack);         // print the sorted stack & write to InputS.txt
    converter();                    // convert each int to its respective base

	fin.close();                    // close the input file
	fout.close();					// close the output file
	fou2.close();                   // close the sorted output file
	fin2.close();                   // close the sorted input file

    return 0;						// return 0 to indicate OS is ok
}

void titleOrig()
{
    cout << endl;
	cout << setw(63) << "T H E    O R I G I N A L    U N S O R T E D    L I S T" << endl;
	cout << setw(63) << "======================================================" << endl << endl;

	fout << endl;
	fout << setw(63) << "T H E    O R I G I N A L    U N S O R T E D    L I S T" << endl;
	fout << setw(63) << "======================================================" << endl << endl;

}

void readData(LinkedStackType<int> & s)
{
    int deciOrig;                  // declare local int for reading
    string str = "--------------- Input error ignored ------------------";

    fin >> deciOrig;                // priming read for the 1st decimal number
    while( !fin.eof() )             // loop while data exists
    {
        try
        {
            if (!fin)
                throw str;
            s.push(deciOrig);
        }
        catch (string messageStr)
        {
            cout << setw(63) << messageStr << endl;
            fout << setw(63) << messageStr << endl;
            fin.clear();
            fin.ignore(100, '\n');
        }
        fin >> deciOrig;            // read the next int
    }
}

// Function to convert a decimal number to base n
void converter()
{
    // Console header
    cout << endl;
	cout << setw(60) << "T H E    B A S E    C O N V E R T E R" << endl;
	cout << setw(60) << "=====================================" << endl << endl;
	cout << setw(62) << "Written by Gabriel Gerdes and Noah Teeter" << endl  << endl;
	cout << setw(20) << "DECIMAL" << setw(12) << "HEX" << setw(13) << "OCTAL"
         << setw(33) << "BINARY" << endl;
    cout << setw(20) << "-------" << setw(12) << "---" << setw(13) << "-----"
         << setw(33) << "------" << endl;

	//Output file header
    fout << endl;
	fout << setw(60) << "T H E    B A S E    C O N V E R T E R" << endl;
	fout << setw(60) << "=====================================" << endl << endl;
	fout << setw(62) << "Written by Gabriel Gerdes and Noah Teeter" << endl  << endl;
	fout << setw(20) << "DECIMAL" << setw(12) << "HEX" << setw(13) << "OCTAL"
         << setw(33) << "BINARY" << endl;
    fout << setw(20) << "-------" << setw(12) << "---" << setw(13) << "-----"
         << setw(33) << "------" << endl;

    string getString[] = {"0", "1", "2", "3", "4", "5", "6", "7",       // Local string array
                          "8", "9", "A", "B", "C", "D", "E", "F" };
	int deciOrig;               // Local variables
    int deciSave;               //
    int divis;                  //
    int quot;                   //
    int remainder;              // End of local int variables
    string sRemainder;          // String variable
    int base[] = {16, 8, 2};    // An array of bases used


    LinkedStackType<string> local;  //create a local stack of strings to store the remainder

    fin2 >> deciOrig;               // Priming read

	while(!fin2.eof())
    {
		deciSave = deciOrig;
		cout << setw(20) << deciOrig;
		fout << setw(20) << deciOrig;
		for(int i = 0; i < 3; i++ ) // For loop to convert int to all bases
		{
		    divis = base[i];        // Divisor is the base to convert
			do                      // Do-While loop to convert one base at a time and then output
			{
			    quot = deciSave /divis;
			    remainder = deciSave % divis;   //get remainder
			    sRemainder = getString[remainder];   //convert to string
			    local.push(sRemainder);     //push string on stack
			    deciSave = quot;        //quotient now a new test
			}while(quot != 0);

			deciSave = deciOrig;        //start next conversion with new base
			printBaseStack(local, i, local.getSize());      //output the elements of the stack
        }
        fin2 >> deciOrig;           // File in read for next conversion
        cout << endl;
        fout << endl;

	}
	cout << endl << endl;
	fout << endl << endl;
}

// Function to reverse the order of a given stack
void printOrigOrder(LinkedStackType<int> stk)
{
    LinkedStackType<int> local;    // make a local stack

    while(!stk.isEmptyStack())
    {
        local.push(stk.top());      // take top element and push into local stack
        stk.pop();                  // remove top element of stk
    }

    while(!local.isEmptyStack())
    {
        cout << setw(40) << local.top() << endl;
        fout << setw(40) << local.top() << endl;
        local.pop();
    }
    cout << "\n\n\n";
    fout << "\n\n\n";
}

// Function to print header and output a stack
void printSortStack(LinkedStackType<int> stk)
{
	cout << setw(51) << "T H E    S O R T E D    L I S T" << endl;
	cout << setw(51) << "===============================" << endl << endl;

	fout << setw(51) << "T H E    S O R T E D    L I S T" << endl;
	fout << setw(51) << "===============================" << endl << endl;

	while(!stk.isEmptyStack())
	{
	    cout << setw(40) << stk.top() << endl;      // look, but don't remove
		fout << setw(40) << stk.top() << endl;      // look, but don't remove
		fou2 << setw(40) << stk.top() << endl;
		stk.pop();                                  // remove the top integer
	}
	cout << endl;
	fout << endl;
}

// Function to output a stack
void printBaseStack(LinkedStackType<string> & stk, int base, int column)
{
    if(base == 0)                   // Set column width based on the number base
    {
        cout << setw(13 - column);
        fout << setw(13 - column);
    }
    else if(base == 1)
    {
        cout << setw(14 - column);
        fout << setw(14 - column);
    }
    else
    {
        cout << setw(34 - column);
        fout << setw(34 - column);
    }                               // End of setw determination

    while (!stk.isEmptyStack())     // While the stack is not empty
    {
        fout << stk.top();          // Output to Output.txt
        cout << stk.top();          // Output to Console
        stk.pop();                  // Remove the top of the stack
    }

}

