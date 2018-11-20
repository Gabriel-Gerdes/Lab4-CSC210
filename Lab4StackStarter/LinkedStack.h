// Header File: LinkedStack.h
// Modified in Lab 4 by Jeff Goldstein, Adjunct Professor, TCC Va Beach
// modify your implementation to accept: size variable, an optimized bubble sort, & swap function

#ifndef H_StackType
#define H_StackType

#include <iostream>
#include <cassert>
#include "stackADT.h"	// your author’s code given electronically

using namespace std;

//Definition of the node
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

template <class Type>
class LinkedStackType : public stackADT<Type>
{
public:
    LinkedStackType();
      //Default constructor
      //Postcondition: stackTop = NULL;

    LinkedStackType(const LinkedStackType<Type>& otherStack);
      //Copy constructor

    ~LinkedStackType();
      //Destructor
      //Postcondition: All the elements of the stack are
      //               removed from the stack.

    const LinkedStackType<Type>& operator=
                              (const LinkedStackType<Type>&);
      //Overload the assignment operator.

    bool isEmptyStack() const;
      //Function to determine whether the stack is empty.
      //Postcondition: Returns true if the stack is empty;
      //               otherwise returns false.

    bool isFullStack() const;
      //Function to determine whether the stack is full.
      //Postcondition: Returns false.

    void initializeStack();
      //Function to initialize the stack to an empty state.
      //Postcondition: The stack elements are removed;
      //               stackTop = NULL;

    void push(const Type& newItem);
      //Function to add newItem to the stack.
      //Precondition: The stack exists and is not full.
      //Postcondition: The stack is changed and newItem
      //               is added to the top of the stack.

    Type top() const;
      //Function to return the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: If the stack is empty, the program
      //               terminates; otherwise, the top
      //               element of the stack is returned.

    void pop();
      //Function to remove the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: The stack is changed and the top
      //               element is removed from the stack.

    int getSize() const;	        /// implement this function
      // return the size of the stack

    void sortLinkedStack();         /// implement this function
      // uses an optimized bubble sort to sort the stack in ascending order

private:
    nodeType<Type> *stackTop;       // top pointer to the stack
    void copyStack(const LinkedStackType<Type>& otherStack);
      //Function to make a copy of otherStack.
      //Postcondition: A copy of otherStack is created and assigned to this stack.
    bool swapData(Type &, Type &);  /// implement this function to swap node data
      // exchanges (swaps) the data
    int size;                       /// implement size of the list
};

#endif
