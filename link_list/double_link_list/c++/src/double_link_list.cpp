#include "double_link_list.h"
#include <malloc.h>
#include <iostream>
using namespace std;
DoubleLinkList::DoubleLinkList()
{
	header = (p_double_link_list)malloc(sizeof(_DOUBLE_LINK_ILIST_));
	cout << "this is DoubleLinkList" << endl;
	if (header != NULL)
	{
		header->data = 0;
		header->next = NULL;
		header->previous = NULL;
	}
}


DoubleLinkList::~DoubleLinkList()
{
	cout << "this is ~DoubleLinkList" << endl;
	if ((header->next != NULL) && (header->next != header))
	{
		clear_double_link();
	}

	free(header);
	header = NULL;
}

bool DoubleLinkList::is_empty()
{
	bool is_empty = true;
	cout << "this is is_empty" << endl;
	if (this->header->next == NULL)
	{
		is_empty = true;
	}
	else
	{
		is_empty = false;
	}
	return is_empty;
}


bool DoubleLinkList::insert_double_link(int data, p_double_link_list pos)
{
	bool insert_success = true;
	p_double_link_list new_node = (p_double_link_list)malloc(sizeof(_DOUBLE_LINK_ILIST_));
	cout << "this is insert_double_link" << endl;
	if (new_node == NULL)
	{
		insert_success = false;
		return insert_success;
	}
	new_node->data = data;
	new_node->next = pos->next;
	new_node->previous = pos;
	if (pos->next != NULL)
	{
		/*插在最后*/
		pos->next->previous = new_node;
	}

	pos->next = new_node;
	header->data++;
	return insert_success;
}


p_double_link_list DoubleLinkList::find_double_link(int data)
{
	p_double_link_list p_cursor = NULL;
	cout << "this is find_double_link" << endl;
	p_cursor = this->header->next;
	while (p_cursor != NULL)
	{
		if (p_cursor->data == data)
		{
			break;
		}
		p_cursor = p_cursor->next;
	}
	return p_cursor;
}


void DoubleLinkList::show_double_link()
{
	p_double_link_list p_cursor = NULL;
	int i = 1;
	cout << "this is show_double_link" << endl;
	p_cursor = this->header->next;
	while (p_cursor != NULL)
	{
		printf("(%d,%d)\n", i, p_cursor->data);
		i++;
		p_cursor = p_cursor->next;
	}
}


void DoubleLinkList::del_element_double_link(int data)
{
	p_double_link_list temp_node = NULL;
	p_double_link_list previous_node = NULL;
	p_double_link_list next_node = NULL;
	cout << "this is del_element_double_link" << endl;
	temp_node = find_double_link(data);
	if (temp_node != NULL)
	{
		previous_node = temp_node->previous;
		next_node = temp_node->next;
		free(temp_node);
		if (next_node != NULL)
		{
			next_node->previous = previous_node;

		}
		previous_node->next = next_node;
		header->data--;
	}
}


void DoubleLinkList::clear_double_link()
{
	p_double_link_list current_node = NULL;
	p_double_link_list previous_node = NULL;
	p_double_link_list next_node = NULL;
	cout << "this is clear_double_link" << endl;
	current_node = this->header->next;
	while (current_node != NULL)
	{
		previous_node = current_node->previous;
		next_node = current_node->next;
		free(current_node);
		if (next_node != NULL)
		{
			next_node->previous = previous_node;
		}
		previous_node->next = next_node;
		current_node = next_node;
	}
	header->data = 0;
}

int DoubleLinkList::get_double_link_lenth()
{
	int i = 0;
	p_double_link_list p_cursor = NULL;
	cout << "this is get_double_link_lenth" << endl;
	p_cursor = this->header->next;
	while (p_cursor != NULL)
	{
		i++;
		p_cursor = p_cursor->next;
	}
	return i;
}


int DoubleLinkList::get_double_link_element_index(int data)
{
	int i = 1;
	p_double_link_list p_cursor = NULL;
	cout << "this is get_double_link_element_index" << endl;
	p_cursor = this->header->next;
	while (p_cursor != NULL)
	{
		if (data == p_cursor->data)
		{
			break;
		}
		i++;
		p_cursor = p_cursor->next;
	}
	if (p_cursor == NULL)
	{
		i = -1;
	}
	return i;
}


void DoubleLinkList::reverse_double_link()
{
	p_double_link_list current_node = NULL;
	p_double_link_list previous_node = NULL;
	p_double_link_list next_node = NULL;
	p_double_link_list p_cursor = NULL;
	cout << "this is reverse_double_link" << endl;
	p_cursor = this->header->next;
	current_node = this->header->next;
	while (p_cursor != NULL)
	{
		p_cursor = p_cursor->next;

		next_node = current_node->next;
		current_node->previous = next_node;
		current_node->next = previous_node;
		previous_node = current_node;
		current_node = p_cursor;

	}
	/*最后一个前指针指向头结点，头结点后指针指向最后一个结点*/
	previous_node->previous = this->header;
	this->header->next = previous_node;
}

