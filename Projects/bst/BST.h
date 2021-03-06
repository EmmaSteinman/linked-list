//=================================================================================
// Emma Steinman, Yow Yong, Sam Strosnider 
// BST.h
// May 1, 2017
// This is the header file for the BST class. It contains methods to create and 
// modify binary search trees.
//=================================================================================

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
using namespace std;

//=================================================================================

#ifndef BST_H
#define BST_H

template <class T>
struct Node
{
    T       	data;
    Node *  	left;
    Node *  	right;
};

template <class T>
class BST
{
public:
    Node<T> * root;        		// root pointer for binary search tree
                BST         	( void );
               ~BST         	( void );
                BST         	( const BST<T> & );
    BST<T>      operator=   	( const BST<T> & );
    void        copy        	( Node<T> * );
    void        insert      	( Node<T> *&ptr, T item );
    void        remove      	( T item );
    Node<T> *   find        	( Node<T> *, T item ) const;
    Node<T> *   findBiggest 	( Node<T> * ) const;
    void        clear       	( Node<T> *& );
    int         length      	( Node<T> * ) const;
    bool        isEmpty     	( void ) const;
    string      to_string   	( Node<T> * ) const;
    friend ostream & operator<< ( ostream &os, const BST<T> &bst )
    {
        os << bst.to_string(bst.root);
        return os;
    }
    
};


//=================================================================================
// Default Constructor
// Initializes a new empty BST.
//=================================================================================
template <class T>	
		BST<T>::BST 			(void)
{
	root = NULL;  
}

//=================================================================================
// Copy Constructor
// Copies elements from existing BST to a new BST.
//=================================================================================

template <class T>
		BST<T>::BST				(const BST<T> &bst) 
{	
	root = NULL;		
	copy(bst.root);	
}
	
//=================================================================================
// Destructor
// Cleans up the memory of the BST (pointer).
//=================================================================================

template <class T>
		BST<T>::~BST			(void)
{
	clear(root);
}

//=================================================================================
// isEmpty
// Returns TRUE if the BST is empty, FALSE otherwise. 
//=================================================================================

template <class T>
bool  	BST<T>::isEmpty			(void) const
{
	return (root == NULL);
}

//=================================================================================
// length
// Return the number of items in the BST.
//=================================================================================

template <class T>
int 	BST<T>::length 			(Node <T> *ptr) const
{
	if (ptr == NULL)
		return 0;

	else
		return 1 + length(ptr->left)+ length(ptr->right);
}

//=================================================================================
// Operator =
// Assigns an existing BST to a new BST.
//=================================================================================

template <class T>
BST<T> 	BST<T>::operator=		(const BST<T> &bst) 
{	
	clear(root);	
	copy(bst.root);
	return *this;
}

//=================================================================================
// to_string
// ”Prints” the BST contents to a string and returns that string.
//=================================================================================

template <class T>
string BST<T>::to_string 		(Node <T> *ptr) const
{	
	stringstream ls;
	if (ptr == NULL)
		return ls.str();

	else 
		ls << to_string(ptr->left) << ptr->data << ' ' << to_string(ptr->right); 

	return ls.str(); 
}

//=================================================================================
// Insert
// Insert a new item at specified index.
//=================================================================================

template <class T>
void 	BST<T>::insert			(Node <T> *&ptr, T item)
{	
	if (ptr == NULL)
	{
		ptr = new Node <T>;				//at NULL ptr, creates new node, 
		ptr->left = NULL;				//and sets left and right pointers
		ptr->right = NULL;
		ptr->data = item;		
	}

	else if (ptr->data <item)
		insert(ptr->right, item);	

	else
		insert(ptr->left,item);	
		
}

//=================================================================================
// Remove
// Removes an item at a specified location. 
//=================================================================================

template <class T>
void	BST<T>::remove 			(T item)
{ 
	
	Node<T>*ptr = find(root,item);
	Node<T>*qtr = root;
	if (ptr == NULL)
	{	
		cout<<"Error: Item not found!!" << endl;
		exit(1);
	}


	if (ptr->data == root->data)						// remove root
	{		
		
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		else if (ptr->left == NULL)
		{
			root = ptr->right;
			delete qtr;
		}
		else
		{										
			Node<T> * rtr = findBiggest(ptr->left);
			rtr->right = root->right;
			root = ptr->left;
			delete qtr;
		}
		return;
	}

	while (qtr->left != ptr && qtr->right != ptr)		//finding parent 
	{
		if (item < qtr->data)
			qtr = qtr->left;
		else if (item > qtr->data)
			qtr = qtr->right;
	}

	if (ptr->left == NULL && ptr->right == NULL)		// remove leaves
	{
		if (qtr->left == ptr)
			qtr->left = NULL;
		if (qtr->right == ptr)
			qtr->right = NULL;
	}

	else if (ptr->left == NULL)							// remove parent with right child
	{
		if (qtr->left == ptr)
			qtr->left = ptr->right;
		if (qtr->right == ptr)
			qtr->right = ptr->right;
	}

	else												// remove parent with two children
	{
		Node<T> * rtr = findBiggest(ptr->left);
		if (qtr->left == ptr)
		{
			rtr->right = ptr->right;
			qtr->left = ptr->left;
		}
		if (qtr->right == ptr)
		{	
			rtr->right = ptr->right;
			qtr->right = ptr->left;
		}

	}	
	delete ptr;
		
}

//=================================================================================
// clear
// Clears tree
//=================================================================================

template <class T>
void 		BST<T>::clear 		(Node<T> *&ptr)
{
	if (ptr)
	{
		clear (ptr->left);
		clear (ptr->right);
		delete ptr;
		ptr = NULL;				
	}
	
}

//=================================================================================
// find
// Finds specified item from given pointer
//=================================================================================

template <class T>
Node<T> *   BST<T>::find        (Node<T> *ptr, T item ) const
{
	if (ptr == NULL)
		return NULL;

	if (ptr->data == item)
		return ptr;

	if (item < ptr->data)
		find(ptr->left, item);

	else
		find(ptr->right, item);	
}

//=================================================================================
// findBiggest
// Finds biggest item in tree from given pointer
//=================================================================================

template <class T>
Node<T> *   BST<T>::findBiggest (Node<T> *ptr) const
{
	if (ptr == NULL)
		return ptr;

	while (ptr->right != NULL)
		ptr = ptr->right;

	return ptr;
}
	
//=================================================================================
// copy
// Copies values from one tree to another
//=================================================================================

template <class T>
void 		BST<T>::copy 		(Node<T> *ptr) 
{	
	if (ptr)
	{
		insert(root, ptr->data);
		copy(ptr->left);
		copy(ptr->right);
	}

}
	


#endif



