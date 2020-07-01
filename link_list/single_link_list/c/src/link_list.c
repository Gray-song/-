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
  * @brief  ͷ�巨��������
  * @note
  * @param  pbuff����Ԫ�أ�lenth ����ĳ���
  * @retval �����õ�����ָ��
  ******************************************************************************
  * @attention
  * �������Ǵ�ͷ���ĵ�����
  ******************************************************************************
 */
p_link_list create_link_list_at_head(element_type* pbuff, int lenth)
{
    /*ͷ�巨*/
    int i = 0;
    p_link_list new_node;
    p_link_list header = (p_link_list)malloc(sizeof(_LINK_LIST_));
    if (header == NULL)
    {
        /*�����ڴ�ʧ��*/
        return NULL;
    }
    header->next = NULL;
    for (i = 0; i < lenth; i++)
    {
        new_node = (p_link_list)malloc(sizeof(_LINK_LIST_));
        if (new_node == NULL)
        {
            /*�����ڴ�ʧ��*/
            return NULL;
        }
        new_node->data = pbuff[i];
        new_node->next = header->next;
        header->next = new_node;
    }
    return header;
}


/**
  * @brief  β�巨��������
  * @note
  * @param  pbuff����Ԫ�أ�lenth ����ĳ���
  * @retval �����õ�����ָ��
  ******************************************************************************
  * @attention
  * �������Ǵ�ͷ���ĵ�����
  ******************************************************************************
 */
p_link_list create_link_list_at_last(element_type* pbuff, int lenth)
{
    /*β�巨*/
    int i = 0;
    p_link_list new_node;
    p_link_list previous_node;
    p_link_list header = (p_link_list)malloc(sizeof(_LINK_LIST_));
    if (header == NULL)
    {
        /*�����ڴ�ʧ�ܣ�ֱ�ӷ���NULL��������ڴ�й¶Ŷ���ٱ�����˼��һ�������Ż�*/
        return NULL;
    }
    header->next = NULL;
    previous_node = header;
    for (i = 0; i < lenth; i++)
    {
        new_node = (p_link_list)malloc(sizeof(_LINK_LIST_));
        if (new_node == NULL)
        {
            /*�����ڴ�ʧ�ܣ�ֱ�ӷ���NULL��������ڴ�й¶Ŷ���ٱ�����˼��һ�������Ż�*/
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
  * @brief  ����һ��������
  * @note
  * @param  None
  * @retval �����õ�����ָ��
  ******************************************************************************
  * @attention
  * �������Ǵ�ͷ���ĵ�����
  ******************************************************************************
 */
p_link_list create_empty_link_list()
{
    p_link_list header = (p_link_list)malloc(sizeof(_LINK_LIST_));
    if (header == NULL)
    {
        /*�����ڴ�ʧ��*/
        return NULL;
    }
    header->next = NULL;
    return header;
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
  * @brief  ����Ԫ�ص�λ��
  * @note
  * @param  data����Ԫ�أ�list��������
  * @retval	���ҵ��򷵻ظ�Ԫ�����ڽ���ָ�룬��δ�ҵ��򷵻�NULL
  ******************************************************************************
  * @attention
  * ʹ��ʱ�����ж��·���ֵ����ֹ���ؿ�ֵ���³��������
  * �÷������ҵ��Ǹ�Ԫ�ص�һ�������г��ֵ�λ��
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
 * @brief  ����Ԫ�����ڽ���ǰһ�����ָ��
 * @note
 * @param  data����Ԫ�أ�list��������
 * @retval	���ҵ��򷵻ظ�Ԫ�����ڽ���ָ�룬��δ�ҵ��򷵻��������һ�����
 ******************************************************************************
 * @attention
 * ʹ��ʱ�����ж��·���ֵ����ֹ���ؿ�ֵ���³��������
 * �÷������ҵ��Ǹ�Ԫ�ص�һ�������г��ֵ�λ��
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
* @brief  ��Ԫ��data���뵽���pos����һ��λ��
* @note
* @param  data����Ԫ�أ�list������������ڸ÷�����Ŀǰ��δʹ�ã���ֹ�Ժ����ʱʹ��
*         �����Ա����Ƚ������룬pos����Ҫ�����λ��
* @retval	TRUE�������ɹ���FALSE�������ʧ��
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
 * @brief  ɾ��Ԫ��data���ڽ��
 * @note
 * @param  data��ɾ��Ԫ�أ�list��ɾ������
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
* @brief  ���½��pos��Ԫ�ص�ֵ
* @note
* @param  data������Ԫ�أ�list�����µ������ڸ÷�����Ŀǰ��δʹ�ã���ֹ�Ժ����ʱʹ��
*         �����Ա����Ƚ������룬pos����Ҫ���µ�λ��
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
* @brief  �������
* @note
* @param  list���������
* @retval	None
******************************************************************************
* @attention
* ͷ�ڵ��ڴ�û���ͷţ��ú���ֻ�������ͷ���֮��Ľڵ㣬list��δ���٣�����ִ��
* �˺�����list�ÿ��Դ��½��в���ɾ�������Ȳ��������볹������list,��ʾ��
* destroy_list ����
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
* @brief  ��ʾ�б�����
* @note
* @param  list����ʾ����
* @retval	None
******************************************************************************
* @attention
* ��index,value��������1��ʼ
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
* @brief  ��ȡ������
* @note
* @param  list
* @retval	����ӵ������������ͷ��㣩
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
 * @brief  ��ȡdata������
 * @note
 * @param  list
 * @retval	�������,������-1��ʾ��������û�и�Ԫ��
 ******************************************************************************
 * @attention
 * ���������ص��ǵ�һ�γ��ֵ�����
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
        /*δ�ҵ���Ԫ��*/
        i = -1;
    }
    return i;
}


/**
* @brief  ����ת
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
    list->next = cur_node_new_next;
}


/**
* @brief  ��������
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
* @brief  ʹ��ͷ�巨����ѭ������
* @note
* @param  pbuff�������ݣ�lenth������
* @retval �����õ�����
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
        /*�����ڴ�ʧ��*/
        return NULL;
    }
    header->next = header;
    for (i = 0; i < lenth; i++)
    {
        new_node = (p_link_list)malloc(sizeof(_LINK_LIST_));
        if (new_node == NULL)
        {
            /*�����ڴ�ʧ�ܣ�ֱ�ӷ���NULL��������ڴ�й¶Ŷ���ٱ�����˼��һ�������Ż�*/
            return NULL;
        }
        new_node->data = pbuff[i];
        new_node->next = header->next;
        header->next = new_node;

    }
    return header;
}


