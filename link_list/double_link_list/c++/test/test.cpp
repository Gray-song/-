#include <iostream>
#include "double_link_list.h"
using namespace std;
void test();
int main()
{
	DoubleLinkList link;
	CycleDoubleLinkList cycle_link;
	cout << "hello double link" << endl;

	cout << "--------------is_empty---------------------" << endl;
	cout << "link is empty? yes(1)/no(0):" << link.is_empty() << endl;

	cout << "--------------insert_double_link---------------------" << endl;
	link.insert_double_link(1, link.get_header());
	cout << "link is empty? yes(1)/no(0):" << link.is_empty() << endl;
	cout << "link len : " << link.get_double_link_lenth() << endl;
	link.show_double_link();

	cout << "--------------insert_double_link---------------------" << endl;
	link.insert_double_link(2, link.find_double_link(1));
	cout << "link is empty? yes(1)/no(0):" << link.is_empty() << endl;
	cout << "link len : " << link.get_double_link_lenth() << endl;
	cout << "link index : " << link.get_double_link_element_index(1) << endl;
	link.show_double_link();

	cout << "--------------del_element_double_link---------------------" << endl;
	link.del_element_double_link(2);
	cout << "link is empty? yes(1)/no(0):" << link.is_empty() << endl;
	cout << "link len : " << link.get_double_link_lenth() << endl;
	link.show_double_link();

	cout << "--------------update_double_link---------------------" << endl;
	link.update_double_link(5, link.find_double_link(1));
	cout << "link is empty? yes(1)/no(0):" << link.is_empty() << endl;
	cout << "link len : " << link.get_double_link_lenth() << endl;
	link.show_double_link();

	cout << "--------------reverse_double_link---------------------" << endl;
	link.insert_double_link(2, link.find_double_link(5));
	cout << "link is empty? yes(1)/no(0):" << link.is_empty() << endl;
	cout << "link len : " << link.get_double_link_lenth() << endl;
	cout << "link index : " << link.get_double_link_element_index(1) << endl;
	link.show_double_link();
	link.reverse_double_link();
	link.show_double_link();

	cout << "--------------clear_double_link---------------------" << endl;
	link.clear_double_link();
	cout << "link is empty? yes(1)/no(0):" << link.is_empty() << endl;
	cout << "link len : " << link.get_double_link_lenth() << endl;
	link.show_double_link();

	cout << endl;
	cout << endl;
	cout << endl;
	cout << "hello cycle double link" << endl;
	cout << "--------------is_empty---------------------" << endl;
	cout << "cycle_link is empty? yes(1)/no(0):" << cycle_link.is_empty() << endl;

	cout << "--------------insert_double_link---------------------" << endl;
	cycle_link.insert_double_link(1, cycle_link.get_header());
	cout << "cycle_link is empty? yes(1)/no(0):" << cycle_link.is_empty() << endl;
	cout << "cycle_link len : " << cycle_link.get_double_link_lenth() << endl;
	cycle_link.show_double_link();

	cout << "--------------insert_double_link---------------------" << endl;
	cycle_link.insert_double_link(2, cycle_link.find_double_link(1));
	cout << "cycle_link is empty? yes(1)/no(0):" << cycle_link.is_empty() << endl;
	cout << "cycle_link len : " << cycle_link.get_double_link_lenth() << endl;
	cout << "cycle_link index : " << cycle_link.get_double_link_element_index(1) << endl;
	cycle_link.show_double_link();

	cout << "--------------del_element_double_link---------------------" << endl;
	cycle_link.del_element_double_link(2);
	cout << "cycle_link is empty? yes(1)/no(0):" << cycle_link.is_empty() << endl;
	cout << "cycle_link len : " << cycle_link.get_double_link_lenth() << endl;
	cycle_link.show_double_link();

	cout << "--------------update_double_link---------------------" << endl;
	cycle_link.update_double_link(5, cycle_link.find_double_link(1));
	cout << "cycle_link is empty? yes(1)/no(0):" << cycle_link.is_empty() << endl;
	cout << "cycle_link len : " << cycle_link.get_double_link_lenth() << endl;
	cycle_link.show_double_link();

	cout << "--------------reverse_double_link---------------------" << endl;
	cycle_link.insert_double_link(2, cycle_link.find_double_link(5));
	cout << "cycle_link is empty? yes(1)/no(0):" << cycle_link.is_empty() << endl;
	cout << "cycle_link len : " << cycle_link.get_double_link_lenth() << endl;
	cout << "cycle_link index : " << cycle_link.get_double_link_element_index(1) << endl;
	cycle_link.show_double_link();
	cycle_link.reverse_double_link();
	cycle_link.show_double_link();

	cout << "--------------clear_double_link---------------------" << endl;
	cycle_link.clear_double_link();
	cout << "cycle_link is empty? yes(1)/no(0):" << cycle_link.is_empty() << endl;
	cout << "cycle_link len : " << cycle_link.get_double_link_lenth() << endl;
	cycle_link.show_double_link();


	cout << endl;
	cout << endl;
	cout << endl;
	test();
	while (true)
	{

	}
	return 0;
}

void test()
{
	DoubleLinkList link;
	CycleDoubleLinkList cycle_link;
	link.insert_double_link(1, link.get_header());
	link.show_double_link();

	cycle_link.insert_double_link(1, cycle_link.get_header());
	cycle_link.show_double_link();
	// CycleDoubleLinkList l;
}