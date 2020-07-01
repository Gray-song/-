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
  * @brief  ���캯��
  * @note
  * @param
  * @retval
  ******************************************************************************
  * @attention
  * �������Ǵ�ͷ���ĵ�����
  ******************************************************************************
 */
LinkList::LinkList()
{
    this->header = (p_link_list)malloc(sizeof(_LINK_LIST_));
    //cout << "this is LinkList LinkList"<<endl;
    if (this->header != NULL)
    {
        this->header->next = NULL;
        this->header->data = 0;  //�����洢��㳤��
    }

}


/**
  * @brief  ��������
  * @note
  * @param
  * @retval
  ******************************************************************************
  * @attention
  * �������Ǵ�ͷ���ĵ�����
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
* @brief  ��Ԫ��data���뵽���pos����һ��λ��
* @note
* @param  data����Ԫ�أ�pos����Ҫ�����λ��
* @retval	TRUE�������ɹ���FALSE�������ʧ��
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
  * @brief  �ж��Ƿ�����Ϊ��
  * @note
  * @param  ��Ҫ�жϵ�����
  * @retval	TRUE ��ʾ������Ϊ�� ��FALSE ��ʾ������Ϊ�ǿ�
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
* @brief  ���½��pos��Ԫ�ص�ֵ
* @note
* @param  data������Ԫ�أ�pos����Ҫ���µ�λ��
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
  * @brief  ����Ԫ�ص�λ��
  * @note
  * @param  data����Ԫ��
  * @retval	���ҵ��򷵻ظ�Ԫ�����ڽ���ָ�룬��δ�ҵ��򷵻�NULL
  ******************************************************************************
  * @attention
  * ʹ��ʱ�����ж��·���ֵ����ֹ���ؿ�ֵ���³��������
  * �÷������ҵ��Ǹ�Ԫ�ص�һ�������г��ֵ�λ��
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
 * @brief  ����Ԫ�����ڽ���ǰһ�����ָ��
 * @note
 * @param  data����Ԫ��
 * @retval	���ҵ��򷵻ظ�Ԫ�����ڽ���ָ�룬��δ�ҵ��򷵻��������һ�����
 ******************************************************************************
 * @attention
 * ʹ��ʱ�����ж��·���ֵ����ֹ���ؿ�ֵ���³��������
 * �÷������ҵ��Ǹ�Ԫ�ص�һ�������г��ֵ�λ��
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
 * @brief  ɾ��Ԫ��data���ڽ��
 * @note
 * @param  data��ɾ��Ԫ��
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
* @brief  �������
* @note
* @param  list���������
* @retval	None
******************************************************************************
* @attention
* ͷ�ڵ��ڴ�û���ͷţ��ú���ֻ�������ͷ���֮��Ľڵ㣬
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
* @brief  ��ʾ�б�����
* @note
* @param
* @retval	None
******************************************************************************
* @attention
* ��index,value��������1��ʼ
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
* @brief  ��ȡ������
* @note
* @param
* @retval	����ӵ������������ͷ��㣩
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
 * @brief  ��ȡdata������
 * @note
 * @param
 * @retval	�������,������-1��ʾ��������û�и�Ԫ��
 ******************************************************************************
 * @attention
 * ���������ص��ǵ�һ�γ��ֵ�����
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
        /*δ�ҵ���Ԫ��*/
        i = -1;
    }
    return i;
}


/**
* @brief  ����ת
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
        /*���浱ǰָ��ĺ���ָ��*/
        p_cursor = p_cursor->next;
        /*���ĵ�ǰ���ĺ���ָ��ָ��*/
        current_node->next = cur_node_new_next;
        /*ʹ�µĺ���ָ��ָ��ǰ���*/
        cur_node_new_next = current_node;
        /*����current_nodeָ��p_cursor*/
        current_node = p_cursor;
    }
    /*����ͷָ��ָ��*/
    this->header->next = cur_node_new_next;
}


/**
* @brief  ���ͷָ��
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
  * @brief  ���캯��
  * @note
  * @param
  * @retval
  ******************************************************************************
  * @attention
  * �������Ǵ�ͷ���ĵ�����
  ******************************************************************************
 */
CycleLinkList::CycleLinkList()
{
    //cout << "this is cyclelink_list CycleLinkList"<<endl;
    this->header = LinkList::get_header();
    if (this->header != NULL)
    {
        this->header->next = this->header;
        this->header->data = 0;  //�����洢��㳤��
    }

}


/**
  * @brief  ��������
  * @note
  * @param
  * @retval
  ******************************************************************************
  * @attention
  * �������Ǵ�ͷ���ĵ�����
  ******************************************************************************
 */
CycleLinkList :: ~CycleLinkList()
{
    //cout << "this is cyclelink_list ~CycleLinkList"<<endl;
    clear_list();
    /*�ڸ����������ͷ�ͷָ��*/
    //free(this->header);
}


/**
  * @brief  �ж��Ƿ�ѭ������Ϊ��
  * @note
  * @param  ��Ҫ�жϵ�����
  * @retval	TRUE ��ʾ������Ϊ�� ��FALSE ��ʾ������Ϊ�ǿ�
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
* @brief  ѭ���������Ԫ��data���ڽ��
* @note
* @param   data
* @retval	Ԫ��data���ڽ�㣬��δ�ҵ�����null
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
* @brief  ѭ���������Ԫ��data���ڽ���ǰ�����
* @note
* @param  data
* @retval	Ԫ��data���ڽ�㣬��δ�ҵ�����null
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
* @brief  ���ѭ������
* @note
* @param
* @retval
******************************************************************************
* @attention
* ͷ�ڵ��ڴ�û���ͷţ��ú���ֻ�������ͷ���֮��Ľڵ㣬
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
* @brief  ��ʾ�б�����
* @note
* @param
* @retval	None
******************************************************************************
* @attention
* ��index,value��������1��ʼ
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
* @brief  ��ȡѭ��������
* @note
* @param
* @retval	����ӵ������������ͷ��㣩
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
 * @brief  ��ȡѭ��data������
 * @note
 * @param
 * @retval	�������,������-1��ʾ��������û�и�Ԫ��
 ******************************************************************************
 * @attention
 * ���������ص��ǵ�һ�γ��ֵ�����
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
        /*δ�ҵ���Ԫ��*/
        i = -1;
    }
    return i;
}


/**
* @brief  ѭ������ת
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
        /*���浱ǰָ��ĺ���ָ��*/
        p_cursor = p_cursor->next;
        /*���ĵ�ǰ���ĺ���ָ��ָ��*/
        current_node->next = cur_node_new_next;
        /*ʹ�µĺ���ָ��ָ��ǰ���*/
        cur_node_new_next = current_node;
        /*����current_nodeָ��p_cursor*/
        current_node = p_cursor;
    }
    /*����ͷָ��ָ��*/
    this->header->next = cur_node_new_next;
}


/**
* @brief  ѭ������ɾ��Ԫ��data���ڽ��
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