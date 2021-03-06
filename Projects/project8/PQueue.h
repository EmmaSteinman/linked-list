//=========================================================
// Emma Steinman
// April 19, 2017
// PQueue.h
// Priority queue implemetation inherited from Queue
//=========================================================

#include <iostream>
#include "Queue.h"
using namespace std;

#ifndef PQUEUE_H
#define PQUEUE_H

template <class T>
class PQueue : public Queue<T>
{
public:
	void	enqueue		(T item);
};

template <class T>
void	PQueue<T>::enqueue	(T item)
{
	for (int i = 0; i < this->list.length(); i++)
	{
		if (item > this->list[i])
		{
			this->list.insert(item, i);
			return;
		}
	}
	this->list.append(item);
}



#endif
