//===================================================================
// Emma Steinman, Yow Yong, Sam Strosnider 
// PQueue.h
// May 1, 2017
// This is the header file for the Priority Queue class using the
// BST class. Our group worked together on almost all of the 
// functions. Emma wrote most of the remove function and Yow Yong 
// wrote the main parts of the other functions and then we worked
// together to fix the errors and change parts of the code. 
//===================================================================

#include "BST.h"
using namespace std;

//===================================================================
#ifndef PQUEUE_H
#define PQUEUE_H

template <class T>
class PQueue
{
private:
    BST<T>      bst;
public:
                PQueue      	( void );
                PQueue     		( const PQueue<T> & );
               ~PQueue      	( void );
    PQueue<T>   operator=   	( const PQueue<T> & );
    void        enqueue     	( T item );
    T           dequeue     	( void );
    T           peek        	( void );
    int         length      	( void ) const;
    bool        isEmpty     	( void ) const;
    void        clear       	( void );
    string      to_string   	( void ) const;
    friend ostream & operator<< ( ostream &os, const PQueue<T> &pq )
    {
        os << pq.bst;
        return os;
    }
};

//===================================================================
// Constructor 
// Creates an empty priority queue
//===================================================================

template <class T>	
			PQueue<T>::PQueue 		(void)
{
}

//===================================================================
// Copy constructor 
// Creates a priority queue from an existing queue
//===================================================================

template <class T>	
			PQueue<T>::PQueue      (const PQueue<T> & pq)
{
	bst = pq.bst;
}

//===================================================================
// Destructor 
// Destroys memory used by priority queue
//===================================================================

template <class T>	
			PQueue<T>::~PQueue      (void)
{
}

//===================================================================
// Operator = 
// Sets priority queue equal to another priority queue
//===================================================================

template <class T>	
PQueue<T> 	PQueue<T>::operator=	(const PQueue<T> & pq)
{
	bst = pq.bst;
	return *this;
}

//===================================================================
// Enqueue 
// Adds another value to the priority queue
//===================================================================

template <class T>	
void		PQueue<T>::enqueue     	(T item)
{
	bst.insert(bst.root, item);
}

//===================================================================
// Dequeue 
// Removes and returns the biggest value in a priority queue
//===================================================================

template <class T>	
T			PQueue<T>::dequeue     	(void)
{
	if (bst.isEmpty())
	{
		cout<< "Error: Empty Queue."<< endl;
		exit(1);
	}
	Node<T> * ptr = bst.findBiggest(bst.root);
	T item = ptr->data;
	bst.remove(ptr->data);
	return item;
}

//===================================================================
// Peek 
// Returns but does not remove the biggest value in a priority queue
//===================================================================

template <class T>	
T			PQueue<T>::peek			(void)
{
	if (bst.isEmpty())
	{
		cout<< "Error: Empty Queue." << endl;
		exit(1);
	}

	Node<T> * ptr = bst.findBiggest(bst.root);
	return ptr->data;

}

//===================================================================
// length 
// Returns the amount of items in the priority queue
//===================================================================

template <class T>	
int			PQueue<T>::length      	(void) const
{	
	return bst.length(bst.root);
}

//===================================================================
// isEmpty 
// Returns a boolean value indicating if the queue is empty
//===================================================================

template <class T>	
bool		PQueue<T>::isEmpty 		(void) const
{
	return bst.isEmpty();
}

//===================================================================
// clear 
// Clears the priority queue
//===================================================================

template <class T>	
void		PQueue<T>::clear		(void)
{
	return bst.clear(bst.root);
}

//===================================================================
// to_string 
// Converts items in priority queue to a string value
//===================================================================

template <class T>	
string		PQueue<T>::to_string   	(void) const
{
	return bst.to_string(bst.root);
}

#endif

