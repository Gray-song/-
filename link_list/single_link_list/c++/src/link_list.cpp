/**
  ******************************************************************************
  * @file    link_list.cpp
  * @author  gray
  * @version V1.0.0
  * @date    23-June-2020
  * @brief
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
*/
#include "link_list.h"
#include <malloc.h>
#include <iostream>
using namespace std;


/**
  * @brief  构造函数
  * @note
  * @param
  * @retval
  ******************************************************************************
  * @attention
  * 该链表是带头结点的单链表
  ******************************************************************************
 */
LinkList::LinkList()
{
    this->header = (p_link_list)malloc(sizeof(_LINK_LIST_));
    //cout << "this is LinkList LinkList"<<endl;
    if (this->header != NULL)
    {
        this->header->next = NULL;
        this->header->data = 0;  //用来存储结点长度
    }

}


/**
  * @brief  析构函数
  * @note
  * @param
  * @retval
  ******************************************************************************
  * @attention
  * 该链表是带头结点的单链表
  ******************************************************************************
 */
LinkList ::~LinkList()
{
    //cout << "this is LinkList ~LinkList"<<endl;
    if ((this->header->next != NULL) && (this->header->next != this->header))
    {
        this->clear_list();
    }

    free(this->header);
}


/**
* @brief  将元素data插入到结点pos的下一个位置
* @note
* @param  data插入元素，pos代表要插入的位置
* @retval	TRUE代表插入成功，FALSE代表插入失败
******************************************************************************
* @attention
*
******************************************************************************
*/
bool LinkList::insert(int data, p_link_list pos)
{
    p_link_list new_node = (p_link_list)malloc(sizeof(_LINK_LIST_));
    //cout << "this is LinkList insert"<<endl;
    if (new_node == NULL)
    {

        return false;
    }
    new_node->data = data;
    new_node->next = pos->next;
    pos->next = new_node;
    this->header->data++;
    return true;
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
bool LinkList::is_empty()
{
    bool is_empty = true;
    //cout << "this is LinkList is_empty"<<endl;
    if (this->header->next == NULL)
    {
        is_empty = true;
    }
    else
    {
        is_empty = false;
    }
    return is_empty;
}


/**
* @brief  更新结点pos的元素的值
* @note
* @param  data待更新元素，pos代表要更新的位置
* @retval	None
******************************************************************************
* @attention
*
******************************************************************************
*/
void LinkList::update(int data, p_link_list pos)
{
    //cout << "this is LinkList update"<<endl;
    pos->data = data;
}


/**
  * @brief  查找元素的位置
  * @note
  * @param  data待查元素
  * @retval	若找到则返回该元素所在结点的指针，如未找到则返回NULL
  ******************************************************************************
  * @attention
  * 使用时做好判断下返回值，防止返回空值导致程序崩溃，
  * 该方法查找的是该元素第一在链表中出现的位置
  ******************************************************************************
 */
p_link_list LinkList::find(int data)
{
    p_link_list temp_node = NULL;
    //cout << "this is LinkList find"<<endl;
    temp_node = this->header->next;
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
 * @param  data待查元素
 * @retval	若找到则返回该元素所在结点的指针，如未找到则返回链表最后一个结点
 ******************************************************************************
 * @attention
 * 使用时做好判断下返回值，防止返回空值导致程序崩溃，
 * 该方法查找的是该元素第一在链表中出现的位置
 ******************************************************************************
*/
p_link_list LinkList::find_previous(int data)
{
    p_link_list temp_node = NULL;
    //cout << "this is LinkList find_previous"<<endl;
    temp_node = this->header;
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
 * @brief  删除元素data所在结点
 * @note
 * @param  data待删除元素
 * @retval	None
 ******************************************************************************
 * @attention
 *
 ******************************************************************************
*/
void LinkList::delete_element(int data)
{
    p_link_list  previous_node = NULL;
    p_link_list temp_node = NULL;
    //cout << "this is LinkList delete_element"<<endl;
    previous_node = find_previous(data);
    if (previous_node->next != NULL)
    {
        temp_node = previous_node->next->next;
        free(previous_node->next);
        previous_node->next = temp_node;
        this->header->data--;
    }
}


/**
* @brief  清空链表
* @note
* @param  list待清空链表，
* @retval	None
******************************************************************************
* @attention
* 头节点内存没有释放，该函数只是清除除头结点之外的节点，
******************************************************************************
*/
void LinkList::clear_list()
{
    p_link_list temp_next_node = NULL;
    p_link_list temp_node = NULL;
    //cout << "this is LinkList clear_list"<<endl;
    temp_node = this->header->next;
    this->header->next = NULL;
    while (temp_node != NULL)
    {
        temp_next_node = temp_node->next;
        free(temp_node);
        temp_node = temp_next_node;
    }
    this->header->data = 0;
}


/**
* @brief  显示列表内容
* @note
* @param
* @retval	None
******************************************************************************
* @attention
* （index,value）索引从1开始
******************************************************************************
*/
void LinkList::show_list()
{
    p_link_list temp_node = NULL;
    int i = 1;
    //cout << "this is LinkList show_list"<<endl;
    temp_node = this->header->next;
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
* @param
* @retval	链表接点个数（不包括头结点）
******************************************************************************
* @attention
*
******************************************************************************
*/
int LinkList::get_list_lenth()
{
    p_link_list temp_node = NULL;
    int i = 0;
    //cout << "this is LinkList get_list_lenth"<<endl;
    temp_node = this->header->next;
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
 * @param
 * @retval	结点索引,若返回-1表示该链表中没有该元素
 ******************************************************************************
 * @attention
 * 该索引返回的是第一次出现的索引
 ******************************************************************************
*/
int LinkList::get_element_index(int data)
{
    p_link_list temp_node = NULL;
    int i = 1;
    //cout << "this is LinkList get_element_index"<<endl;
    temp_node = this->header->next;
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
* @param
* @retval
******************************************************************************
* @attention
*
******************************************************************************
*/
void LinkList::reverse_list()
{
    p_link_list cur_node_new_next = NULL;
    p_link_list p_cursor = NULL;
    p_link_list current_node = NULL;
    //cout << "this is LinkList reverse_list"<<endl;
    p_cursor = this->header->next;
    current_node = this->header->next;
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
    this->header->next = cur_node_new_next;
}


/**
* @brief  获得头指针
* @note
* @param
* @retval
******************************************************************************
* @attention
*
******************************************************************************
*/
p_link_list LinkList::get_header()
{
    //cout << "this is LinkList get_header"<<endl;
    return this->header;
}


/**
  * @brief  构造函数
  * @note
  * @param
  * @retval
  ******************************************************************************
  * @attention
  * 该链表是带头结点的单链表
  ******************************************************************************
 */
CycleLinkList::CycleLinkList()
{
    //cout << "this is cyclelink_list CycleLinkList"<<endl;
    this->header = LinkList::get_header();
    if (this->header != NULL)
    {
        this->header->next = this->header;
        this->header->data = 0;  //用来存储结点长度
    }

}


/**
  * @brief  析构函数
  * @note
  * @param
  * @retval
  ******************************************************************************
  * @attention
  * 该链表是带头结点的单链表
  ******************************************************************************
 */
CycleLinkList :: ~CycleLinkList()
{
    //cout << "this is cyclelink_list ~CycleLinkList"<<endl;
    clear_list();
    /*在父类析构中释放头指针*/
    //free(this->header);
}


/**
  * @brief  判断是否循环链表为空
  * @note
  * @param  需要判断的链表
  * @retval	TRUE 表示该链表为空 ，FALSE 表示该链表为非空
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
 */
bool CycleLinkList::is_empty()
{
    bool is_empty = true;
    //cout << "this is cyclelink_list is_empty"<<endl;
    if (this->header->next == this->header)
    {
        is_empty = true;
    }
    else
    {
        is_empty = false;
    }
    return is_empty;
}


/**
* @brief  循环链表查找元素data所在结点
* @note
* @param   data
* @retval	元素data所在结点，若未找到返回null
******************************************************************************
* @attention
*
******************************************************************************
*/
p_link_list CycleLinkList::find(int data)
{
    p_link_list temp_node = NULL;
    //cout << "this is cyclelink_list find"<<endl;
    temp_node = this->header->next;
    while (temp_node != this->header)
    {
        if (data == temp_node->data)
        {
            break;
        }
        temp_node = temp_node->next;
    }
    if (temp_node == this->header)
    {
        temp_node = NULL;
    }
    return temp_node;
}


/**
* @brief  循环链表查找元素data所在结点的前驱结点
* @note
* @param  data
* @retval	元素data所在结点，若未找到返回null
******************************************************************************
* @attention
*
******************************************************************************
*/
p_link_list CycleLinkList::find_previous(int data)
{
    p_link_list temp_node = NULL;
    //cout << "this is cyclelink_list find_previous"<<endl;
    temp_node = this->header;
    while (temp_node->next != this->header)
    {
        if (data == temp_node->next->data)
        {
            break;
        }
        temp_node = temp_node->next;
    }
    if (temp_node->next == this->header)
    {
        temp_node = NULL;
    }
    return temp_node;
}


/**
* @brief  清空循环链表
* @note
* @param
* @retval
******************************************************************************
* @attention
* 头节点内存没有释放，该函数只是清除除头结点之外的节点，
******************************************************************************
*/
void CycleLinkList::clear_list()
{
    p_link_list temp_next_node = NULL;
    p_link_list temp_node = NULL;
    //cout << "this is cyclelink_list clear_list"<<endl;
    temp_node = this->header->next;
    this->header->next = this->header;
    while (temp_node != this->header)
    {
        temp_next_node = temp_node->next;
        free(temp_node);
        temp_node = temp_next_node;
    }
    this->header->data = 0;
}


/**
* @brief  显示列表内容
* @note
* @param
* @retval	None
******************************************************************************
* @attention
* （index,value）索引从1开始
******************************************************************************
*/
void CycleLinkList::show_list()
{
    p_link_list temp_node = NULL;
    int i = 1;
    //cout << "this is cyclelink_list show_list"<<endl;
    temp_node = this->header->next;
    while (temp_node != this->header)
    {
        printf("(%d , %d)\n", i, temp_node->data);
        i++;
        temp_node = temp_node->next;
    }
}


/**
* @brief  获取循环链表长度
* @note
* @param
* @retval	链表接点个数（不包括头结点）
******************************************************************************
* @attention
*
******************************************************************************
*/
int CycleLinkList::get_list_lenth()
{
    p_link_list temp_node = NULL;
    int i = 0;
    //cout << "this is cyclelink_list get_list_lenth"<<endl;
    temp_node = this->header->next;
    while (temp_node != this->header)
    {

        i++;
        temp_node = temp_node->next;
    }
    return i;
}


/**
 * @brief  获取循环data的索引
 * @note
 * @param
 * @retval	结点索引,若返回-1表示该链表中没有该元素
 ******************************************************************************
 * @attention
 * 该索引返回的是第一次出现的索引
 ******************************************************************************
*/
int CycleLinkList::get_element_index(int data)
{
    p_link_list temp_node = NULL;
    int i = 1;
    //cout << "this is cyclelink_list get_element_index"<<endl;
    temp_node = this->header->next;
    while (temp_node != this->header)
    {
        if (data == temp_node->data)
        {
            break;
        }
        i++;
        temp_node = temp_node->next;
    }
    if (temp_node == this->header)
    {
        /*未找到该元素*/
        i = -1;
    }
    return i;
}


/**
* @brief  循环链表反转
* @note
* @param
* @retval
******************************************************************************
* @attention
*
******************************************************************************
*/
void CycleLinkList::reverse_list()
{
    p_link_list cur_node_new_next = NULL;
    p_link_list p_cursor = NULL;
    p_link_list current_node = NULL;
    //cout << "this is cyclelink_list reverse_list"<<endl;
    p_cursor = this->header->next;
    current_node = this->header->next;
    while (p_cursor != this->header)
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
    this->header->next = cur_node_new_next;
}


/**
* @brief  循环链表删除元素data所在结点
* @note
* @param  data
* @retval
******************************************************************************
* @attention
*
******************************************************************************
*/
void CycleLinkList::delete_element(int data)
{
    p_link_list  previous_node = NULL;
    p_link_list temp_node = NULL;
    //cout << "this is LinkList delete_element"<<endl;
    previous_node = find_previous(data);
    if (previous_node->next != NULL)
    {
        temp_node = previous_node->next->next;
        free(previous_node->next);
        previous_node->next = temp_node;
        this->header->data--;
    }
}