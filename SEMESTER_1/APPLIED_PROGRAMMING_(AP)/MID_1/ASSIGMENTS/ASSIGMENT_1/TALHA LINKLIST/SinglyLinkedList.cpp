#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

//	Insertion Part here
void insert_head(Node*& head, int value)
{
	Node* node = new Node();
	node->data = value;
	node->next = head;
	head = node;
}
void insert_on_key(Node*& head, int value, int key)
{
	Node* node = new Node();
	if (head == NULL)
	{
		cout << "Head is Null !!!" << endl;
 		return;
	}

	Node* temp = head;

	while (temp->data != key)
		temp = temp->next;

	node->data = value;
	node->next = temp->next;

	temp->next = node;
}
void insert_tail(Node*& head, int value)
{
	Node* node = new Node;
	node->data = value;

	if (head == NULL)
	{
		head = node;
		return;
	}

	Node* temp = head;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = node;
	node->next = NULL;
}

//	Deletion Part here
void delete_head(Node*& head)
{
	Node* node = head;
	head = head->next;
	delete node;
}
void delete_on_key(Node*& head, int key)
{
	Node* prev = NULL;
	Node* temp = head;

	while (temp != NULL)
	{
		if (temp->data == key)
		{
			if (temp == head)
			{
				head = head->next;
				delete temp;
				temp = head;
			}
			else
			{
				prev->next = temp->next;
				delete temp;
				temp = prev->next;
			}
		}
		else
		{
			prev = temp;
			temp = temp->next;
		}
	}
}
void delete_tail(Node*& head)
{
	if (head == NULL)
		return;

	if (head->next == NULL)
	{
		delete head;
		return;
	}

	Node* temp = head;
	while (temp->next->next != NULL)
		temp = temp->next;

	delete temp->next;
	temp->next = NULL;
}
//	Print Reverse here
void print_reverse(Node* head)
{
	if (head == NULL)
		return;

	print_reverse(head->next);
	cout << head->data << " ";
}
//	Search here
bool search_node(Node* head, int key)
{
	Node* temp = head;
	int iterations_taken = 1;
	bool flag = false;
	while (temp != NULL)
	{
		if (temp->data == key)
		{
			flag = true;
			break;
		}
		temp = temp->next;
		iterations_taken++;
	}
	return flag;
}
//	Print here
void print(Node* head)
{
	Node* temp = head;
	cout << "[ ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "]\n";
}

int main()
{
	Node* head = NULL;
	insert_head(head, 10);
	insert_tail(head, 20);
	insert_on_key(head, 30, 20);
	insert_tail(head, 40);
	insert_tail(head, 50);
	print(head);

	cout << (search_node(head, 50) ? "Found" : "Not found") << endl;
	
	delete_head(head);
	delete_tail(head);
	print(head);

	delete_on_key(head, 30);
	print(head);

	insert_head(head, 100);
	insert_tail(head, 200);
	print(head);
	
	cout << "[ ";
	print_reverse(head);
	cout << "]";

	system("PAUSE");
	return 0;
}
