#include <iostream>
#include "queue_array.h"
using namespace std;
void test_queue();
void test_cycle_queue();
int main()
{

	//test_queue();
	test_cycle_queue();
	while (true)
	{

	}
}

void test_queue()
{
	Queue queue;
	cout << "hello queue !" << endl;
	cout << "the queue is empty : " << queue.is_empty() << endl;
	cout << "the queue is full : " << queue.is_full() << endl;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);
	queue.enqueue(5);
	queue.enqueue(6);
	cout << "the queue is dequeue : " << queue.dequeue() << endl;
	queue.enqueue(6);
	queue.clear_queue();
	queue.enqueue(6);
	cout << "the queue is dequeue : " << queue.dequeue() << endl;
	cout << "the queue is dequeue : " << queue.dequeue() << endl;
	cout << "the queue is dequeue : " << queue.dequeue() << endl;
	cout << "the queue is dequeue : " << queue.dequeue() << endl;
	cout << "the queue is dequeue : " << queue.dequeue() << endl;
	cout << "the queue is empty : " << queue.is_empty() << endl;
	cout << "the queue is full : " << queue.is_full() << endl;
}

void test_cycle_queue()
{
	CycleQueue queue;
	cout << "the queue is empty : " << queue.is_empty() << endl;
	cout << "the queue is full : " << queue.is_full() << endl;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);
	queue.enqueue(5);
	queue.enqueue(6);
	cout << "the queue is dequeue : " << queue.dequeue() << endl;
	cout << "the queue is dequeue : " << queue.dequeue() << endl;
	queue.enqueue(6);
	cout << "the queue is dequeue : " << queue.dequeue() << endl;
	cout << "the queue is dequeue : " << queue.dequeue() << endl;
	cout << "the queue is dequeue : " << queue.dequeue() << endl;
	cout << "the queue is dequeue : " << queue.dequeue() << endl;

}