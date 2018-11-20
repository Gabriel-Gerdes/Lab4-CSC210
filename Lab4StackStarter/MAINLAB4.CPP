// mainLab4.cpp (a good start)
// This program tests various operations of a linked stack
// (but this is without any input error checks!)
// Written by ...[Your name(s) go(es) here]
// (don't forget to use copious comments in all your files)

#include <fstream>
#include <iomanip>
#include <string>
#include "LinkedStack.cpp"            // more implementation is necessary

using namespace std;

void titleOrig();
void converter();
void readData(LinkedStackType<int> & );
void printOrigOrder(LinkedStackType<int> );

void printSortStack(LinkedStackType<int> );

ifstream fin ("Input.txt");         // input file
ofstream fout("Output.txt");        // Output file

int main()
{
	LinkedStackType<int> iStack;    // stack object accepting int inputs
	readData(iStack);               // read the data into the stack (pass by ref)
	titleOrig();					// prints the title

	printOrigOrder(iStack);         // demonstrates printing data in orig order as read
    iStack.sortLinkedStack();       // call the class sort function
    printSortStack(iStack);         // print the sorted stack & write to InputS.txt
    converter();                    // convert each int to its respective base
	fin.close();                    // close the input file (notice it was not used)
	fout.close();					// close the output file
    return 0;						// return 0 to indicate OS is ok
}

void titleOrig()
{
    cout << endl;
	cout << setw(63) << "T H E    O R I G I N A L    U N S O R T E D    L I S T" << endl;
	cout << setw(63) << "======================================================" << endl << endl << endl;
	//cout << setw(33) << "Written by" << " Your Names Here" << endl  << endl  << endl;

	fout << endl;
	fout << setw(63) << "T H E    O R I G I N A L    U N S O R T E D    L I S T" << endl;
	fout << setw(63) << "======================================================" << endl << endl << endl;
	//fout << setw(33) << "Written by" << " Your Names Here" << endl  << endl  << endl;
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
        fin >> deciOrig;

        s.push(deciOrig);           // push the int into the stack
        fin >> deciOrig;            // read the next int
    }
}

// a function to convert a decimal number to base n
void converter()
{
    // cleverly converts an input index to a one letter string corresponding to base digits
    string getString[] = {"0", "1", "2", "3", "4", "5", "6", "7",
                          "8", "9", "A", "B", "C", "D", "E", "F" };
    /// more code here
}

// displays the data in last in, first out (LIFO).  (backwards stack)
void printReversedOrder(LinkedStackType<int> stk)
{
	while(!stk.isEmptyStack())
	{
		cout << setw(40) << stk.top() << endl;      // look, but don't remove
		fout << setw(40) << stk.top() << endl;      // look, but don't remove
		stk.pop();                                  // remove the top integer
	}
	cout << endl;
    cout << setw(67) << "Oops! This output should be in the same order as the data!\n";
    cout << setw(67) << "Perhaps, you can fix it so it shows same order as read in?\n";
    cout << setw(68) << "(note:  The 7 should be the first number printed.........)\n\n";
	fout << endl;
    fout << setw(67) << "Oops! This output should be in the same order as the data!\n";
    fout << setw(67) << "Perhaps, you can fix it so it shows same order as read in?\n";
    fout << setw(68) << "(note:  The 7 should be the first number printed.........)\n\n";
    fout << endl;
}

void printOrigOrder(LinkedStackType<int> stk)
{
    /// This is your first challenge.
}

void printSortStack(LinkedStackType<int> stk)
{

}

