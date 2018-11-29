// Handle exceptions by fixing the errors. The program continues to
// read the valid data and shows exceptions where data is invalid
// modified from Ch14_Exp17.cpp (from the Malik 7th Edition)
// by Jeff Goldstein, TCC Adjunct Professor

/// important.... test compiling this program with C++11.... or C++98 works, too.
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ifstream fin("Input.txt");      /// note: this is the Lab 4 input file with 3 errors

int main()
{
    int i = 1;                                      //Line 1
    int number;
    //bool done = false;                            //Line 2 (not used from author)

    string str = "Input error ignored.";            //Line 3
    fin >> number;
    while(!fin.eof())                               //Line 4
    {                                               //Line 5
        try                                         //Line 6
        {                                           //Line 7
            if (!fin)                               //Line 11
                throw str;                          //Line 12

            //done = true;                          //Line 13 (not used from author)
            cout << i << "\t" << number
                 << endl;
            i++;         //it prints the count of correct data just read
        }                                           //Line 15
        catch (string messageStr)                   //Line 16
        {                                           //Line 17
            cout << messageStr
                 << endl;                           //Line 18
            fin.clear();                            //Line 20
            fin.ignore(100, '\n');                  //Line 21
        }
        fin >> number;                              //Line 22
    }
    return 0;                                       //Line 24
}
