
#include <iostream>
using namespace std;

struct Node
{int data;
    struct Node *next;
};

Node *merge_lists(Node *a, Node *b)
{
    if (a == NULL && b == NULL)
        return NULL;
    Node *result = NULL;
    while (a != NULL && b != NULL)
    {
        if (a->data <= b->data)
        {
            Node *temp = a->next;

            a->next = result;
            result = a;

            a = temp;
        }

        else
        {
            Node *temp = b->next;
            b->next = result;
            result = b;
            b = temp;
        }
    }

    while (a != NULL)
    {
        Node *temp = a->next;
        a->next = result;
        result = a;
        a = temp;
    }

    while (b != NULL)
    {
        Node *temp = b->next;
        b->next = result;
        result = b;
        b = temp;
    }

    return result;
}

void printList(struct Node *Node)



{while (Node != NULL)
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

    struct Node *result = NULL;
    Node *a = newNode(5);
    a->next = newNode(9);
    a->next->next = newNode(25);

    Node *b = newNode(3);
    b->next = newNode(1);
    b->next->next = newNode(50);

    cout << "list A: \n";
    printList(a);

    cout << "\n list B: \n";
    printList(b);

    result = merge_lists(a, b);

    cout << "\nmerged linked: \n";
    printList(result);

    return 0;
}
