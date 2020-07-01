#include <iostream>
#include "stack_array.h"
using namespace std;
int main()
{
	STACK stack;

	cout << "hello stack array" << endl;

	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(8);
	stack.push(7);
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	stack.push(6);
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;


	while (true)
	{

	}
}