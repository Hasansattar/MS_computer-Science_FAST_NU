#include <iostream>
using namespace std;

class node
{
public:
    int data;   // data members
    node *next; // pointer => represent the next node point

    node(int val)
    {                 // constructor pass the value
        data = val;
        next = NULL;
    }
};

/*--------------------------INSERTION IN LINKLIST------------------------------*/

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void inserAtTail(node *&head, int val) // here we take head by reference not by value because we need to modify our linklist
{

    node *n = new node(val);

    if (head == NULL) //  if no one node in our linklist . head is equal to null
    {
        head = n; // then n is first node of linklist
        return;
    }

    node *temp = head; // here we make temp pointer for iterate the pointer

    while (temp->next != NULL)
    {
        temp = temp->next;
        /* code */
    }
    temp->next = n;
    n->next = NULL; // here n->next is already null that why we dont need this line
};

void insertAtMid(node *&head, int after, int val)
{
    //
    node *n = new node(val);

    if (head == NULL)
    {
        cout << "The given previous node cannot be NULL";
        return;
    }

    node *temp = head; // here we make temp pointer for iterate the pointer
    node *current = temp->next;

    while (temp->data != after)
    {
        temp = temp->next;
        current = current->next;
        /* code */
    }
     

    n->data = val;

    n->next = temp->next;

    temp->next = n;

    //    temp=temp->next;
};

void display(node *head) // here we take head by value not by reference because we cannot  do modify our linklist
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
        /* code */
    }
    cout << "null" << endl;
}

/*--------------------------SEARCHING------------------------------*/

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout << temp->data << endl;
        }
        temp = temp->next;
    }
    return false;
}
/*--------------------------DELETION IN LINKLIST------------------------------*/

void deleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;
    delete todelete;
}

void deletion(node *&head, int val)
{

    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
        /* code */
    }

    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }

    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

/*--------------------------REVERSE OPERATION IN LINKLIST------------------------------*/

node *reverve(node *&head)
{

    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;
    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
        /* code */
    }

    return prevptr;
}

int main()
{

    node *head = NULL; // to insertion something into linklist we make head

    /*--------------------------INSERTION IN TAIL------------------------------*/

    inserAtTail(head, 1);
    inserAtTail(head, 2);
    inserAtTail(head, 3);
    display(head);

    /*--------------------------INSERTION IN HEAD------------------------------*/
    insertAtHead(head, 4);
    display(head);

    inserAtTail(head, 5);
    display(head);

/*--------------------------INSERTION IN MIDDLE------------------------------*/
    insertAtMid(head, 2, 8);
    display(head);

    /*--------------------------DELETION IN LINKLIST------------------------------*/
    //
    deletion(head, 2);
    display(head);

     /*--------------------------DELETION IN HEAD------------------------------*/
    deleteAtHead(head);
    display(head);



       /*--------------------------SEARCHIING--------------------------------------*/

    search(head, 8);
    // cout<<search(head,4)<<endl;

    /*--------------------------REVERSE OPERATION IN LINKLIST------------------------------*/

    node *newhead = reverve(head);
    display(newhead);

 

    return 0;
}
