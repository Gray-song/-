#include <stdio.h>

#include "link_list.h"
int main()
{
    bool link_list_status;
    p_link_list list_at_head = NULL;
    p_link_list list_empty = NULL;
    p_link_list list_at_list = NULL;
    p_link_list temp = NULL;
    p_link_list pos = NULL;
    p_link_list list_cycle = NULL;
    p_link_list list_cycle_at_last = NULL;
    p_link_list list_cycle_empty = NULL;
    element_type buff[5] = { 0,1,2,3,4 };

    list_at_head = create_link_list_at_head(buff, 5);
    list_empty = create_empty_link_list();
    list_at_list = create_link_list_at_last(buff, 5);
    delete_element(0, list_at_head);
    temp = find(2, list_at_head);
    update(8, list_at_head, temp);
    insert(6, list_at_head, temp);



    //insert(78,list_empty,list_empty);
    show_list(list_empty);
    show_list(list_at_list);
    printf("index :%d\n", get_element_index(5, list_at_list));

    printf("list_at_head len :%d\n", get_list_lenth(list_at_head));
    show_list(list_at_head);
    clear_list(list_at_head);
    link_list_status = is_empty(list_at_head);
    printf("list_at_head is empty %d\n", link_list_status);
    link_list_status = is_empty(list_empty);
    printf("list_empty is empty %d\n", link_list_status);

    reverse_list(list_at_list);
    show_list(list_at_list);

    /*释放内存*/

    destroy_list(list_at_head);
    destroy_list(list_at_list);
    destroy_list(list_empty);
    
    printf("----------------------------------\n");
    list_cycle = create_cycle_link_list_at_head(buff, 5);
    //show_list(list_cycle);
    show_cycle_link_list(list_cycle);
    list_cycle_at_last = create_cycle_link_list_at_last(buff, 5);
    show_cycle_link_list(list_cycle_at_last);
    list_cycle_empty = create_cycle_empty_link_list();
    link_list_status = is_empty_cycle_link_list(list_cycle_empty);
    printf("cycle_list_empty is empty %d\n", link_list_status);
    pos = find_cycle_link_list(3, list_cycle);
    if (pos == NULL)
    {
        printf(" 未找到\n");
    }
    else
    {
        printf("  %d\n", pos->data);
        insert(6, list_cycle, pos);
    }
    printf("1----------------------------------\n");
    show_cycle_link_list(list_cycle);
    printf("2----------------------------------\n");
    delete_element_cycle_link_list(6, list_cycle);
    show_cycle_link_list(list_cycle);
    printf("3----------------------------------\n");
    printf("list_cycle len :%d\n", get_cycle_list_lenth(list_cycle));
    printf("list_cycle index :%d\n", get_cycle_list_element_index(3,list_cycle));
    printf("4----------------------------------\n");
    reverse_cycle_list(list_cycle);
    show_cycle_link_list(list_cycle);
    printf("5----------------------------------\n");
    pos = find_previous_cycle_link_list(3, list_cycle);
    if (pos == NULL)
    {
        printf(" 1未找到\n");
    }
    else
    {
        printf("  %d\n", pos->data);
    }
    clear_cycle_link_list(list_cycle);
    printf("6----------------------------------\n");
    printf("list_cycle len :%d\n", get_cycle_list_lenth(list_cycle));
    show_cycle_link_list(list_cycle);
    destroy_cycle_list(list_cycle);
    
   
    while (1)
    {
        ;
    }
    return 0;
}