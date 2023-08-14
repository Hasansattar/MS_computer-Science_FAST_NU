#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
 
class singleList
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
	  head = node;
}

    }
    void insertAtEnd(Node*& head, int value)
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


   void insertAtMid(Node*& head, int value, int after)
{
	Node* node = new Node();
	if (head == NULL)
	{
		cout << "Head is Null !!!" << endl;
 		return;
	}

	Node* temp = head;

	while (temp->data != after)
		temp = temp->next;

	node->data = value;
	node->next = temp->next;

	temp->next = node;
}



   
    
    /*-----------------------------DELETION----------------------------*/
    void deleteAtFront(Node*& head){
      Node* node = head;
	head = head->next;
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
    
    
 /*--------------------------SEARCHING------------------------------*/

bool search(Node *head, int key)
{
    Node *temp = head;
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
    singleList obj;
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