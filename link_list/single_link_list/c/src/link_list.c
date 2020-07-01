/**
  ******************************************************************************
  * @file    link_list.c
  * @author  gray
  * @version V1.0.0
  * @date    18-June-2020
  * @brief
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
*/
#include "link_list.h"
#include <stdio.h>
#include <malloc.h>
/**
  * @brief  头插法创建链表
  * @note
  * @param  pbuff数组元素，lenth 链表的长度
  * @retval 创建好的链表指针
  ******************************************************************************
  * @attention
  * 该链表是带头结点的单链表
  ******************************************************************************
 */
p_link_list create_link_list_at_head(element_type* pbuff, int lenth)
{
    /*头插法*/
    int i = 0;
    p_link_list new_node;
    p_link_list header = (p_link_list)malloc(sizeof(_LINK_LIST_));
    if (header == NULL)
    {
        /*申请内存失败*/
        return NULL;
    }
    header->next = NULL;
    for (i = 0; i < lenth; i++)
    {
        new_node = (p_link_list)malloc(sizeof(_LINK_LIST_));
        if (new_node == NULL)
        {
            /*申请内存失败*/
            return NULL;
        }
        new_node->data = pbuff[i];
        new_node->next = header->next;
        header->next = new_node;
    }
    return header;
}


/**
  * @brief  尾插法创建链表
  * @note
  * @param  pbuff数组元素，lenth 链表的长度
  * @retval 创建好的链表指针
  ******************************************************************************
  * @attention
  * 该链表是带头结点的单链表
  ******************************************************************************
 */
p_link_list create_link_list_at_last(element_type* pbuff, int lenth)
{
    /*尾插法*/
    int i = 0;
    p_link_list new_node;
    p_link_list previous_node;
    p_link_list header = (p_link_list)malloc(sizeof(_LINK_LIST_));
    if (header == NULL)
    {
        /*申请内存失败，直接返回NULL可能造成内存泄露哦，荣笔者在思量一番进行优化*/
        return NULL;
    }
    header->next = NULL;
    previous_node = header;
    for (i = 0; i < lenth; i++)
    {
        new_node = (p_link_list)malloc(sizeof(_LINK_LIST_));
        if (new_node == NULL)
        {
            /*申请内存失败，直接返回NULL可能造成内存泄露哦，荣笔者在思量一番进行优化*/
            return NULL;
        }
        new_node->data = pbuff[i];
        new_node->next = NULL;
        previous_node->next = new_node;
        previous_node = previous_node->next;
    }
    return header;
}


/**
  * @brief  创建一个空链表
  * @note
  * @param  None
  * @retval 创建好的链表指针
  ******************************************************************************
  * @attention
  * 该链表是带头结点的单链表
  ******************************************************************************
 */
p_link_list create_empty_link_list()
{
    p_link_list header = (p_link_list)malloc(sizeof(_LINK_LIST_));
    if (header == NULL)
    {
        /*申请内存失败*/
        return NULL;
    }
    header->next = NULL;
    return header;
}


/**
  * @brief  判断是否链表为空
  * @note
  * @param  需要判断的链表
  * @retval	TRUE 表示该链表为空 ，FALSE 表示该链表为非空
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
 */
bool is_empty(p_link_list list)
{
    bool is_empty = TRUE;
    if (list->next == NULL)
    {
        is_empty = TRUE;
    }
    else
    {
        is_empty = FALSE;
    }
    return is_empty;
}


/**
  * @brief  查找元素的位置
  * @note
  * @param  data待查元素，list待查链表
  * @retval	若找到则返回该元素所在结点的指针，如未找到则返回NULL
  ******************************************************************************
  * @attention
  * 使用时做好判断下返回值，防止返回空值导致程序崩溃，
  * 该方法查找的是该元素第一在链表中出现的位置
  ******************************************************************************
 */
p_link_list find(element_type data, p_link_list list)
{
    p_link_list temp_node = NULL;
    temp_node = list->next;
    while (temp_node != NULL)
    {
        if (data == temp_node->data)
        {
            break;
        }
        temp_node = temp_node->next;
    }
    return temp_node;
}


/**
 * @brief  查找元素所在结点的前一个结点指针
 * @note
 * @param  data待查元素，list待查链表
 * @retval	若找到则返回该元素所在结点的指针，如未找到则返回链表最后一个结点
 ******************************************************************************
 * @attention
 * 使用时做好判断下返回值，防止返回空值导致程序崩溃，
 * 该方法查找的是该元素第一在链表中出现的位置
 ******************************************************************************
*/
p_link_list find_previous(element_type data, p_link_list list)
{
    p_link_list temp_node = NULL;
    temp_node = list;
    while (temp_node->next != NULL)
    {
        if (data == temp_node->next->data)
        {
            break;
        }
        temp_node = temp_node->next;
    }

    return temp_node;
}



