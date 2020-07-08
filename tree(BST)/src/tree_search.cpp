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
			/*值小于当前结点，插看左子树*/
			if (p_cursor->left == NULL)
			{
				/*找到叶子结点*/
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
			/*值大于等于当前结点，插看右子树*/
			if (p_cursor->right == NULL)
			{
				/*找到叶子结点*/
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
		cout << "----" << value << " 未找到--------" << endl;
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
	/*查找要删除结点，以及要删除结点前一节点*/
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
		cout << "该 tree 中没有 " << value << endl;
		return false;
	}

	if ((p_cursor->left == NULL) && (p_cursor->right == NULL))
	{
		/*要删除的结点即无左子节点也无右子节点*/
		if (p_cursor->data < p_last_cursor->data)
		{
			/*要删除的结点是其父节点的左子节点*/
			p_last_cursor->left = NULL;
		}
		else
		{
			/*要删除的结点是其父节点的右子节点*/
			p_last_cursor->right = NULL;
		}
		free(p_cursor);
	}
	else if ((p_cursor->left != NULL) && (p_cursor->right != NULL))
	{
		/*要删除的结点即有左子节点也有右子节点*/
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
		/*交换最小结点与待删除结点*/
		temp = p_right_min->right;
		if (p_cursor->data < p_last_cursor->data)
		{
			/*要删除的结点是其父节点的左子节点*/
			p_last_cursor->left = p_right_min;
			p_right_min->left = p_cursor->left;
			p_right_min->right = p_cursor->right;
		}
		else
		{
			/*要删除的结点是其父节点的右子节点*/
			p_last_cursor->right = p_right_min;
			p_right_min->left = p_cursor->left;
			p_right_min->right = p_cursor->right;
		}

		if (p_right_min->data < p_last_right_min->data)
		{
			/*最小结点是其父节点的左子节点*/
			p_last_right_min->left = p_cursor;
			p_cursor->right = temp;
			p_cursor->left = NULL;
			/*删除p_cursor*/
			p_last_right_min->left = p_cursor->right;
		}
		else
		{
			/*最小结点是其父节点的右子节点*/
			//p_last_right_min->right = p_cursor;
			//p_cursor->right = temp;
			//p_cursor->left = NULL;
			/*删除p_cursor*/
			//p_last_right_min->right = p_cursor->right;
			p_right_min->right = temp;
		}
		free(p_cursor);
	}
	else
	{
		/*要删除的结点只有一个子节点（左子节点或右子节点）*/
		if (p_cursor->data < p_last_cursor->data)
		{
			/*要删除的结点是其父节点的左子节点*/
			if (p_cursor->left != NULL)
			{
				/*要删除的结点只有左子节点*/
				p_last_cursor->left = p_cursor->left;
			}
			else
			{
				/*要删除的结点只有右子节点*/
				p_last_cursor->left = p_cursor->right;
			}

		}
		else
		{
			/*要删除的结点是其父节点的右子节点*/
			if (p_cursor->left != NULL)
			{
				/*要删除的结点只有左子节点*/
				p_last_cursor->right = p_cursor->left;
			}
			else
			{
				/*要删除的结点只有右子节点*/
				p_last_cursor->right = p_cursor->right;
			}
		}
		free(p_cursor);
	}
	return true;
}