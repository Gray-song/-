#ifndef _QUEUE_ARRAY_H_
#define _QUEUE_ARRAY_H_

class Queue
{
public:
	Queue();
	Queue(int cap);
	~Queue();
	bool is_empty();
	bool is_full();
	void clear_queue();
	void enqueue(int data);
	int dequeue();
private:
	int capacity;
	int head;
	int tail;

	int* array;
};



class CycleQueue
{

public:
	CycleQueue();
	CycleQueue(int cap);
	~CycleQueue();
	bool is_empty();
	bool is_full();
	void clear_queue();
	void enqueue(int data);
	int dequeue();
private:
	int capacity;
	int head;
	int tail;
	bool empty_flag;
	bool full_flag;
	int* array;
};
#endif 