/**
* @brief  将元素data插入到结点pos的下一个位置
* @note
* @param  data插入元素，list被插入的链表，在该方法中目前并未使用，防止以后更新时使用
*         ，所以笔者先将他传入，pos代表要插入的位置
* @retval	TRUE代表插入成功，FALSE代表插入失败
******************************************************************************
* @attention
*
******************************************************************************
*/
bool insert(element_type data, p_link_list list, p_link_list pos)
{
    bool insert_success = TRUE;
    p_link_list new_node = (p_link_list)malloc(sizeof(_LINK_LIST_));
    if (new_node == NULL)
    {
        insert_success = FALSE;
        return insert_success;
    }
    new_node->data = data;
    new_node->next = pos->next;
    pos->next = new_node;
    return insert_success;
}



/**
 * @brief  删除元素data所在结点
 * @note
 * @param  data待删除元素，list待删除链表
 * @retval	None
 ******************************************************************************
 * @attention
 *
 ******************************************************************************
*/
void delete_element(element_type data, p_link_list list)
{
    p_link_list  previous_node = NULL;
    p_link_list temp_node = NULL;
    previous_node = find_previous(data, list);
    if (previous_node->next != NULL)
    {
        temp_node = previous_node->next->next;
        free(previous_node->next);
        previous_node->next = temp_node;
    }
}



/**
* @brief  更新结点pos的元素的值
* @note
* @param  data待更新元素，list被更新的链表，在该方法中目前并未使用，防止以后更新时使用
*         ，所以笔者先将他传入，pos代表要更新的位置
* @retval	None
******************************************************************************
* @attention
*
******************************************************************************
*/
void update(element_type data, p_link_list list, p_link_list pos)
{
    pos->data = data;
}



/**
* @brief  清空链表
* @note
* @param  list待清空链表，
* @retval	None
******************************************************************************
* @attention
* 头节点内存没有释放，该函数只是清除除头结点之外的节点，list并未销毁，所以执行
* 此函数后list让可以从新进行插入删除遍历等操作，若想彻底销毁list,请示用
* destroy_list 方法
******************************************************************************
*/
void clear_list(p_link_list list)
{
    p_link_list temp_next_node = NULL;
    p_link_list temp_node = NULL;
    temp_node = list->next;
    list->next = NULL;
    while (temp_node != NULL)
    {
        temp_next_node = temp_node->next;
        free(temp_node);
        temp_node = temp_next_node;
    }
}


/**
* @brief  显示列表内容
* @note
* @param  list待显示链表，
* @retval	None
******************************************************************************
* @attention
* （index,value）索引从1开始
******************************************************************************
*/
void show_list(p_link_list list)
{
    p_link_list temp_node = NULL;
    int i = 1;
    temp_node = list->next;
    while (temp_node != NULL)
    {
        printf("(%d , %d)\n", i, temp_node->data);
        i++;
        temp_node = temp_node->next;
    }
}


/**
* @brief  获取链表长度
* @note
* @param  list
* @retval	链表接点个数（不包括头结点）
******************************************************************************
* @attention
*
******************************************************************************
*/
int get_list_lenth(p_link_list list)
{
    p_link_list temp_node = NULL;
    int i = 0;
    temp_node = list->next;
    while (temp_node != NULL)
    {

        i++;
        temp_node = temp_node->next;
    }
    return i;
}


/**
 * @brief  获取data的索引
 * @note
 * @param  list
 * @retval	结点索引,若返回-1表示该链表中没有该元素
 ******************************************************************************
 * @attention
 * 该索引返回的是第一次出现的索引
 ******************************************************************************
*/
int get_element_index(element_type data, p_link_list list)
{
    p_link_list temp_node = NULL;
    int i = 1;
    temp_node = list->next;
    while (temp_node != NULL)
    {
        if (data == temp_node->data)
        {
            break;
        }
        i++;
        temp_node = temp_node->next;
    }
    if (temp_node == NULL)
    {
        /*未找到该元素*/
        i = -1;
    }
    return i;
}


