// mainLab4.cpp (a good start)
// This program tests various operations of a linked stack
// (but this is without any input error checks!)
// Written by ...[Your name(s) go(es) here]
// (don't forget to use copious comments in all your files)

#include <fstream>
#include <iomanip>
#include <string>
#include <math.h>
#include "LinkedStack.cpp"            // more implementation is necessary

using namespace std;

<<<<<<< HEAD
void title();
=======
void titleOrig();
>>>>>>> Noah
void converter();
void readData(LinkedStackType<int> & );
void printOrigOrder(LinkedStackType<int> );
void printSortStack(LinkedStackType<int> );
void printBaseStack(LinkedStackType<string> &, int);

ifstream fin ("Input.txt");         // input file
ofstream fout("Output.txt");        // Output file for complete report
ofstream fou2("InputS.txt");        //
//ofstream fin("InputS.txt");         //

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
	cout << setw(63) << "======================================================" << endl << endl;

	//fout << setw(33) << "Written by" << " Your Names Here" << endl  << endl  << endl;
}

void readData(LinkedStackType<int> & s)
{
    int deciOrig;                  // declare local int for reading

    fin.clear();
    fin.seekg(0, ios::beg);

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

// a function to convert a decimal number to base n
void converter()
{
    cout << endl;
	cout << setw(63) << "T H E    B A S E    C O N V E R T E R" << endl;
	cout << setw(63) << "=====================================" << endl << endl;
	cout << setw(65) << "Written by Gabriel Gerdes and Noah Teeter" << endl  << endl;

	//fout header

    LinkedStackType<int> stk;
    readData(stk);
    stk.sortLinkedStack();
    string getString[] = {"0", "1", "2", "3", "4", "5", "6", "7",
                          "8", "9", "A", "B", "C", "D", "E", "F" };
	int deciOrig;
    int deciSave;
<<<<<<< HEAD
    int divis;
    int quot;
    string remainder = "";
    LinkedStackType<string> local;
=======
    int i;
    int divis;
    int quot;
    int remainder;
    string sRemainder;               //
    int base[] = {16, 8, 2};        //an array of bases used


    LinkedStackType<string> local;  //create a local stack of strings

	while(!fou2.eof())
    {
		deciSave = deciOrig;
		cout << setw(14) << deciOrig;
		fout << setw(14) << deciOrig;
		for(int i = 0; i < 3; i++ )
		{
		    divis = base[i];      //divisor is the base to convert
			do
			{
			    quot = deciSave /divis;
			    remainder = deciSave % divis;   //get remainder
			    sRemainder = getString[remainder];   //convert to string
			    local.push(sRemainder);     //push string on stack
			    deciSave = quot;        //quotient now a new test
			}while(quot != 0);

			deciSave = deciOrig;        //start next conversion with new base
			printBaseStack(local, i);   //output the elements of the stack
        }
        cout << endl;
        fout << endl;
>>>>>>> Noah

	while(!stk.isEmptyStack())
    {
		deciOrig = stk.top();
		for(int i = 0; i < 4; i++ )
		{
			deciSave = deciOrig;
			switch(i)
			{
                case 0:
                    divis = 10;
                    break;
				case 1:
					divis = 16;
					break;
				case 2:
					divis = 8;
					break;
				case 3:
					divis = 2;
					break;
			}
			do{
                quot = deciSave/divis;
                local.push(getString[deciSave%divis]);
                deciSave = quot;
			}while(quot != 0);

			while(!local.isEmptyStack())
			{
				remainder += local.top();
				local.pop();
			}
			cout << right << setw((40/(pow(1.05,divis)))) << remainder;
			remainder = "";
        }
        cout << endl;
		stk.pop();
	}
}

void printOrigOrder(LinkedStackType<int> stk)
{
<<<<<<< HEAD
    LinkedStackType<int> local;
    while(!stk.isEmptyStack())
	{
	    local.push(stk.top());
	    stk.pop();                                  // remove the top integer
	}
    while(!local.isEmptyStack())
	{
	    cout << setw(40) << local.top() << endl;      // look, but don't remove
		fout << setw(40) << local.top() << endl;      // look, but don't remove
		local.pop();                                  // remove the top integer
	}
	cout << endl;
	fout << endl;
}
=======
    LinkedStackType<int> local;    // make a local stack
>>>>>>> Noah

    while(!stk.isEmptyStack())
<<<<<<< HEAD
	{
	    local.push(stk.top());
	    stk.pop();                                  // remove the top integer
	}
    while(!local.isEmptyStack())
	{
	    cout << setw(40) << local.top() << endl;      // look, but don't remove
		fout << setw(40) << local.top() << endl;      // look, but don't remove
		local.pop();                                  // remove the top integer
=======
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
>>>>>>> Noah
	}
	cout << endl;
	fout << endl;
}

<<<<<<< HEAD
void printStackFromTopDown(LinkedStackType<string> stk)
=======
void printBaseStack(LinkedStackType<string> & stk, int column)
>>>>>>> Noah
{

}

