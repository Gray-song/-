#include "queue_link.h"
#include <iostream>
#include <malloc.h>
using namespace std;
QUEUE::QUEUE()
{
	header = (p_queue)malloc(sizeof(_NODE_));
	if (header != NULL)
	{
		header->next = NULL;
		tail = header;
	}
}

QUEUE::~QUEUE()
{
	clear_queue();
	free(header);
}

bool QUEUE::is_empty()
{
	bool is_empty = true;
	if (header->next != NULL)
	{
		is_empty = false;
	}
	return is_empty;
}

void QUEUE::enqueue(int data)
{
	p_queue new_node = (p_queue)malloc(sizeof(_NODE_));
	new_node->data = data;
	new_node->next = tail->next;
	tail->next = new_node;
	tail = tail->next;
}


int QUEUE::dequeue()
{
	bool is_empty_status;
	int data;
	p_queue temp;
	is_empty_status = is_empty();
	if (is_empty_status == false)
	{
		data = header->next->data;
		temp = header->next->next;
		free(header->next);
		header->next = temp;
		return data;
	}
	cout << "the queue is empty" << endl;
	return -1;
}


void QUEUE::clear_queue()
{
	bool is_empty_status;
	is_empty_status = is_empty();
	while (is_empty_status == false)
	{
		dequeue();
	}
}