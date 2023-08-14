 
#include<iostream>
using namespace std;

 
struct Node
{
	int key;
	struct Node* next;
};

 
Node*  merge_lists(Node *a, Node *b)
{
	 
	if (a==NULL && b==NULL) return NULL;

	 
	Node *res = NULL;

	 
	while (a != NULL && b != NULL)
	{
		 
		if (a->key <= b->key)
		{
			 
			Node *temp = a->next;

			 
			a->next = res;
			res = a;

		 
			a = temp;
		}

		 
		else
		{
			Node *temp = b->next;
			b->next = res;
			res = b;
			b = temp;
		}
	}
 
	while (a != NULL)
	{
		Node *temp = a->next;
		a->next = res;
		res = a;
		a = temp;
	}

 
	while (b != NULL)
	{
		Node *temp = b->next;
		b->next = res;
		res = b;
		b = temp;
	}

	return res;
}
 
void printList(struct Node *Node)
{
	while (Node!=NULL)
	{
		cout << Node->key << " ";
		Node = Node->next;
	}
}

 
Node *newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}
 
int main()
{
	 
	struct Node* res = NULL;

	 
	Node *a = newNode(5);
	a->next = newNode(10);
	a->next->next = newNode(15);

	Node *b = newNode(2);
	b->next = newNode(3);
	b->next->next = newNode(20);

	cout << "List A before merge: \n";
	printList(a);

	cout << "\nList B before merge: \n";
	printList(b);

	 
	res =  merge_lists(a, b);

	cout << "\nMerged Linked List is: \n";
	printList(res);

	return 0;
}
