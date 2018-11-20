// LinkedStack.cpp (Implementation file for the LinkedStack)

#include "LinkedStack.h"

//Default constructor
template <class Type>
LinkedStackType<Type>::LinkedStackType()
{
    stackTop = NULL;
    size = 0;
}

//copy constructor
template <class Type>
LinkedStackType<Type>::LinkedStackType(const LinkedStackType<Type>& otherStack)
{
    stackTop = NULL;
    copyStack(otherStack);
}//end copy constructor

//destructor
template <class Type>
LinkedStackType<Type>::~LinkedStackType()
{
    initializeStack();
}//end destructor

    //overloading the assignment operator
template <class Type>
const LinkedStackType<Type>& LinkedStackType<Type>::operator=
    			  (const LinkedStackType<Type>& otherStack)
{
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this;
}//end operator=

template <class Type>
bool LinkedStackType<Type>::isEmptyStack() const
{
    return(stackTop == NULL);       //stack is empty if stackTop is NULL
} //end isEmptyStack

template <class Type>
bool LinkedStackType<Type>:: isFullStack() const
{
    return false;                   //a linked stack is virtually never full
} //end isFullStack

template <class Type>
void LinkedStackType<Type>:: initializeStack()
{
    nodeType<Type> *temp;           //pointer to delete the node

    while (stackTop != NULL)        //while there are elements in the stack
    {
        temp = stackTop;            //set temp to point to the current node
        stackTop = stackTop->link;  //advance stackTop to the next node
        delete temp;                //deallocate memory occupied by temp
    }
} //end initializeStack

template <class Type>
void LinkedStackType<Type>::push(const Type& newElement)
{
    nodeType<Type> *newNode;        //pointer to create the new node

    newNode = new nodeType<Type>;   //create the node

    newNode->info = newElement;     //store newElement in the node
    newNode->link = stackTop;       //insert newNode before stackTop
    stackTop = newNode;             //set stackTop to point to the
                                    //top node
    size++;                         // add 1 to size
} //end push


template <class Type>
Type LinkedStackType<Type>::top() const
{
    assert(stackTop != NULL);       //if stack is empty, terminate the program
    return stackTop->info;          //return the top element
}//end top

template <class Type>
void LinkedStackType<Type>::pop()
{
    nodeType<Type> *temp;           //pointer to deallocate memory

    if (stackTop != NULL)
    {
        temp = stackTop;            //set temp to point to the top node

        stackTop = stackTop->link;  //advance stackTop to the
                                    //next node
        delete temp;                //delete the top node
        size--;                     //reduce size by 1
    }
    else
        cout << "Cannot remove from an empty stack." << endl;
}//end pop

template <class Type>
void LinkedStackType<Type>::copyStack
                     (const LinkedStackType<Type>& otherStack)
{
    nodeType<Type> *newNode, *current, *last;

    if (stackTop != NULL)               //if stack is nonempty, make it empty
        initializeStack();

    if (otherStack.stackTop == NULL)
        stackTop = NULL;
    else
    {
        current = otherStack.stackTop; //set current to point to stack to be copied
        size = otherStack.size;         // size of stacks are the same
        //copy the stackTop element of the stack
        stackTop = new nodeType<Type>;  //create the node

        stackTop->info = current->info; //copy the info
        stackTop->link = NULL;          //set the link field of the node to NULL
        last = stackTop;                //set last to point to the node
        current = current->link;        //set current to point to the next node

        //copy the remaining stack
        while (current != NULL)         /// these lines need to be commented
        {                               /// to notify reader what is going on?
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }//end while
    }//end else
} //end copyStack

template <class Type>
int LinkedStackType<Type>::getSize() const
{
    return 0;                    // returns the size of the stack
}

template <class Type>
void LinkedStackType<Type>::sortLinkedStack()
{
	bool swapped = true;      				 // assume exchanges will happen
    nodeType<Type> *curr;            //pointer to traverse the list
    nodeType<Type> *next;           //pointer for progression

	for(int i = 0; swapped && i < size; i++) // outer loop
	{
	    swapped = false;					 //   reset the flag for no exchanges

	    curr = stackTop;           //primes traversal pointers
	    next = curr -> link;

    	for(int j = 0; j < size - i - 1; j++)//   inner loop does not check sorted items
		{
            if(curr->info > next->info)		 //     if current element bigger than next
            {
                cout << size << "swapped" << curr->info << endl;
                swapped = swapData(curr->info, next->info);   //bubble sort.
            }
        }
        curr = next;            // advance curr pointer.
        next = next->link;      // advance next pointer.
     }   //end of inner loop;
}  // uses an optimized bubble sort to sort the stack in ascending order

template <class Type>
bool LinkedStackType<Type>::swapData(Type & dataA, Type & dataB)
{
    Type temp = dataA;  //adds data from A to Temp
    dataA = dataB;      //copies data from B to A
    dataB = temp;       //copies data from Temp to B.
    return true;
}
