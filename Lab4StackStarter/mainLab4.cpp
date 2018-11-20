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

	//printStackFromTopDown(iStack);     // demonstrates an incorrect LIFO printing of data
	printOrigOrder(iStack);         // demonstrates printing data in orig order as read
	iStack.sortLinkedStack();
	printOrigOrder(iStack);
	converter(iStack);                    // convert each int to its respective base
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

	fout << setw(63) << "T H E    O R I G I N A L    U N S O R T E D    L I S T" << endl;
	fout << setw(63) << "======================================================" << endl << endl;
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
void converter(LinkedStackType<int> original)
{
    string getString[] = {"0", "1", "2", "3", "4", "5", "6", "7",
                          "8", "9", "A", "B", "C", "D", "E", "F" };
    int deciSave = original.top();
    int divis;
    int quot;
    string remainder = "";
    LinkedStackType<string> localTemp;
    LinkedStackType<string> local;
    LinkedStackType<int> stk;

    for(int i =0; i < 3; i++ )
    {
        switch(i)
        {
            case 0:
                divis = 16;
                break;
            case 1:
                divis = 8;
                break;
            case 2:
                divis = 2;
                break;
        }
        stk = original;
        while(!stk.isEmptyStack())
        {
            deciSave = stk.top();
            do{
                quot = deciSave/divis;
                localTemp.push(getString[deciSave%divis]);
                deciSave = quot;
            }while(quot != 0);

            while(!localTemp.isEmptyStack())
            {
                remainder += localTemp.top();
                localTemp.pop();
            }

            local.push(remainder);
            stk.pop();
            remainder = "";
        }
        printOrigOrder(local);
    }
}

void printOrigOrder(LinkedStackType<int> stk)
{
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

void printOrigOrder(LinkedStackType<string> stk)
{
    LinkedStackType<string> local;
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

