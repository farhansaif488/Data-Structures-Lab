#include <bits/stdc++.h>
using namespace std;


#define SIZE 10


class queue
{
	int *arr;
	int capacity;
	int front;
	int rear;
	int count;

public:
	queue(int size = SIZE);
	~queue();

	void dequeue();
	void enqueue(int x);
	int peek();
	int size();
	bool isEmpty();
	bool isFull();
};

queue::queue(int size)
{
	arr = new int[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}


queue::~queue()
{
	delete arr;
}


void queue::dequeue()
{

	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Removing " << arr[front] << '\n';

	front = (front + 1) % capacity;
	count--;
}


void queue::enqueue(int item)
{

	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Inserting " << item << '\n';

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}


int queue::peek()
{
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	return arr[front];
}


int queue::size()
{
	return count;
}


bool queue::isEmpty()
{
	return (size() == 0);
}


bool queue::isFull()
{
	return (size() == capacity);
}


int main()
{

	queue q(5);

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	cout << "Front element is: " << q.peek() << endl;
	q.dequeue();

	q.enqueue(4);

	cout << "Queue size is " << q.size() << endl;

	q.dequeue();
	q.dequeue();
	q.dequeue();

	if (q.isEmpty())
		cout << "Queue Is Empty\n";
	else
		cout << "Queue Is Not Empty\n";

	return 0;
}
