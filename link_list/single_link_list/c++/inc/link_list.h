/**
  ******************************************************************************
  * @file    link_list.h
  * @author  gray
  * @version V1.0.0
  * @date    23-June-2020
  * @brief
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
*/
#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
#include <iostream>
typedef struct _LINK_LIST_
{
	int data;
	struct _LINK_LIST_* next;
}_LINK_LIST_;

typedef _LINK_LIST_* p_link_list;

class LinkList
{
public:
	LinkList();
	~LinkList();
	bool insert(int data, p_link_list pos);
	bool is_empty();
	void update(int data, p_link_list pos);
	p_link_list find(int data);
	p_link_list find_previous(int data);
	void delete_element(int data);
	void clear_list();
	void show_list();
	int get_list_lenth();
	int get_element_index(int data);
	void reverse_list();
	p_link_list get_header();
private:
	p_link_list header;
};


class CycleLinkList : public LinkList
{
public:
	/*需要重写方法*/
	CycleLinkList();
	~CycleLinkList();
	bool is_empty();
	p_link_list find(int data);
	p_link_list find_previous(int data);
	void clear_list();
	void show_list();
	int get_list_lenth();
	int get_element_index(int data);
	void reverse_list();
	void delete_element(int data);

private:
	p_link_list header;
};

#endif