/**
* @brief  链表反转
* @note
* @param  list
* @retval
******************************************************************************
* @attention
*
******************************************************************************
*/
void reverse_list(p_link_list list)
{
    p_link_list cur_node_new_next = NULL;
    p_link_list p_cursor = NULL;
    p_link_list current_node = NULL;
    p_cursor = list->next;
    current_node = list->next;
    while (p_cursor != NULL)
    {
        /*保存当前指针的后驱指针*/
        p_cursor = p_cursor->next;
        /*更改当前结点的后驱指针指向*/
        current_node->next = cur_node_new_next;
        /*使新的后驱指针指向当前结点*/
        cur_node_new_next = current_node;
        /*更新current_node指向p_cursor*/
        current_node = p_cursor;
    }
    /*更改头指针指向*/
    list->next = cur_node_new_next;
}


/**
* @brief  销毁链表
* @note
* @param  list
* @retval
******************************************************************************
* @attention
*
******************************************************************************
*/
void destroy_list(p_link_list list)
{
    clear_list(list);
    free(list);
    list = NULL;

}


/**
* @brief  使用头插法创建循环链表
* @note
* @param  pbuff链表数据，lenth链表长度
* @retval 创建好的链表
******************************************************************************
* @attention
*
******************************************************************************
*/
p_link_list create_cycle_link_list_at_head(element_type* pbuff, int lenth)
{
    p_link_list header = (p_link_list)malloc(sizeof(_LINK_LIST_));
    p_link_list new_node = NULL;
    int i = 0;
    if (header == NULL)
    {
        /*申请内存失败*/
        return NULL;
    }
    header->next = header;
    for (i = 0; i < lenth; i++)
    {
        new_node = (p_link_list)malloc(sizeof(_LINK_LIST_));
        if (new_node == NULL)
        {
            /*申请内存失败，直接返回NULL可能造成内存泄露哦，荣笔者在思量一番进行优化*/
            return NULL;
        }
        new_node->data = pbuff[i];
        new_node->next = header->next;
        header->next = new_node;

    }
    return header;
}


/**
* @brief  使用尾插法创建循环链表
* @note
* @param  pbuff链表数据，lenth链表长度
* @retval 创建好的链表
******************************************************************************
* @attention
*
******************************************************************************
*/
p_link_list create_cycle_link_list_at_last(element_type* pbuff, int lenth)
{
    p_link_list header = (p_link_list)malloc(sizeof(_LINK_LIST_));
    p_link_list new_node = NULL;
    p_link_list temp_node = NULL;
    int i = 0;
    if (header == NULL)
    {
        return NULL;
    }
    header->next = header;
    temp_node = header;
    for (i = 0; i < lenth; i++)
    {
        new_node = (p_link_list)malloc(sizeof(_LINK_LIST_));
        if (new_node == NULL)
        {
            /*申请内存失败，直接返回NULL可能造成内存泄露哦，荣笔者在思量一番进行优化*/
            return NULL;
        }
        new_node->data = pbuff[i];
        new_node->next = temp_node->next;
        temp_node->next = new_node;
        temp_node = new_node;
    }
    return header;
}


/**
* @brief  创建空循环链表
* @note
* @param  pbuff链表数据，lenth链表长度
* @retval 创建好的链表
******************************************************************************
* @attention
*
******************************************************************************
*/
p_link_list create_cycle_empty_link_list()
{
    p_link_list header = (p_link_list)malloc(sizeof(_LINK_LIST_));
    if (header == NULL)
    {
        /*申请内存失败*/
        return NULL;
    }
    header->next = header;
    return header;

}


/**
* @brief  显示列表内容
* @note
* @param  list待显示链表，
* @retval	None
******************************************************************************
* @attention
* （index,value）索引从1开始
******************************************************************************
*/
void show_cycle_link_list(p_link_list list)
{
    p_link_list p_cursor = NULL;
    int i = 1;
    p_cursor = list->next;
    while (p_cursor != list)
    {
        printf("(%d , %d)\n", i, p_cursor->data);
        i++;
        p_cursor = p_cursor->next;
    }
}


/**
* @brief  判断循环链表是否为空链表
* @note
* @param  list待显示链表，
* @retval	TRUE 为空，FALSE 为非空
******************************************************************************
* @attention
* （
******************************************************************************
*/
bool is_empty_cycle_link_list(p_link_list  list)
{
    bool is_empty = TRUE;
    if (list->next == list)
    {
        is_empty = TRUE;

    }
    else
    {
        is_empty = FALSE;
    }
    return is_empty;
}


