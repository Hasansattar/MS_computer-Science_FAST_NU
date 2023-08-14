#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *temp = NULL, *first = NULL, *second = NULL;

struct Node *Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = A[0];
    temp->next = NULL;
    last = temp;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return temp;
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void Concat(struct Node *first, struct Node *second)
{
    struct Node *p = first;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = second->next->next;
    second->next->next = NULL;
}
void CommonNodes(struct Node *head1, struct Node *head2)
{

    struct Node *current1 = first;

    struct Node *current2 = second;

    while (current1 != NULL)
    {

        while (current2 != NULL)
        {

            if (current1->data == current2->data)
            {
                cout << "\n";
                cout << "same nodes on both Linked list:  " << current1->data << "  " << endl;
            }

            current2 = current2->next;
        }

        current1 = current1->next;

        current2 = second;
    }
}

int main()
{
    int A[] = {9, 7, 4, 3, 5, 16};
    int B[] = {3, 5, 6, 8, 10, 20};
    first = Create(A, 6);
    second = Create(B, 6);

    cout << "A Linked List: ";
    Display(first);

    cout << "\n B Linked List: ";
    Display(second);

    Concat(first, second);

    cout << "\n\n connect Linked List: \n";
    Display(first);

    CommonNodes(first, second);

    return 0;
}
