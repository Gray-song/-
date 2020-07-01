#ifndef _DOUBLE_LINK_LIST_H_
#define _DOUBLE_LINK_LIST_H_
#include "typedefs.h"
typedef struct _DOUBLE_LINK_ILIST_
{
	int data;
	struct _DOUBLE_LINK_ILIST_* previous;
	struct _DOUBLE_LINK_ILIST_* next;
}_DOUBLE_LINK_ILIST_;
typedef _DOUBLE_LINK_ILIST_* p_double_link_list;
extern p_double_link_list create_empty_double_link_list();
extern bool is_empty_double_link(p_double_link_list link);
extern bool insert_double_link(int data, p_double_link_list pos);
extern p_double_link_list find_double_link(int data, p_double_link_list link);
extern void show_double_link(p_double_link_list link);
extern void del_element_double_link(int data, p_double_link_list link);
extern void clear_double_link(p_double_link_list link);
extern int get_double_link_lenth(p_double_link_list link);
extern int get_double_link_element_index(int  data, p_double_link_list link);
extern void reverse_double_link(p_double_link_list link);
extern void destroy_double_link(p_double_link_list link);
extern void update_double_link(int data, p_double_link_list pos);
/*Ë«ÏòÑ­»·Á´±í*/
extern p_double_link_list create_empty_double_cycle_link();
extern bool is_empty_double_cycle_link(p_double_link_list link);
extern p_double_link_list find_double_cycle_link(int data, p_double_link_list link);
extern void show_double_cycle_link(p_double_link_list link);
extern void del_element_double_cycle_link(int data, p_double_link_list link);
extern void clear_double_cycle_link(p_double_link_list link);
extern int get_double_cycle_link_lenth(p_double_link_list link);
extern int get_double_cycle_link_index(int  data, p_double_link_list link);
extern void reverse_double_cycle_link(p_double_link_list link);
extern void destroy_double_cycle_link(p_double_link_list link);
#endif

