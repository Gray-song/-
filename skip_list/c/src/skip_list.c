#include "skip_list.h"
#include<malloc.h>
#include <stdio.h>
#include <stdlib.h>
p_skip_list creat_empty_skip_list()
{

	int i;
	p_skip_list header;

	header = (p_skip_list)malloc(sizeof(_SKIP_NODE_));
	if (header == NULL)
	{
		return NULL;
	}
	header->max_level = MAX_LEVEL;
	header->next = (p_skip_list*)malloc(MAX_LEVEL * sizeof(p_skip_list));
	if (header->next == NULL)
	{
		return NULL;
	}
	for (i = 0; i < MAX_LEVEL; i++)
	{
		header->next[i] = NULL;
	}
	return header;
}


p_skip_list find(int data, p_skip_list header)
{
	p_skip_list temp;
	int i = 0;
	i = MAX_LEVEL - 1;
	temp = header;

	while (i >= 0)
	{

		if (temp->next[i] != NULL)
		{
			if (temp->next[i]->data < data)
			{
				/*当前层的下一个小于data，在本层继续查找*/
				printf("路径：%d,层数：%d\n", temp->next[i]->data, i);
				temp = temp->next[i];
			}
			else if (temp->next[i]->data > data)
			{
				/*当前层的下一个大于data，去下一层查找*/
				i--;
				printf("路径：%d,层数：%d\n", temp->data, i);
			}
			else
			{
				/*找到了*/
				return temp->next[i];
			}
		}
		else
		{
			/*本层遍历到末尾了*/
			i--;
			printf("路径：%d,层数：%d\n", temp->data, i);
		}
	}

	/*未找到*/
	return NULL;
}

bool insert(int data, p_skip_list header)
{
	int level;

	bool insert_success = TRUE;
	int i = 0;
	p_skip_list updata[MAX_LEVEL];
	p_skip_list new_node = NULL;
	p_skip_list temp;

	level = skip_list_random(MAX_LEVEL);

	new_node = (p_skip_list)malloc(sizeof(_SKIP_NODE_));
	if (new_node == NULL)
	{
		insert_success = FALSE;
		return insert_success;
	}
	new_node->next = (p_skip_list*)malloc(MAX_LEVEL * sizeof(p_skip_list));
	if (new_node->next == NULL)
	{
		insert_success = FALSE;
		return insert_success;
	}

	new_node->data = data;
	new_node->max_level = level;

	temp = header;

	for (i = 0; i < MAX_LEVEL; i++)
	{
		updata[i] = header;
	}
	i = MAX_LEVEL - 1;
	while (i >= 0)
	{
		if (temp->next[i] != NULL)
		{
			if (temp->next[i]->data < data)
			{
				temp = temp->next[i];
			}
			else
			{
				updata[i] = temp;
				i--;
			}
		}
		else
		{
			updata[i] = temp;
			i--;


		}
	}
	// updata[0] = temp;
	for (i = 0; i < level; i++)
	{
		new_node->next[i] = updata[i]->next[i];
		updata[i]->next[i] = new_node;
	}
	return insert_success;

}

int skip_list_random(int maxlevel)
{
	int level = 1;


	while ((rand() % 2 == 1) && (level < maxlevel))
	{
		level++;
	}
	return level;
}


void skip_list_show(p_skip_list header)
{
	p_skip_list temp = header;


	int i;


	for (i = MAX_LEVEL - 1; i >= 0; i--)
	{
		printf("第%d层:", i);
		temp = header;
		while (temp->next[i] != NULL)
		{

			printf(" %d -> ", temp->next[i]->data);
			temp = temp->next[i];
		}
		printf("\n");

	}

}

bool delete_element(int data, p_skip_list header)
{
	p_skip_list temp;
	p_skip_list temp_node;
	p_skip_list updata[MAX_LEVEL];
	int level;
	int i = 0;
	for (i = 0; i < MAX_LEVEL; i++)
	{
		updata[i] = header;
	}

	temp = header;
	i = MAX_LEVEL - 1;
	while (i >= 0)
	{
		if (temp->next[i] != NULL)
		{
			if (temp->next[i]->data < data)
			{
				temp = temp->next[i];
			}
			else
			{
				updata[i] = temp;
				i--;
			}
		}
		else
		{
			updata[i] = temp;
			i--;


		}
	}
	if ((temp->next[0] != NULL) && (temp->next[0]->data == data))
	{
		printf("temp : %d,层数 %d\n", temp->data, temp->max_level);
		printf("temp->next : %d,层数 %d\n", temp->next[0]->data, temp->next[0]->max_level);
		level = temp->next[0]->max_level;
		temp_node = temp->next[0];
		for (i = 0; i < level; i++)
		{
			printf("updata[%d],数据 %d\n", i, updata[i]->data);
			printf("updata[%d]->next[%d],数据 %d\n", i, i, updata[i]->next[i]->data);
			updata[i]->next[i] = updata[i]->next[i]->next[i];
			printf("updata[%d],数据 %d\n", i, updata[i]->data);
			printf("updata[%d]->next[%d],数据 %d\n", i, i, updata[i]->next[i]->data);
		}
		free(temp_node->next);
		free(temp_node);
		return TRUE;
	}
	else
	{
		printf("未找到\n\n");
		return FALSE;
	}
}