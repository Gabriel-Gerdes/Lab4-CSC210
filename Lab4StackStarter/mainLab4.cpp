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

void titleOrig();
void converter();
void readData(LinkedStackType<int> &, ostream&);
void printOrigOrder(LinkedStackType<int> );
void printSortStack(LinkedStackType<int> );
void printConvertedValue(LinkedStackType<string> &, int);

ifstream fin ("Input.txt");         // input file
ofstream fout("Output.txt");        // Output file for complete report
ofstream fou2("InputS.txt");        //
ifstream fin("InputS.txt");         //

int main()
{
    LinkedStackType<int> iStack;    // stack object accepting int inputs
    readData(iStack, fin);               // read the data into the stack (pass by ref)

    titleOrig();					// prints the title
    printOrigOrder(iStack);         // demonstrates printing data in orig order as read
    iStack.sortLinkedStack();       // call the class sort function
    printSortStack(iStack);         // print the sorted stack & write to InputS.txt
    converter();                    // convert each int to its respective base

    fin.close();                    // close the input file (notice it was not used)
    fout.close();					// close the output file
    return 0;						// return 0 to indicate OS is ok
}

void readData(LinkedStackType<int> & s, ostream& stream)
{
    int deciOrig;                  // declare local int for reading

    stream.clear();
    stream.seekg(0, ios::beg);

    string str = "--------------- Input error ignored ------------------";

    stream >> deciOrig;                // priming read for the 1st decimal number
    while( !stream.eof() )             // loop while data exists
    {
        try
        {
            if (!stream)
                throw str;
            s.push(deciOrig);
        }
        catch (string messageStr)
        {
            cout << setw(63) << messageStr << endl;
            fout << setw(63) << messageStr << endl;
            stream.clear();
            stream.ignore(100, '\n');
        }
        stream >> deciOrig;            // read the next int
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
    }
    cout << endl;
    fout << endl;
}

void printConvertedValue(LinkedStackType<string> & stk, int column)
{
    string convertedValue = "";

    while(!stk.isEmptyStack())
    {
        convertedValue += stk.top();
        stk.pop();
    }

    cout << right << setw((40/(pow(1.05,column)))) << convertedValue;

    cout << endl;
}

// a function to convert a decimal number to base n
void converter()
{
    cout << endl;
    cout << setw(63) << "T H E    B A S E    C O N V E R T E R" << endl;
    cout << setw(63) << "=====================================" << endl << endl;
    cout << setw(65) << "Written by Gabriel Gerdes and Noah Teeter" << endl  << endl;

    LinkedStackType<int> stk;
    readData(stk, fin);
    stk.sortLinkedStack(); ///This needs to be replaced by the process of reading in from the second file.
    
    int base[] = {16, 8, 2};        //an array of bases used
    string getString[] = {"0", "1", "2", "3", "4", "5", "6", "7",
                          "8", "9", "A", "B", "C", "D", "E", "F" };
    int deciOrig;
    int deciSave;
    int divis;
    int quot;
    string sRemainder = "";
    LinkedStackType<string> local;

    while(!stk.isEmptyStack())
    {
        deciOrig = stk.top();
        deciSave = deciOrig;
        cout << setw(14) << deciOrig;
        fout << setw(14) << deciOrig;
        for(int i = 0; i < 3; i++ )
        {
            divis = base[i];      //divisor is the base to convert
            do
            {
                quot = deciSave/divis;
                sRemainder = getString[deciSave%divis] //get the remainder of the value from the stack divided by desired base value. 
                local.push(sRemainder); //push string on stack
                deciSave = quot;        //quotient now a new test
            }while(quot != 0);

            deciSave = deciOrig;        //start next conversion with new base
            printConvertedValue(local, i);   //output the elements of the stack
        }
        sRemainder = "";
        stk.pop();
        cout << endl;
        fout << endl;
    }
}

void titleOrig()
{
    fout << endl;
    fout << setw(63) << "T H E    O R I G I N A L    U N S O R T E D    L I S T" << endl;
    fout << setw(63) << "======================================================" << endl << endl;

    //fout << setw(33) << "Written by" << " Your Names Here" << endl  << endl  << endl;
}
