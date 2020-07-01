#include <iostream>
#include "link_list.h"
using namespace std;
void test();
int main()
{
	bool is_empty = false;
	cout << "hello link list \n";
	LinkList link;
	CycleLinkList cyclelink;

	cout << "----------is_empty test------------" << endl;
	is_empty = link.is_empty();
	cout << is_empty << endl;

	cout << "----------insert test------------" << endl;
	link.insert(1, link.get_header());
	is_empty = link.is_empty();
	cout << is_empty << endl;
	link.show_list();

	cout << "----------find test------------" << endl;
	link.insert(2, link.find(1));
	is_empty = link.is_empty();
	cout << is_empty << endl;
	cout << "link len:" << link.get_list_lenth() << endl;
	cout << "link len header data:" << link.get_header()->data << endl;
	link.show_list();

	cout << "----------find test------------" << endl;
	link.insert(3, link.find(2));
	link.insert(4, link.find(3));
	link.insert(5, link.find(4));
	link.insert(6, link.find(5));
	is_empty = link.is_empty();
	cout << is_empty << endl;
	cout << "link len:" << link.get_list_lenth() << endl;
	cout << "link len header data:" << link.get_header()->data << endl;
	link.show_list();

	cout << "----------get_element_index test------------" << endl;
	cout << "index:" << link.get_element_index(5) << endl;
	link.update(8, link.find(5));
	cout << "index:" << link.get_element_index(5) << endl;
	cout << "index:" << link.get_element_index(8) << endl;
	link.show_list();

	cout << "----------delete_element test------------" << endl;
	link.delete_element(8);
	cout << "link len:" << link.get_list_lenth() << endl;
	cout << "link len header data:" << link.get_header()->data << endl;
	link.show_list();

	cout << "----------clear_list test------------" << endl;
	link.clear_list();
	is_empty = link.is_empty();
	cout << is_empty << endl;
	cout << "link len:" << link.get_list_lenth() << endl;
	cout << "link len header data:" << link.get_header()->data << endl;



	cout << "hello cycle link list \n";

	cout << "----------is_empty test------------" << endl;
	is_empty = cyclelink.is_empty();
	cout << is_empty << endl;

	cout << "----------insert test------------" << endl;
	cyclelink.insert(8, cyclelink.get_header());
	link.show_list();
	is_empty = cyclelink.is_empty();
	cout << is_empty << endl;
	cyclelink.show_list();

	cout << "----------find test------------" << endl;
	cyclelink.insert(2, cyclelink.find(8));
	is_empty = cyclelink.is_empty();
	cout << is_empty << endl;
	cout << "link len:" << cyclelink.get_list_lenth() << endl;
	cout << "link len header data:" << cyclelink.get_header()->data << endl;
	cyclelink.show_list();

	cout << "----------find test------------" << endl;
	cyclelink.insert(3, cyclelink.find(2));
	cyclelink.insert(4, cyclelink.find(3));
	cyclelink.insert(5, cyclelink.find(4));
	cyclelink.insert(6, cyclelink.find(5));
	is_empty = cyclelink.is_empty();
	cout << is_empty << endl;
	cout << "link len:" << cyclelink.get_list_lenth() << endl;
	cout << "link len header data:" << cyclelink.get_header()->data << endl;
	cyclelink.show_list();

	cout << "----------get_element_index test------------" << endl;
	cout << "index:" << cyclelink.get_element_index(5) << endl;
	cyclelink.update(8, cyclelink.find(5));
	cout << "index:" << cyclelink.get_element_index(5) << endl;
	cout << "index:" << cyclelink.get_element_index(8) << endl;
	cyclelink.show_list();

	cout << "----------delete_element test------------" << endl;
	cyclelink.delete_element(8);
	cout << "link len:" << cyclelink.get_list_lenth() << endl;
	cout << "link len header data:" << cyclelink.get_header()->data << endl;
	cyclelink.show_list();

	cout << "----------clear_list test------------" << endl;
	cyclelink.clear_list();
	is_empty = cyclelink.is_empty();
	cout << is_empty << endl;
	cout << "link len:" << cyclelink.get_list_lenth() << endl;
	cout << "link len header data:" << cyclelink.get_header()->data << endl;

	cout << "----------destory test------------" << endl;
	cout << "----------destory test------------" << endl;
	test();
	while (1)
	{
		;
	}
	return 0;
}


void test()
{
	LinkList link;
	CycleLinkList cyclelink;
}