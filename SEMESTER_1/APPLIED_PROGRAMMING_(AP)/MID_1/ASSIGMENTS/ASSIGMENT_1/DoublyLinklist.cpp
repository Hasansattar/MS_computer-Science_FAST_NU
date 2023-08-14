#include <iostream>
using namespace std;

class node
{

public:
  int data;
  node *next;
  node *prev;

  node(int val)
  {
    data = val;
    next = NULL;
    prev = NULL;
  }
};
/*--------------------------------INSERT AT HEAD---------------------------*/

void insertAtHead(node *&head, int val)
{

  node *n = new node(val);
  n->next = head;
  if (head != NULL)
  {
    head->prev = n;
  }

  n->prev = NULL;

  head = n;
}

/*--------------------------------INSERT AT TAIL---------------------------*/
void insertAtTail(node *&head, int val)
{

  if (head == NULL)
  {
    insertAtHead(head, val);
    return;
  }

  node *n = new node(val);
  node *temp = head;

  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = n;
  n->prev = temp;
  n->next = NULL;
}

void insertAtMid(node *&head, int after, int val)
{
  node *n = new node(val);
  node *temp = head;

  while (temp->data != after)

  {
    temp = temp->next;
  }
  n->data = val;
  n->next = temp->next;
  temp->next->prev = n;
  temp->next = n;
  n->prev = temp;
}

/*--------------------------------DELETION-------------------------------------*/

void deleteAtHead(node *&head)
{
  node *todelete = head;
  head = head->next;
  head->prev = NULL;

  delete todelete;
}

void deletion(node *&head, int pos)
{
  if (pos == 1)
  {
    deleteAtHead(head);
    return;
  }

  node *temp = head;
  int count = 1;

  while (temp != NULL && count != pos)
  {
    temp = temp->next;
    count++;
  }

  temp->prev->next = temp->next;

  if (temp->next != NULL)
  {
    temp->next->prev = temp->prev;
  }

  delete temp;
}

/*--------------------------SEARCHING------------------------------*/

bool search(node *head, int key)
{

  node *temp = head;

  int pos = 0;

  if (temp != NULL)
  {
    while (temp != NULL)
    {
      pos++;
      if (temp->data == key)
      {
        cout << temp->data << endl;
        break;
      }
      temp = temp->next;
    }
  }
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

/*--------------------------------DISPLAY ALL LINK LIST---------------------------*/
void display(node *head)
{
  node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{

  node *head = NULL;

  /*--------------------------------INSERT AT TAIL---------------------------*/
  insertAtTail(head, 1);
  insertAtTail(head, 2);
  insertAtTail(head, 3);
  insertAtTail(head, 4);
  display(head);
  /*--------------------------------INSERT AT HEAD---------------------------*/
  insertAtHead(head, 5);
  display(head);
/*--------------------------------INSERT AT MIDDILE---------------------------*/
  insertAtMid(head, 2, 8);
  display(head);

  /*--------------------------------DELETION-------------------------------------*/
  deletion(head, 5);
  display(head);

  /*--------------------------SEARCHIING--------------------------------------*/

  search(head, 8);
  // cout<<search(head,4)<<endl;

  /*--------------------------REVERSE OPERATION IN LINKLIST------------------------------*/

  node *newhead = reverve(head);
  display(newhead);

  return 0;
}