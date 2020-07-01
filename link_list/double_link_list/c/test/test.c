#include <stdio.h>
#include "double_link_list.h"
int main()
{
	bool is_empty = TRUE;
	p_double_link_list link_empty = NULL;
	p_double_link_list cycle_link_empty = NULL;
	printf("hello double link list\n");

	printf("-----------------is_empty_double_link test--------------------\n");
	link_empty = create_empty_double_link_list();
	is_empty = is_empty_double_link(link_empty);
	printf("link_empty is empty? yes(1)/no(0):%d\n", is_empty);

	printf("-----------------insert_double_link test--------------------\n");
	insert_double_link(1, link_empty);
	is_empty = is_empty_double_link(link_empty);
	printf("link_empty is empty? yes(1)/no(0):%d\n", is_empty);
	show_double_link(link_empty);

	printf("-----------------find_double_link test--------------------\n");
	insert_double_link(2, find_double_link(1, link_empty));
	is_empty = is_empty_double_link(link_empty);
	printf("link_empty is empty? yes(1)/no(0):%d\n", is_empty);
	show_double_link(link_empty);

	printf("-----------------find_double_link test--------------------\n");
	insert_double_link(3, find_double_link(1, link_empty));
	is_empty = is_empty_double_link(link_empty);
	printf("link_empty is empty? yes(1)/no(0):%d\n", is_empty);
	show_double_link(link_empty);

	printf("-----------------del_element_double_link test--------------------\n");
	del_element_double_link(3, find_double_link(1, link_empty));
	is_empty = is_empty_double_link(link_empty);
	printf("link_empty is empty? yes(1)/no(0):%d\n", is_empty);
	show_double_link(link_empty);

	printf("-----------------clear_double_link test--------------------\n");
	clear_double_link(link_empty);
	is_empty = is_empty_double_link(link_empty);
	printf("link_empty is empty? yes(1)/no(0):%d\n", is_empty);
	show_double_link(link_empty);

	printf("-----------------insert_double_link test--------------------\n");
	insert_double_link(1, link_empty);
	insert_double_link(2, find_double_link(1, link_empty));
	insert_double_link(3, find_double_link(2, link_empty));
	is_empty = is_empty_double_link(link_empty);
	printf("link_empty is empty? yes(1)/no(0):%d\n", is_empty);
	show_double_link(link_empty);
	printf("link_empty len:%d\n", get_double_link_lenth(link_empty));
	printf("link_empty index:%d\n", get_double_link_element_index(2, link_empty));
	reverse_double_link(link_empty);
	show_double_link(link_empty);
	//clear_double_link(link_empty);
	update_double_link(3, find_double_link(1, link_empty));
	show_double_link(link_empty);
	printf("link_empty len:%d\n", get_double_link_lenth(link_empty));
	printf("link_empty index:%d\n", get_double_link_element_index(1, link_empty));

	destroy_double_link(link_empty);


	printf("hello double cycle link list\n");

	printf("-----------------create_empty_double_cycle_link test--------------------\n");
	cycle_link_empty = create_empty_double_cycle_link();
	printf("cycle_link_empty is empty? yes(1)/no(0):%d\n", is_empty_double_cycle_link(cycle_link_empty));

	printf("-----------------insert_double_link test--------------------\n");
	insert_double_link(1, cycle_link_empty);
	printf("cycle_link_empty is empty? yes(1)/no(0):%d\n", is_empty_double_cycle_link(cycle_link_empty));
	show_double_cycle_link(cycle_link_empty);
	printf("link_empty len:%d\n", get_double_cycle_link_lenth(cycle_link_empty));
	printf("link_empty index:%d\n", get_double_cycle_link_index(1, cycle_link_empty));
	insert_double_link(2, find_double_cycle_link(1, cycle_link_empty));
	show_double_cycle_link(cycle_link_empty);
	printf("link_empty len:%d\n", get_double_cycle_link_lenth(cycle_link_empty));
	printf("link_empty index:%d\n", get_double_cycle_link_index(1, cycle_link_empty));

	printf("-----------------del_element_double_cycle_link test--------------------\n");
	del_element_double_cycle_link(1, cycle_link_empty);
	show_double_cycle_link(cycle_link_empty);
	printf("link_empty len:%d\n", get_double_cycle_link_lenth(cycle_link_empty));
	printf("link_empty index:%d\n", get_double_cycle_link_index(1, cycle_link_empty));

	printf("-----------------clear_double_cycle_link test--------------------\n");
	clear_double_cycle_link(cycle_link_empty);
	show_double_cycle_link(cycle_link_empty);
	printf("cycle_link_empty is empty? yes(1)/no(0):%d\n", is_empty_double_cycle_link(cycle_link_empty));
	printf("link_empty len:%d\n", get_double_cycle_link_lenth(cycle_link_empty));
	printf("link_empty index:%d\n", get_double_cycle_link_index(1, cycle_link_empty));

	printf("-----------------insert_double_link test2--------------------\n");
	insert_double_link(1, cycle_link_empty);
	printf("cycle_link_empty is empty? yes(1)/no(0):%d\n", is_empty_double_cycle_link(cycle_link_empty));
	show_double_cycle_link(cycle_link_empty);
	printf("link_empty len:%d\n", get_double_cycle_link_lenth(cycle_link_empty));
	printf("link_empty index:%d\n", get_double_cycle_link_index(1, cycle_link_empty));
	insert_double_link(2, find_double_cycle_link(1, cycle_link_empty));
	show_double_cycle_link(cycle_link_empty);
	printf("link_empty len:%d\n", get_double_cycle_link_lenth(cycle_link_empty));
	printf("link_empty index:%d\n", get_double_cycle_link_index(1, cycle_link_empty));

	printf("-----------------reverse_double_cycle_link test2--------------------\n");
	reverse_double_cycle_link(cycle_link_empty);
	show_double_cycle_link(cycle_link_empty);
	printf("link_empty len:%d\n", get_double_cycle_link_lenth(cycle_link_empty));
	printf("link_empty index:%d\n", get_double_cycle_link_index(1, cycle_link_empty));

	update_double_link(3, find_double_cycle_link(1, cycle_link_empty));
	show_double_cycle_link(cycle_link_empty);
	printf("link_empty len:%d\n", get_double_cycle_link_lenth(cycle_link_empty));
	printf("link_empty index:%d\n", get_double_cycle_link_index(1, cycle_link_empty));

	destroy_double_cycle_link(cycle_link_empty);
	while (1)
	{
		;
	}
	return 0;
}