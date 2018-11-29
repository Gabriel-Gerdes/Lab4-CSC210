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

void title();
void converter(LinkedStackType<int> );
void readData(LinkedStackType<int> & );
void printOrigOrder(LinkedStackType<int> );
void printOrigOrder(LinkedStackType<string> );
void printStackFromTopDown(LinkedStackType<int> );
void printStackFromTopDown(LinkedStackType<string> );


ifstream fin ("Input.txt");        /// input file without any errors
ofstream fout("Output.txt");

int main()
{
	LinkedStackType<int> iStack;    // stack object accepting int inputs
	title();						// prints the title
	readData(iStack);               // read the data into the stack (pass by ref)
	//converter(iStack);                    // convert each int to its respective base

	//printStackFromTopDown(iStack);     // demonstrates an incorrect LIFO printing of data
	printOrigOrder(iStack);         // demonstrates printing data in orig order as read
	iStack.sortLinkedStack();
	printOrigOrder(iStack);
                          // call the class sort function
                          // print the sorted stack & write to InputS.txt
    fin.close();                    // close the input file (notice it was not used)
	fout.close();					// close the output file
    return 0;						// return 0 to indicate OS is ok
}

void title()
{
	cout << setw(63) << "T H E    O R I G I N A L    U N S O R T E D    L I S T" << endl;
	cout << setw(63) << "======================================================" << endl << endl;
	cout << setw(33) << "Written by" << " Your Names Here" << endl  << endl  << endl;

	fout << setw(63) << "T H E    O R I G I N A L    U N S O R T E D    L I S T" << endl;
	fout << setw(63) << "======================================================" << endl << endl;
	fout << setw(33) << "Written by" << " Your Names Here" << endl  << endl  << endl;
}

void readData(LinkedStackType<int> & s)
{

    int deciOrig;                  // declare local int for reading
    string str = "-------------- Input error ignored ---------------";            //Line 3

    fin >> deciOrig;

    while(!fin.eof())                               //Line 4
    {                                               //Line 5
        try                                         //Line 6
        {                                           //Line 7
            if (!fin)                               //Line 11
                throw str;                          //Line 12

            s.push(deciOrig);           // push the int into the stack
        }                                           //Line 15
        catch (string messageStr)                   //Line 16
        {                                           //Line 17
            cout <<  messageStr << endl;                           //Line 18
            fout << messageStr << endl;
            fin.clear();                            //Line 20
            fin.ignore(100, '\n');                  //Line 21
        }
        fin >> deciOrig;            // read the next int
    }
}

// a function to convert a decimal number to base n
void converter(LinkedStackType<int> stk)
{
    string getString[] = {"0", "1", "2", "3", "4", "5", "6", "7",
                          "8", "9", "A", "B", "C", "D", "E", "F" };
    int deciOrig = 15;
    int deciSave = stk.top();
    int divis = 16;
    int quot;
    string remainder = "";
    LinkedStackType<string> local;
    while(!stk.isEmptyStack())
	{
        deciSave = stk.top();
	    cout << stk.top() << endl;
            int conversionNumber = stk.top();
            int digits = 0;
            while (conversionNumber != 0)
                conversionNumber /= 10; digits++;

            for(int j=1; digits > j; j++)
            {
                do{
                    quot = deciSave/divis;
                    remainder += getString[deciSave%divis];
                }while(quot != 0);
            }
            local.push(remainder);
            stk.pop();
            remainder = "";

	}
    printOrigOrder(local);
}

void printOrigOrder(LinkedStackType<int> stk)
{
    LinkedStackType<int> local;
    while(!stk.isEmptyStack())
	{
	    local.push(stk.top());
	    stk.pop();                                  // remove the top integer
	}
	printStackFromTopDown(local);
}

void printOrigOrder(LinkedStackType<string> stk)
{
    LinkedStackType<string> local;
    while(!stk.isEmptyStack())
	{
	    local.push(stk.top());
	    stk.pop();                                  // remove the top integer
	}
	printStackFromTopDown(local);
}

// displays the data in last in, first out (LIFO).  (backwards stack)
void printStackFromTopDown(LinkedStackType<int> stk)
{
    while(!stk.isEmptyStack())
	{
	    cout << setw(40) << stk.top() << endl;      // look, but don't remove
		fout << setw(40) << stk.top() << endl;      // look, but don't remove
		stk.pop();                                  // remove the top integer
	}
	cout << endl;
	fout << endl;
}
void printStackFromTopDown(LinkedStackType<string> stk)
{
    while(!stk.isEmptyStack())
	{
	    cout << setw(40) << stk.top() << endl;      // look, but don't remove
		fout << setw(40) << stk.top() << endl;      // look, but don't remove
		stk.pop();                                  // remove the top integer
	}
	cout << endl;
	fout << endl;
}

