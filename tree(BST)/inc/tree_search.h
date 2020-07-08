#ifndef _TREE_SEARCH_H_
#define _TREE_SEARCH_H_

struct _ROOT_
{
	int data;
	struct _ROOT_* left;
	struct _ROOT_* right;
};
typedef struct _ROOT_* p_root;

class TreeSearch
{
public:
	TreeSearch(int root_value);
	~TreeSearch();
	p_root get_root();
	bool insert(int value);
	void pre_show(p_root tree);
	void mid_show(p_root tree);
	void rear_show(p_root tree);
	p_root find(int value);
	bool delete_node(int value);

private:

	p_root tree;
};
#endif // !_TREE_SEARCH_H_

