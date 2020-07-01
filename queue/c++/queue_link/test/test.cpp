#include <iostream>
#include "queue_link.h"
using namespace std;
int main()
{
	QUEUE queue;
	cout << "hello queue!" << endl;
	cout << "the queue is empty : " << queue.is_empty() << endl;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);
	queue.enqueue(5);
	cout << "the queue is  : " << queue.dequeue() << endl;
	cout << "the queue is  : " << queue.dequeue() << endl;
	cout << "the queue is  : " << queue.dequeue() << endl;
	cout << "the queue is  : " << queue.dequeue() << endl;
	cout << "the queue is  : " << queue.dequeue() << endl;
	cout << "the queue is  : " << queue.dequeue() << endl;
	while (true)
	{

	}
	return 0;
}