#include "double_link_list.h"
#include <malloc.h>
#include <stdio.h>
p_double_link_list create_empty_double_link_list()
{
	p_double_link_list header = (p_double_link_list)malloc(sizeof(_DOUBLE_LINK_ILIST_));
	if (header == NULL)
	{
		return NULL;
	}
	header->previous = NULL;
	header->next = NULL;
	return header;
}


bool is_empty_double_link(p_double_link_list link)
{
	bool is_empty = TRUE;
	if (link->next == NULL)
	{
		is_empty = TRUE;
	}
	else
	{
		is_empty = FALSE;
	}
	return is_empty;
}


bool insert_double_link(int data, p_double_link_list pos)
{
	bool insert_success = TRUE;
	p_double_link_list new_node = (p_double_link_list)malloc(sizeof(_DOUBLE_LINK_ILIST_));
	if (new_node == NULL)
	{
		insert_success = FALSE;
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
	return insert_success;
}


p_double_link_list find_double_link(int data, p_double_link_list link)
{
	p_double_link_list p_cursor = NULL;
	p_cursor = link->next;
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


void show_double_link(p_double_link_list link)
{
	p_double_link_list p_cursor = NULL;
	int i = 1;
	p_cursor = link->next;
	while (p_cursor != NULL)
	{
		printf("(%d,%d)\n", i, p_cursor->data);
		i++;
		p_cursor = p_cursor->next;
	}
}

void del_element_double_link(int data, p_double_link_list link)
{
	p_double_link_list temp_node = NULL;
	p_double_link_list previous_node = NULL;
	p_double_link_list next_node = NULL;
	temp_node = find_double_link(data, link);
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
	}
}

void clear_double_link(p_double_link_list link)
{
	p_double_link_list current_node = NULL;
	p_double_link_list previous_node = NULL;
	p_double_link_list next_node = NULL;
	current_node = link->next;
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
}

int get_double_link_lenth(p_double_link_list link)
{
	int i = 0;
	p_double_link_list p_cursor = NULL;
	p_cursor = link->next;
	while (p_cursor != NULL)
	{
		i++;
		p_cursor = p_cursor->next;
	}
	return i;
}

int get_double_link_element_index(int data, p_double_link_list link)
{
	int i = 1;
	p_double_link_list p_cursor = NULL;
	p_cursor = link->next;
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

void reverse_double_link(p_double_link_list link)
{
	p_double_link_list current_node = NULL;
	p_double_link_list previous_node = NULL;
	p_double_link_list next_node = NULL;
	p_double_link_list p_cursor = NULL;
	p_cursor = link->next;
	current_node = link->next;
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
	previous_node->previous = link;
	link->next = previous_node;
}

void destroy_double_link(p_double_link_list link)
{
	clear_double_link(link);
	free(link);
	link = NULL;
}

void update_double_link(int data, p_double_link_list pos)
{
	pos->data = data;
}

p_double_link_list create_empty_double_cycle_link()
{
	p_double_link_list header = (p_double_link_list)malloc(sizeof(_DOUBLE_LINK_ILIST_));
	if (header == NULL)
	{
		return NULL;
	}
	header->previous = header;
	header->next = header;
	return header;
}


bool is_empty_double_cycle_link(p_double_link_list link)
{
	bool is_empty = TRUE;
	if ((link->next == link) && (link->previous == link))
	{
		is_empty = TRUE;
	}
	else
	{
		is_empty = FALSE;
	}
	return is_empty;
}


p_double_link_list find_double_cycle_link(int data, p_double_link_list link)
{
	p_double_link_list p_cursor = NULL;
	p_cursor = link->next;
	while (p_cursor != link)
	{
		if (p_cursor->data == data)
		{
			break;
		}
		p_cursor = p_cursor->next;
	}
	if (p_cursor == link)
	{
		/*未找到data*/
		p_cursor = NULL;
	}
	return p_cursor;
}


void show_double_cycle_link(p_double_link_list link)
{
	p_double_link_list p_cursor = NULL;
	int i = 1;
	p_cursor = link->next;
	while (p_cursor != link)
	{
		printf("(%d,%d)\n", i, p_cursor->data);
		i++;
		p_cursor = p_cursor->next;
	}
}


void del_element_double_cycle_link(int data, p_double_link_list link)
{
	p_double_link_list temp_node = NULL;
	p_double_link_list previous_node = NULL;
	p_double_link_list next_node = NULL;
	temp_node = find_double_cycle_link(data, link);
	if (temp_node != NULL)
	{
		previous_node = temp_node->previous;
		next_node = temp_node->next;
		free(temp_node);

		next_node->previous = previous_node;

		previous_node->next = next_node;
	}
}

void clear_double_cycle_link(p_double_link_list link)
{
	p_double_link_list current_node = NULL;
	p_double_link_list previous_node = NULL;
	p_double_link_list next_node = NULL;
	current_node = link->next;
	while (current_node != link)
	{
		previous_node = current_node->previous;
		next_node = current_node->next;
		free(current_node);

		next_node->previous = previous_node;

		previous_node->next = next_node;
		current_node = next_node;
	}
}

int get_double_cycle_link_lenth(p_double_link_list link)
{
	int i = 0;
	p_double_link_list p_cursor = NULL;
	p_cursor = link->next;
	while (p_cursor != link)
	{
		i++;
		p_cursor = p_cursor->next;
	}
	return i;
}


int get_double_cycle_link_index(int  data, p_double_link_list link)
{
	int i = 1;
	p_double_link_list p_cursor = NULL;
	p_cursor = link->next;
	while (p_cursor != link)
	{
		if (data == p_cursor->data)
		{
			break;
		}
		i++;
		p_cursor = p_cursor->next;
	}
	if (p_cursor == link)
	{
		i = -1;
	}
	return i;
}


void reverse_double_cycle_link(p_double_link_list link)
{
	p_double_link_list current_node = NULL;
	p_double_link_list previous_node = link;
	p_double_link_list next_node = NULL;
	p_double_link_list p_cursor = NULL;
	p_cursor = link->next;
	current_node = link->next;
	while (p_cursor != link)
	{
		p_cursor = p_cursor->next;

		next_node = current_node->next;
		current_node->previous = next_node;
		current_node->next = previous_node;
		previous_node = current_node;
		current_node = p_cursor;

	}
	/*最后一个前指针指向头结点，头结点后指针指向最后一个结点*/
	previous_node->previous = link;
	link->next = previous_node;
}


void destroy_double_cycle_link(p_double_link_list link)
{
	clear_double_cycle_link(link);
	free(link);
	link = NULL;
}