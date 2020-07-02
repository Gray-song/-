#include <stdio.h>
#include "skip_list.h"
#include <time.h>
#include <stdlib.h>
int main()
{
	p_skip_list list;
	p_skip_list l;
	srand((unsigned)time(NULL));
	list = creat_empty_skip_list();
	insert(5, list);
	insert(6, list);
	insert(8, list);
	insert(3, list);
	insert(10, list);

	insert(9, list);
	insert(1, list);
	insert(12, list);
	insert(14, list);
	insert(11, list);
	l = find(8, list);
	if (l != NULL)
	{
		printf("value = %d,≤„ ˝ = %d\n", l->data, l->max_level);
	}
	else
	{
		printf("Œ¥’“µΩ\n");
	}

	printf("hello skip_list\n");
	skip_list_show(list);
	delete_element(8, list);
	delete_element(8, list);
	skip_list_show(list);
	

}