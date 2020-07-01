#include "stack_array.h"
#include <iostream>
using namespace std;

STACK::STACK()
{

	this->capacity = 5;
	this->topofstack = -1;
	this->array = new int[this->capacity];
}

STACK::STACK(int cap)
{
	/* */
	cout << "this is you can gouzao" << endl;
	this->capacity = cap;
	this->topofstack = -1;
	this->array = new int[this->capacity];
}

STACK::~STACK()
{
	cout << "this isÎö¹¹" << endl;
	delete[] this->array;
	this->capacity = 0;
	this->topofstack = -1;
}


bool STACK::is_empty()
{
	bool is_empty = true;
	if (this->topofstack != -1)
	{
		is_empty = false;
	}
	return is_empty;
}

bool STACK::is_full()
{
	bool is_full = false;
	if (this->capacity == this->topofstack)
	{
		is_full = true;
	}
	return is_full;
}


void STACK::push(int data)
{
	int* temp;
	int i;
	this->topofstack++;
	if (this->topofstack >= this->capacity)
	{
		/*¶¯Ì¬À©ÈÝ*/
		temp = new int[this->capacity * 2];
		for (i = 0; i < this->topofstack; i++)
		{
			temp[i] = this->array[i];
		}
		delete[] this->array;
		this->array = temp;
		this->capacity = this->capacity * 2;
	}
	this->array[this->topofstack] = data;

}

int STACK::pop()
{

	if (this->topofstack == -1)
	{
		cout << "stack is null" << endl;
		return -1;
	}
	return this->array[this->topofstack--];
}

void STACK::clear_stack()
{
	while (this->topofstack != -1)
	{
		pop();
	}
}