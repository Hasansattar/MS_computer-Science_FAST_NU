
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *merge_lists(Node *a, Node *b)
{

    if (a == NULL && b == NULL)
        return NULL;

    Node *res = NULL;

    while (a != NULL && b != NULL)
    {

        if (a->data <= b->data)
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

void displayList(struct Node *Node)
{
    while (Node != NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{

    struct Node *res = NULL;

    Node *a = newNode(5);
    a->next = newNode(10);
    a->next->next = newNode(15);

    Node *b = newNode(2);
    b->next = newNode(3);
    b->next->next = newNode(20);

    cout << "list A before merge: \n";
    displayList(a);

    cout << "\n list B before merge: \n";
    displayList(b);

    res = merge_lists(a, b);

    cout << "\nmerged linked list is: \n";
    displayList(res);

    return 0;
}
