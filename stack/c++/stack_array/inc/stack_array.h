#ifndef _STACK_ARRAY_H_
#define _STACK_ARRAY_H_
class STACK
{
public:
	STACK();
	STACK(int cap);

	~STACK();
	bool is_empty();
	bool is_full();
	void clear_stack();
	void push(int data);
	int pop();

private:
	int capacity;
	int topofstack;
	int* array;

};


#endif 
