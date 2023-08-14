#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

class Queue
{
private:
	Node* head, * tail;
public:
	Queue()
	{
		head = tail = NULL;
	}

	void Enqueue_Tail(int data)
	{
		Node* node = new Node;
		node->data = data;
		node->next = NULL;
		if (head == NULL)
		{
			head = tail = node;
		}
		else
		{
			//	10 -> 20 -> 30 -> 40 -> NULL
			tail->next = node;
			tail = node;
		}
	}

	void Enqueue_Head(int data)
	{
		Node* node = new Node;
		node->data = data;
		if (head == NULL)
		{
			node->next = NULL;
			head = tail = node;
		}
		else
		{
			node->next = head;
			head = node;
		}
	}

	bool IsEmpty()
	{
		if (head == NULL)
			return true;
		return false;
	}

	void Dequeue_Head()
	{
		if (IsEmpty())
		{
			cout << "Queue is empty...\n";
			return;
		}
		Node* node = head;
		head = head->next;
		delete node;
	}

	void Dequeue_Tail()
	{
		if (IsEmpty())
		{
			cout << "Queue is empty...\n";
			return;
		}
		//	10
		//	node = 10, head = 10, tail = 10
		//	10 -> 20 -> 30 -> 40
		//	node = 10
		Node* node = head;
		if (node->next == NULL)
		{
			delete node;
			return;
		}
		else
		{
			//	10 -> 20
			//	node = 10, head = 10, tail = 20
			//	node = 10, head = 10, tail = 10
			//	delete node->next = 20
			while (node->next != tail)
				node = node->next;
			tail = node;
			tail->next = NULL;
			delete node->next;
		}
	}

	void Display()
	{
		Node* node = head;
		if (node != NULL)
		{
			cout << "[ ";
			while (node != NULL)
			{
				cout << node->data << " ";
				node = node->next;
			}
			cout << "]" << endl;
		}
	}
};

int main()
{
	Queue queue;

	queue.Enqueue_Tail(10);
	queue.Enqueue_Tail(20);
	queue.Enqueue_Tail(30);
	queue.Enqueue_Tail(40);
	queue.Display();

	queue.Enqueue_Head(50);
	queue.Enqueue_Head(60);
	queue.Enqueue_Head(70);
	queue.Enqueue_Head(80);
	queue.Display();

	queue.Dequeue_Head();
	queue.Dequeue_Tail();

	queue.Display();

	system("PAUSE");
	return 0;
}
