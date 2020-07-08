#include "tree_search.h"
#include <malloc.h>
#include <iostream>
using namespace std;
TreeSearch::TreeSearch(int root_value)
{
	tree = (p_root)malloc(sizeof(_ROOT_));
	if (tree != NULL)
	{
		tree->data = root_value;
		tree->left = NULL;
		tree->right = NULL;
	}
}

TreeSearch::~TreeSearch()
{
	free(tree);
}

p_root TreeSearch::get_root()
{
	return tree;
}

bool TreeSearch::insert(int value)
{
	p_root new_node = NULL;
	bool insert_success;
	p_root p_cursor;
	new_node = (p_root)malloc(sizeof(_ROOT_));
	if (new_node != NULL)
	{

		new_node->data = value;
		new_node->left = NULL;
		new_node->right = NULL;

	}
	else
	{
		cout << "new_node is  NULL" << endl;
		insert_success = false;
		return insert_success;
	}
	p_cursor = tree;
	while (true)
	{
		if (value < p_cursor->data)
		{
			/*ֵС�ڵ�ǰ��㣬�忴������*/
			if (p_cursor->left == NULL)
			{
				/*�ҵ�Ҷ�ӽ��*/
				p_cursor->left = new_node;
				insert_success = true;
				//return insert_success;
				break;
			}
			else
			{
				p_cursor = p_cursor->left;
			}
		}
		else
		{
			/*ֵ���ڵ��ڵ�ǰ��㣬�忴������*/
			if (p_cursor->right == NULL)
			{
				/*�ҵ�Ҷ�ӽ��*/
				p_cursor->right = new_node;
				insert_success = true;
				//return insert_success;
				break;
			}
			else
			{
				p_cursor = p_cursor->right;
			}
		}
	}
	return insert_success;
}


void TreeSearch::pre_show(p_root node)
{
	if (node == NULL)
	{
		return;
	}
	cout << node->data << "->";
	pre_show(node->left);
	pre_show(node->right);
}

void TreeSearch::mid_show(p_root node)
{
	if (node == NULL)
	{

		return;
	}
	mid_show(node->left);
	cout << node->data << "->";


	mid_show(node->right);
}


void TreeSearch::rear_show(p_root node)
{
	if (node == NULL)
	{

		return;
	}
	rear_show(node->left);
	rear_show(node->right);
	cout << node->data << "->";
}

p_root TreeSearch::find(int value)
{
	p_root p_cursor;
	p_cursor = tree;
	while (p_cursor != NULL)
	{
		if (p_cursor->data == value)
		{
			break;
		}
		else if (p_cursor->data > value)
		{
			p_cursor = p_cursor->left;
		}
		else
		{
			p_cursor = p_cursor->right;
		}
	}
	if (p_cursor == NULL)
	{
		cout << "----" << value << " δ�ҵ�--------" << endl;
	}

	return p_cursor;
}


bool TreeSearch::delete_node(int value)
{
	p_root p_cursor;
	p_root p_last_cursor;

	p_root p_right_min;
	p_root p_last_right_min;
	p_root temp;
	p_cursor = tree;
	p_last_cursor = p_cursor;
	/*����Ҫɾ����㣬�Լ�Ҫɾ�����ǰһ�ڵ�*/
	while (p_cursor != NULL)
	{
		if (p_cursor->data == value)
		{
			break;
		}
		else if (p_cursor->data > value)
		{
			p_last_cursor = p_cursor;
			p_cursor = p_cursor->left;
		}
		else
		{
			p_last_cursor = p_cursor;
			p_cursor = p_cursor->right;
		}
	}
	if (p_cursor == NULL)
	{
		cout << "�� tree ��û�� " << value << endl;
		return false;
	}

	if ((p_cursor->left == NULL) && (p_cursor->right == NULL))
	{
		/*Ҫɾ���Ľ�㼴�����ӽڵ�Ҳ�����ӽڵ�*/
		if (p_cursor->data < p_last_cursor->data)
		{
			/*Ҫɾ���Ľ�����丸�ڵ�����ӽڵ�*/
			p_last_cursor->left = NULL;
		}
		else
		{
			/*Ҫɾ���Ľ�����丸�ڵ�����ӽڵ�*/
			p_last_cursor->right = NULL;
		}
		free(p_cursor);
	}
	else if ((p_cursor->left != NULL) && (p_cursor->right != NULL))
	{
		/*Ҫɾ���Ľ�㼴�����ӽڵ�Ҳ�����ӽڵ�*/
		p_right_min = p_cursor->right;
		p_last_right_min = p_cursor;
		while (p_right_min != NULL)
		{
			if (p_right_min->left == NULL)
			{
				break;
			}
			else
			{
				p_last_right_min = p_right_min;
				p_right_min = p_right_min->left;
			}
		}
		/*������С������ɾ�����*/
		temp = p_right_min->right;
		if (p_cursor->data < p_last_cursor->data)
		{
			/*Ҫɾ���Ľ�����丸�ڵ�����ӽڵ�*/
			p_last_cursor->left = p_right_min;
			p_right_min->left = p_cursor->left;
			p_right_min->right = p_cursor->right;
		}
		else
		{
			/*Ҫɾ���Ľ�����丸�ڵ�����ӽڵ�*/
			p_last_cursor->right = p_right_min;
			p_right_min->left = p_cursor->left;
			p_right_min->right = p_cursor->right;
		}

		if (p_right_min->data < p_last_right_min->data)
		{
			/*��С������丸�ڵ�����ӽڵ�*/
			p_last_right_min->left = p_cursor;
			p_cursor->right = temp;
			p_cursor->left = NULL;
			/*ɾ��p_cursor*/
			p_last_right_min->left = p_cursor->right;
		}
		else
		{
			/*��С������丸�ڵ�����ӽڵ�*/
			//p_last_right_min->right = p_cursor;
			//p_cursor->right = temp;
			//p_cursor->left = NULL;
			/*ɾ��p_cursor*/
			//p_last_right_min->right = p_cursor->right;
			p_right_min->right = temp;
		}
		free(p_cursor);
	}
	else
	{
		/*Ҫɾ���Ľ��ֻ��һ���ӽڵ㣨���ӽڵ�����ӽڵ㣩*/
		if (p_cursor->data < p_last_cursor->data)
		{
			/*Ҫɾ���Ľ�����丸�ڵ�����ӽڵ�*/
			if (p_cursor->left != NULL)
			{
				/*Ҫɾ���Ľ��ֻ�����ӽڵ�*/
				p_last_cursor->left = p_cursor->left;
			}
			else
			{
				/*Ҫɾ���Ľ��ֻ�����ӽڵ�*/
				p_last_cursor->left = p_cursor->right;
			}

		}
		else
		{
			/*Ҫɾ���Ľ�����丸�ڵ�����ӽڵ�*/
			if (p_cursor->left != NULL)
			{
				/*Ҫɾ���Ľ��ֻ�����ӽڵ�*/
				p_last_cursor->right = p_cursor->left;
			}
			else
			{
				/*Ҫɾ���Ľ��ֻ�����ӽڵ�*/
				p_last_cursor->right = p_cursor->right;
			}
		}
		free(p_cursor);
	}
	return true;
}