/**
* @brief  循环链表查找元素data所在结点
* @note
* @param  list待待查链表，data
* @retval	元素data所在结点，若未找到返回null
******************************************************************************
* @attention
*
******************************************************************************
*/
p_link_list find_cycle_link_list(element_type data, p_link_list list)
{
    p_link_list p_cursor = NULL;
    p_cursor = list->next;
    while (p_cursor != list)
    {
        if (p_cursor->data == data)
        {
            break;
        }
        p_cursor = p_cursor->next;
    }
    if (p_cursor == list)
    {
        p_cursor = NULL;
    }
    return p_cursor;
}


/**
* @brief  循环链表查找元素data所在结点的前驱结点
* @note
* @param  list待待查链表，data
* @retval	元素data所在结点，若未找到返回null
******************************************************************************
* @attention
*
******************************************************************************
*/
p_link_list find_previous_cycle_link_list(element_type data, p_link_list list)
{
    p_link_list p_cursor = NULL;
    p_cursor = list;
    while (p_cursor->next != list)
    {
        if (p_cursor->next->data == data)
        {
            break;
        }
        p_cursor = p_cursor->next;
    }
    if (p_cursor->next == list)
    {
        p_cursor = NULL;
    }
    return p_cursor;
}


/**
* @brief  循环链表删除元素data所在结点
* @note
* @param  list，data
* @retval	
******************************************************************************
* @attention
*
******************************************************************************
*/
void delete_element_cycle_link_list(element_type data, p_link_list list)
{
    p_link_list previous_node = NULL;
    p_link_list temp_node = NULL;
    previous_node = find_previous_cycle_link_list(data, list);
    if (previous_node->next != NULL)
    {
        /*判断该元素前一个节点不是最后一个节点*/
        
        temp_node = previous_node->next;
        previous_node->next = previous_node->next->next;
        free(temp_node);
    }
    
}


/**
* @brief  清空循环链表
* @note
* @param  list，data
* @retval
******************************************************************************
* @attention
* 头节点内存没有释放，该函数只是清除除头结点之外的节点，list并未销毁，所以执行
* 此函数后list让可以从新进行插入删除遍历等操作，若想彻底销毁list,请示用
* destroy_cycle_list 方法
******************************************************************************
*/
void clear_cycle_link_list(p_link_list list)
{
    p_link_list p_cursor = NULL;
    p_link_list temp_node = NULL;
    p_cursor = list->next;
    list->next = list;
    while (p_cursor != list)
    {
        temp_node = p_cursor->next;
        free(p_cursor);
        p_cursor = temp_node;
    }
}


/**
* @brief  获取循环链表长度
* @note
* @param  list
* @retval	链表接点个数（不包括头结点）
******************************************************************************
* @attention
*
******************************************************************************
*/
int get_cycle_list_lenth(p_link_list list)
{
    int i = 0;
    p_link_list p_cursor = NULL;
    p_cursor = list->next;
    while (p_cursor != list)
    {
        i++;
        p_cursor = p_cursor->next;
    }
    return i;
}


/**
 * @brief  获取循环data的索引
 * @note
 * @param  list
 * @retval	结点索引,若返回-1表示该链表中没有该元素
 ******************************************************************************
 * @attention
 * 该索引返回的是第一次出现的索引
 ******************************************************************************
*/
int get_cycle_list_element_index(element_type data, p_link_list list)
{
    int i = 1;
    p_link_list p_cursor = NULL;
    p_cursor = list->next;
    while (p_cursor != list)
    {
        if (p_cursor->data == data)
        {
            break;
        }
        i++;
        p_cursor = p_cursor->next;
    }
    if (p_cursor == list)
    {
        /*未找到该元素*/
        i = -1;
    }
    return i;
}


/**
* @brief  循环链表反转
* @note
* @param  list
* @retval
******************************************************************************
* @attention
*
******************************************************************************
*/
void reverse_cycle_list(p_link_list list)
{
    p_link_list p_cursor = NULL;
    p_link_list temp_node = NULL;
    p_link_list new_next_node = NULL;
    p_cursor = list->next;
    temp_node = list->next;
    new_next_node = list;
    while (p_cursor != list)
    {
        p_cursor = p_cursor->next;
        temp_node->next = new_next_node;
        new_next_node = temp_node;
        temp_node = p_cursor;

    }
    list->next = new_next_node;
}


/**
* @brief  销毁循环链表
* @note
* @param  list
* @retval
******************************************************************************
* @attention
*
******************************************************************************
*/
void destroy_cycle_list(p_link_list list)
{
    clear_cycle_link_list(list);
    free(list);
    list = NULL;
}
