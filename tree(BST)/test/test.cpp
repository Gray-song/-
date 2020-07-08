#include <iostream>
#include "tree_search.h"
using namespace std;
int main()
{
	TreeSearch tree(30);
	p_root temp;
	cout << "hello tree search!" << endl;
	tree.insert(28);
	tree.insert(27);
	tree.insert(32);
	tree.insert(29);
	tree.insert(31);
	tree.insert(33);
	tree.insert(34);
	cout << "前序" << endl;
	tree.pre_show(tree.get_root());
	cout << endl;
	cout << "中序" << endl;
	tree.mid_show(tree.get_root());
	cout << endl;
	cout << "后序" << endl;
	tree.rear_show(tree.get_root());
	cout << endl;

	cout << "-------------------------------------" << endl;
	temp = tree.find(27);
	if (temp != NULL)
	{
		cout << temp->data << " is finded " << endl;
	}
	else
	{

	}
	cout << "中序" << endl;
	tree.mid_show(tree.get_root());
	cout << endl;
	tree.delete_node(27);
	cout << "中序" << endl;
	tree.mid_show(tree.get_root());
	cout << endl;
	tree.delete_node(31);
	cout << "中序" << endl;
	tree.mid_show(tree.get_root());
	cout << endl;
	tree.delete_node(33);
	cout << "中序" << endl;
	tree.mid_show(tree.get_root());
	cout << endl;
	
	return 0;
}