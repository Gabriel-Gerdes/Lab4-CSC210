// This program tests various operations of a linked stack
// (Just for now, try reading input0.txt without any input error checks)
// Written by (Your name goes here) 11/01/2018

#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

#include "linkedStack.cpp"

string getString(int num);
void title();
void converter(LinkedStackType<string> s);

ifstream fin("Input.txt");
ofstream fout("Output.txt");

int main()
{
	LinkedStackType<string> stack;	// stack object accepting string inputs
	title();						// prints the title
	converter(stack);				// convert each # to respective bases
	fout.close();					// close the output file
    return 0;						// return 0 to indicate OS is ok
}

void title()
{									// title with column headings in correct places
	cout << setw(62) << "B  A  S  E      C   O   N   V   E   R   T   E   R" << endl;
	cout << setw(62) << "=================================================" << endl << endl;
	cout << setw(35) << "Written by" << " Your Name Here" << endl  << endl  << endl;

	fout << setw(62) << "B  A  S  E      C   O   N   V   E   R   T   E   R" << endl;
	fout << setw(62) << "=================================================" << endl << endl;
	fout << setw(35) << "Written by" << " Your Name Here" << endl  << endl  << endl;
}

// a simple function to test
// converts from base 10 to base (2, 8, and 16)... not yet!
void converter(LinkedStackType<string> s)
{
    string getString[] = {"0", "1", "2", "3",   // cleverly converts int index to a string
                          "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };
	s.push("O");                // note, letter "O" is the first push into the stack
	s.push("L");
	s.push("L");
	s.push("E");
	s.push("H");                // note, letter "H" is the last push into the stack!

	cout << setw(32) << getString[10] << "\t";

	while(!s.isEmptyStack())
	{
		cout << s.top();        // look, but don't remove
		fout << s.top();        // look, but don't remove
		s.pop();                // remove the top letter
	}
    cout << endl << endl;
    fout << endl << endl;
}
