//====================================================
// Emma Steinman
// March 31, 2017
// llist.h
// This program illustrates simple linked list 
// operations.
//====================================================

#include <iostream>
using namespace std;


//====================================================
// 
//====================================================

struct Node
{
	int 	data;
	Node*	next;
};

void	printList	(Node * head);
Node	*insertList	(Node *head, int item);
int		length		(Node *head);
Node	*clear		(Node *head);
//====================================================
// main
//====================================================
int main (void)
{
	Node * head = NULL;

	printList(head);

	head = insertList(head, 1);
	head = insertList(head, 2);
	head = insertList(head, 3);
	printList(head);

	cout << "Length = " << length(head) << endl;
	
	head = clear(head);
	cout << "Length = " << length(head) << endl;
	return 0;
}

//====================================================
// printList
// This function prints the items in a linked list
//====================================================

void	printList(Node *head)
{
	Node * ptr = head;
	cout << "List : ";
	while (ptr != NULL)
	{
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}
//====================================================
// insertList
// This function inserts new item at end of linked list
//====================================================

Node * insertList(Node *head, int item)
{
	Node * ptr = new Node;
	ptr->data = item;
	ptr->next = NULL;

	if (head == NULL)
	{
		// case 1: change empty list
		head = ptr;
	}
	else
	{
		// case 2; insert at end of non empty list
		Node * qtr = head;
		while (qtr->next != NULL)
			qtr = qtr->next;
		qtr->next = ptr;
	}
	return head;
}


//====================================================
// length
// This function returns the length of the linked list
//====================================================

int	length	(Node *head)
{
	Node * ptr = head;
	int count = 0;
	while ( ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return count;
}

//====================================================
// clear
// This function clears the elements in a linked list
//====================================================

Node* clear	(Node *head)
{
	Node *ptr, *qtr;
	ptr = qtr = head;	
	while (ptr != NULL)
	{
		qtr = ptr->next;
		delete ptr;
		ptr = qtr;
	}
	return NULL;
}
