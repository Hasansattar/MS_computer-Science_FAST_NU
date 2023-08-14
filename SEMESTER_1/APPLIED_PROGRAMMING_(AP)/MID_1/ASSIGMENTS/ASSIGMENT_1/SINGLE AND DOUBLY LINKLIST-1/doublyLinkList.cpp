#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next,*prev;
};
 
class doublyList
{
  private:
    Node*head, *temp;
  
  public:
    /*-------------------------------INSERTION---------------------------------------*/ 
    void insertAtFront(Node*& head, int value){
     {
	  Node* node = new Node();
	node->data = value;
	node->next = head;
	if (head != NULL)
		head->prev = node;

	node->prev = NULL;
	head = node;
}

    }
    void insertAtEnd(Node*& head, int value)
{
	if (head == NULL)
	{
		insertAtFront(head, value);
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


   void insertAtMid(Node*& head, int value, int after)
{
	Node* node = new Node();
	node->data = value;

	Node* temp = head;
	while (temp != NULL && temp->data != after)
		temp = temp->next;

	if (temp == NULL)	 
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



   
    
    /*-----------------------------DELETION----------------------------*/
    void deleteAtFront(Node*& head){
     Node* node = head;
	head = head->next;
	head->prev = NULL;
	delete node;
    }
    void deleteAtEnd(Node*& head){
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

    void deleteAtMid(Node*& head, int key){

      Node* temp = head;
	if (temp->data == key)	 
	{
		deleteAtFront(head);
		temp = temp->next;
		return;
	}
	while (temp != NULL && temp->data != key)
		temp = temp->next;
	if (temp == NULL)	 
	{
		cout << "Node Not found..." << endl;
		return;
	}

	if (temp->next == NULL)
	{
		deleteAtEnd(head);
	}
	else
	{
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
	}
    }
    
    
 /*--------------------------SEARCHING------------------------------*/

bool search(Node *head, int key)
{

  Node *temp = head;

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

     /*--------------------------REVERSE------------------------------*/
Node *reverve(Node *&head)
{

  Node *prevptr = NULL;
  Node *currptr = head;
  Node *nextptr;
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
   

    /*--------------------------DISPLAY------------------------------*/
    void display(Node* head)
{
	Node* temp = head;
	cout << "[ ";
	while (temp != NULL)
	{
		cout << temp->data << " ->";
		temp = temp->next;
	}
	cout << "]\n";
}

};

int main()
{
     Node* head = NULL;
    doublyList obj;
          /*----------------------------------------INSERTION--------------------------------*/

    obj.insertAtFront(head,1);
    obj.display(head);
      obj.insertAtFront(head,2);
    obj.display(head);
    obj.insertAtEnd(head,3);
     obj.display(head);
    obj.insertAtEnd(head,4);
     obj.display(head);
      obj.insertAtEnd(head,5);
     obj.display(head);
      obj.insertAtEnd(head,6);
     obj.display(head);
    obj.insertAtMid(head,8,1);
    obj.display(head);
   

   /*----------------------------------------DELETION--------------------------------*/

    obj.deleteAtFront(head);
    obj.display(head);
    obj.deleteAtEnd(head);
    obj.display(head);
    obj.deleteAtMid(head,8);
    obj.display(head);
   
    
          /*--------------------------SEARCHIING--------------------------------------*/

    obj.search(head, 1);
    obj.display(head);
    

      /*--------------------------REVERSE  ------------------------------*/

      Node *newhead = obj.reverve(head);
    obj.display(newhead);
    return 0;
}