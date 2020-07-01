#ifndef _STACK_LINK_H_
#define _STACK_LINK_H_

struct _NODE_
{
	int data;
	_NODE_* next;
};
typedef _NODE_* p_stack;

class STACK
{
public:
	STACK();
	~STACK();
	bool is_empty();
	void clearstack();
	void push(int data);
	int pop();
private:
	p_stack header;
};
#endif 
