#include "queue_array.h"
#include <iostream>
#include <malloc.h>
using namespace std;

Queue::Queue()
{
	capacity = 5;
	head = 0;
	tail = 0;
	array = (int*)malloc((sizeof(int) * capacity));
}

Queue::Queue(int cap)
{
	capacity = cap;
	head = 0;
	tail = 0;
	array = (int*)malloc((sizeof(int) * capacity));
}

Queue ::~Queue()
{
	cout << "this is Îö¹¹" << endl;
	capacity = 0;
	head = 0;
	tail = 0;
	free(array);
}

bool Queue::is_empty()
{
	bool is_empty = true;
	if (head != tail)
	{
		is_empty = false;
	}
	return is_empty;
}

bool Queue::is_full()
{
	bool is_full = false;
	if ((tail == capacity) && (head == 0))
	{
		is_full = true;
	}
	return is_full;
}

void Queue::enqueue(int data)
{
	int i = 0;
	if (tail == capacity)
	{
		if (head == 0)
		{
			cout << "The queue is full`````" << endl;
			return;
		}
		else
		{
			for (i = head; i < tail; i++)
			{
				array[i - head] = array[i];
			}
			tail = tail - head;
			head = 0;

		}
	}

	array[tail] = data;
	tail++;

}

int Queue::dequeue()
{
	int data;
	if (head < tail)
	{
		data = array[head];
		head++;
	}
	else
	{
		cout << "the queue is empty" << endl;
		data = -1;
	}
	return data;
}

void Queue::clear_queue()
{
	head = tail;
}


CycleQueue::CycleQueue()
{
	capacity = 5;
	head = 0;
	tail = 0;
	empty_flag = true;
	full_flag = false;
	array = (int*)malloc((sizeof(int) * capacity));
}

CycleQueue::CycleQueue(int cap)
{
	capacity = cap;
	head = 0;
	tail = 0;
	empty_flag = true;
	full_flag = false;
	array = (int*)malloc((sizeof(int) * capacity));
}


CycleQueue::~CycleQueue()
{
	capacity = 0;
	head = 0;
	tail = 0;
	empty_flag = true;
	full_flag = false;
	free(array);
}


void CycleQueue::enqueue(int data)
{
	if (full_flag == false)
	{
		array[tail] = data;
		tail++;
		empty_flag = false;
		if (tail >= capacity)
		{
			tail = 0;
		}
		if (tail == head)
		{
			/*the queue is full*/

			full_flag = true;

		}

	}
	else
	{
		cout << "the queue is full.............." << endl;
	}


}

int CycleQueue::dequeue()
{
	int data;
	if (empty_flag == false)
	{
		data = array[head];
		head++;
		full_flag = false;
		if (head >= capacity)
		{
			head = 0;
		}
		if (head == tail)
		{
			/*the queue is empty*/

			empty_flag = true;

		}

	}
	else
	{
		cout << "the queue is empty................" << endl;
		data = -1;
	}
	return data;

}


bool CycleQueue::is_empty()
{
	return empty_flag;
}

bool CycleQueue::is_full()
{
	return full_flag;
}

void CycleQueue::clear_queue()
{
	head = 0;
	tail = 0;
	empty_flag = true;
	full_flag = false;
}