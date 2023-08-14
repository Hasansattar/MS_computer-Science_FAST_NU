#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next, *prev;
};

//	Insertion Part here
void insert_head(Node*& head, int value)
{
	Node* node = new Node();
	node->data = value;
	node->next = head;
	if (head != NULL)
		head->prev = node;

	node->prev = NULL;
	head = node;
}
void insert_on_key(Node*& head, int value, int key)
{
	Node* node = new Node();
	node->data = value;

	Node* temp = head;
	while (temp != NULL && temp->data != key)
		temp = temp->next;

	if (temp == NULL)	//	It means we are at the end;
	{
		cout << "Key not found. Cannot insert value.\n";
		return;
	}

	node->next = temp->next;
	if(temp->next != NULL)
		temp->next->prev = node;
	temp->next = node;
	node->prev = temp;
}
void insert_tail(Node*& head, int value)
{
	if (head == NULL)
	{
		insert_head(head, value);
		return;
	}

	Node* node = new Node();
	node->data = value;
	Node* temp = head;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = node;
	node->prev = temp;
	node->next = NULL;
}

//	Deletion Part here
void delete_head(Node*& head)
{
	Node* node = head;
	head = head->next;
	head->prev = NULL;
	delete node;
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
void delete_on_key(Node*& head, int key)
{
	Node* temp = head;
	if (temp->data == key)	//	 If the deleting node is at head.
	{
		delete_head(head);
		temp = temp->next;
		return;
	}
	while (temp != NULL && temp->data != key)
		temp = temp->next;
	if (temp == NULL)	//	We are at end. Maybe not is not in list.
	{
		cout << "Node Not found..." << endl;
		return;
	}

	if (temp->next == NULL)
	{
		delete_tail(head);
	}
	else
	{
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
	}
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
	print(head);

	insert_on_key(head, 30, 200);
	insert_tail(head, 40);
	insert_tail(head, 50);
	print(head);

	cout << (search_node(head, 50) ? "Found" : "Not found") << endl;
	
	delete_head(head);
	delete_tail(head);
	print(head);

	delete_on_key(head, 10);
	print(head);

	insert_head(head, 100);
	insert_tail(head, 200);
	print(head);

	insert_tail(head, 500);
	print(head);
	
	delete_on_key(head, 500);
	delete_on_key(head, 100);
	print(head);

	delete_on_key(head, 20);
	print(head);
	
	cout << "[ ";
	print_reverse(head);
	cout << "]\n";

	system("PAUSE");
	return 0;
}
