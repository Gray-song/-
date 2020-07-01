#ifndef _DOUBLE_LINK_LIST_H_
#define _DOUBLE_LINK_LIST_H_
typedef struct _DOUBLE_LINK_ILIST_
{
	int data;
	struct _DOUBLE_LINK_ILIST_* previous;
	struct _DOUBLE_LINK_ILIST_* next;
}_DOUBLE_LINK_ILIST_;
typedef _DOUBLE_LINK_ILIST_* p_double_link_list;

class DoubleLinkList
{
public:
	DoubleLinkList();
	~DoubleLinkList();
	bool is_empty();
	bool insert_double_link(int data, p_double_link_list pos);
	p_double_link_list find_double_link(int data);
	void show_double_link();
	void del_element_double_link(int data);
	void clear_double_link();
	int get_double_link_lenth();
	int get_double_link_element_index(int data);
	void reverse_double_link();
	void update_double_link(int data, p_double_link_list pos);
	p_double_link_list get_header();
private:
	p_double_link_list header;
};


class CycleDoubleLinkList : public DoubleLinkList
{
public:
	CycleDoubleLinkList();
	~CycleDoubleLinkList();
	bool is_empty();
	p_double_link_list find_double_link(int data);
	void show_double_link();
	void del_element_double_link(int data);
	void clear_double_link();
	int get_double_link_lenth();
	int get_double_link_element_index(int data);
	void reverse_double_link();
private:
	p_double_link_list header;
};
#endif