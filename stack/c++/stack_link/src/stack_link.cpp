#include "stack_link.h"
#include <iostream>
using namespace std;

STACK::STACK()
{
	cout << "this is 构造函数" << endl;
	header = new _NODE_;
	header->next = NULL;
}

STACK::~STACK()
{
	cout << "this is 析构函数" << endl;
	clearstack();
	delete header;
}

bool STACK::is_empty()
{
	bool is_empty = true;
	cout << "this is is_empty" << endl;
	if (header->next != NULL)
	{
		is_empty = false;
	}
	return is_empty;

}

void STACK::push(int data)
{
	p_stack new_node = new _NODE_;

	cout << "this is push" << endl;

	new_node->data = data;
	new_node->next = header->next;
	header->next = new_node;

}

int STACK::pop()
{
	p_stack temp_node = NULL;
	int temp;
	cout << "this is pop" << endl;
	if (header->next != NULL)
	{
		temp = header->next->data;
		temp_node = header->next->next;
		delete header->next;
		header->next = temp_node;
		return temp;
	}
	else
	{
		cout << "stack is null" << endl;
		return -1;
	}

}

void STACK::clearstack()
{
	cout << "this is clearstack" << endl;
	while (header->next != NULL)
	{
		pop();
	}
}