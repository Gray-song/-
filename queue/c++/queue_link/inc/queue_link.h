#ifndef _QUEUE_LINK_H_
#define _QUEUE_LINK_H_
struct  _NODE_
{
	int data;
	_NODE_* next;
};
typedef struct _NODE_* p_queue;

class QUEUE
{
public:
	QUEUE();
	~QUEUE();
	bool is_empty();
	void clear_queue();
	void enqueue(int data);
	int dequeue();
private:
	p_queue header;
	p_queue tail;
};
#endif

