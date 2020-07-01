#include <iostream>
#include "stack_link.h"
using namespace std;

int main()
{
	STACK stack;

	cout << "hello stack!" << endl;

	cout << "stack is " << stack.is_empty() << endl;
	stack.push(2);
	cout << "stack is " << stack.is_empty() << endl;
	cout << "stack pop " << stack.pop() << endl;
	cout << "stack is " << stack.is_empty() << endl;
	cout << "stack pop " << stack.pop() << endl;
	stack.clearstack();
	cout << "stack is " << stack.is_empty() << endl;
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);
	cout << "stack is " << stack.is_empty() << endl;
	cout << "stack pop " << stack.pop() << endl;
	cout << "stack pop " << stack.pop() << endl;
	cout << "stack pop " << stack.pop() << endl;
	cout << "stack pop " << stack.pop() << endl;
	cout << "stack pop " << stack.pop() << endl;
	cout << "stack pop " << stack.pop() << endl;
	while (true)
	{
		;
	}
}