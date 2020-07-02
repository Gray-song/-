#ifndef _SKIP_LIST_H_
#define _SKIP_LIST_H_

#define FALSE 0
#define TRUE 1
#ifndef __cplusplus
typedef unsigned char bool;
#endif
#define MAX_LEVEL 5

struct _SKIP_NODE_
{
	int data;
	int max_level;
	struct _SKIP_NODE_** next;
}_SKIP_NODE_;
typedef struct _SKIP_NODE_* p_skip_list;


extern p_skip_list creat_empty_skip_list();
extern p_skip_list find(int data, p_skip_list header);
extern bool insert(int data, p_skip_list header);
extern int skip_list_random(int maxlevel);
extern void skip_list_show(p_skip_list header);
extern bool delete_element(int data, p_skip_list header);
#endif