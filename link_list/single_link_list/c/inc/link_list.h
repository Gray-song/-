/**
  ******************************************************************************
  * @file    link_list.h
  * @author  gray
  * @version V1.0.0
  * @date    18-June-2020
  * @brief
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
*/
#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
#include "typedefs.h"
typedef int element_type;

typedef struct _LINK_LIST_
{
    element_type data;
    struct _LINK_LIST_* next;

}_LINK_LIST_;
typedef struct _LINK_LIST_* p_link_list;
/*single link_list*/
extern p_link_list create_link_list_at_head(element_type* pbuff, int lenth);
extern p_link_list create_link_list_at_last(element_type* pbuff, int lenth);
extern p_link_list create_empty_link_list();
extern bool is_empty(p_link_list  list);
extern p_link_list find(element_type data, p_link_list list);
extern p_link_list find_previous(element_type data, p_link_list list);
extern void delete_element(element_type data, p_link_list list);
extern void clear_list(p_link_list list);
extern void show_list(p_link_list list);
extern int get_list_lenth(p_link_list list);
extern int get_element_index(element_type data, p_link_list list);
extern void reverse_list(p_link_list list);
extern void destroy_list(p_link_list list);

/*single cycle link_list*/
extern p_link_list create_cycle_link_list_at_head(element_type* pbuff, int lenth);
extern p_link_list create_cycle_link_list_at_last(element_type* pbuff, int lenth);
extern p_link_list create_cycle_empty_link_list();
extern void show_cycle_link_list(p_link_list list);
extern bool is_empty_cycle_link_list(p_link_list  list);
extern p_link_list find_cycle_link_list(element_type data, p_link_list list);
extern p_link_list find_previous_cycle_link_list(element_type data, p_link_list list);
extern void delete_element_cycle_link_list(element_type data, p_link_list list);
extern void clear_cycle_link_list(p_link_list list);
extern int get_cycle_list_lenth(p_link_list list);
extern int get_cycle_list_element_index(element_type data, p_link_list list);
extern void reverse_cycle_list(p_link_list list);
extern void destroy_cycle_list(p_link_list list);
/*cycle link list and link list*/
extern bool insert(element_type data, p_link_list list, p_link_list pos);
extern void update(element_type data, p_link_list list, p_link_list pos);

#endif // !_LINK_LIST_H_