void DoubleLinkList::update_double_link(int data, p_double_link_list pos)
{
	cout << "this is update_double_link" << endl;
	pos->data = data;
}

p_double_link_list DoubleLinkList::get_header()
{
	cout << "this is get_header" << endl;
	return header;
}


CycleDoubleLinkList::CycleDoubleLinkList()
{
	header = DoubleLinkList::get_header();
	cout << "this is CycleDoubleLinkList" << endl;
	if (header != NULL)
	{
		header->data = 0;
		header->next = header;
		header->previous = header;
	}
}

CycleDoubleLinkList::~CycleDoubleLinkList()
{
	cout << "this is ~CycleDoubleLinkList" << endl;
	clear_double_link();
}

bool CycleDoubleLinkList::is_empty()
{
	bool is_empty = true;
	cout << "this is CycleDoubleLinkList is_empty" << endl;
	if ((header->next == header) && (header->previous == header))
	{
		is_empty = true;
	}
	else
	{
		is_empty = false;
	}
	return is_empty;
}


p_double_link_list CycleDoubleLinkList::find_double_link(int data)
{
	p_double_link_list p_cursor = NULL;
	cout << "this is CycleDoubleLinkList find_double_link" << endl;
	p_cursor = header->next;
	while (p_cursor != header)
	{
		if (p_cursor->data == data)
		{
			break;
		}
		p_cursor = p_cursor->next;
	}
	if (p_cursor == header)
	{
		/*未找到data*/
		p_cursor = NULL;
	}
	return p_cursor;
}


void CycleDoubleLinkList::show_double_link()
{
	p_double_link_list p_cursor = NULL;

	int i = 1;
	cout << "this is CycleDoubleLinkList show_double_link" << endl;
	p_cursor = header->next;
	while (p_cursor != header)
	{
		printf("(%d,%d)\n", i, p_cursor->data);
		i++;
		p_cursor = p_cursor->next;
	}
}

void CycleDoubleLinkList::del_element_double_link(int data)
{
	p_double_link_list temp_node = NULL;
	p_double_link_list previous_node = NULL;
	p_double_link_list next_node = NULL;
	cout << "this is CycleDoubleLinkList del_element_double_link" << endl;
	temp_node = find_double_link(data);
	if (temp_node != NULL)
	{
		previous_node = temp_node->previous;
		next_node = temp_node->next;
		free(temp_node);

		next_node->previous = previous_node;

		previous_node->next = next_node;
	}
}


void CycleDoubleLinkList::clear_double_link()
{
	p_double_link_list current_node = NULL;
	p_double_link_list previous_node = NULL;
	p_double_link_list next_node = NULL;
	cout << "this is CycleDoubleLinkList clear_double_link" << endl;
	current_node = header->next;
	while (current_node != header)
	{
		previous_node = current_node->previous;
		next_node = current_node->next;
		free(current_node);

		next_node->previous = previous_node;

		previous_node->next = next_node;
		current_node = next_node;
	}
}

int  CycleDoubleLinkList::get_double_link_lenth()
{
	int i = 0;
	p_double_link_list p_cursor = NULL;
	cout << "this is CycleDoubleLinkList get_double_link_lenth" << endl;
	p_cursor = header->next;
	while (p_cursor != header)
	{
		i++;
		p_cursor = p_cursor->next;
	}
	return i;
}


int CycleDoubleLinkList::get_double_link_element_index(int data)
{
	int i = 1;
	p_double_link_list p_cursor = NULL;
	cout << "this is CycleDoubleLinkList get_double_link_element_index" << endl;
	p_cursor = header->next;
	while (p_cursor != header)
	{
		if (data == p_cursor->data)
		{
			break;
		}
		i++;
		p_cursor = p_cursor->next;
	}
	if (p_cursor == header)
	{
		i = -1;
	}
	return i;
}


void CycleDoubleLinkList::reverse_double_link()
{
	p_double_link_list current_node = NULL;
	p_double_link_list previous_node = header;
	p_double_link_list next_node = NULL;
	p_double_link_list p_cursor = NULL;
	cout << "this is CycleDoubleLinkList reverse_double_link" << endl;
	p_cursor = header->next;
	current_node = header->next;
	while (p_cursor != header)
	{
		p_cursor = p_cursor->next;

		next_node = current_node->next;
		current_node->previous = next_node;
		current_node->next = previous_node;
		previous_node = current_node;
		current_node = p_cursor;

	}
	/*最后一个前指针指向头结点，头结点后指针指向最后一个结点*/
	previous_node->previous = header;
	header->next = previous_node;
}