/**
* @brief  ʹ��β�巨����ѭ������
* @note
* @param  pbuff�������ݣ�lenth������
* @retval �����õ�����
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
            /*�����ڴ�ʧ�ܣ�ֱ�ӷ���NULL��������ڴ�й¶Ŷ���ٱ�����˼��һ�������Ż�*/
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
* @brief  ������ѭ������
* @note
* @param  pbuff�������ݣ�lenth������
* @retval �����õ�����
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
        /*�����ڴ�ʧ��*/
        return NULL;
    }
    header->next = header;
    return header;

}


/**
* @brief  ��ʾ�б�����
* @note
* @param  list����ʾ����
* @retval	None
******************************************************************************
* @attention
* ��index,value��������1��ʼ
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
* @brief  �ж�ѭ�������Ƿ�Ϊ������
* @note
* @param  list����ʾ����
* @retval	TRUE Ϊ�գ�FALSE Ϊ�ǿ�
******************************************************************************
* @attention
* ��
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
* @brief  ѭ���������Ԫ��data���ڽ��
* @note
* @param  list����������data
* @retval	Ԫ��data���ڽ�㣬��δ�ҵ�����null
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
* @brief  ѭ���������Ԫ��data���ڽ���ǰ�����
* @note
* @param  list����������data
* @retval	Ԫ��data���ڽ�㣬��δ�ҵ�����null
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
* @brief  ѭ������ɾ��Ԫ��data���ڽ��
* @note
* @param  list��data
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
        /*�жϸ�Ԫ��ǰһ���ڵ㲻�����һ���ڵ�*/
        
        temp_node = previous_node->next;
        previous_node->next = previous_node->next->next;
        free(temp_node);
    }
    
}


/**
* @brief  ���ѭ������
* @note
* @param  list��data
* @retval
******************************************************************************
* @attention
* ͷ�ڵ��ڴ�û���ͷţ��ú���ֻ�������ͷ���֮��Ľڵ㣬list��δ���٣�����ִ��
* �˺�����list�ÿ��Դ��½��в���ɾ�������Ȳ��������볹������list,��ʾ��
* destroy_cycle_list ����
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
* @brief  ��ȡѭ��������
* @note
* @param  list
* @retval	����ӵ������������ͷ��㣩
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
 * @brief  ��ȡѭ��data������
 * @note
 * @param  list
 * @retval	�������,������-1��ʾ��������û�и�Ԫ��
 ******************************************************************************
 * @attention
 * ���������ص��ǵ�һ�γ��ֵ�����
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
        /*δ�ҵ���Ԫ��*/
        i = -1;
    }
    return i;
}


/**
* @brief  ѭ������ת
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
* @brief  ����ѭ������
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
