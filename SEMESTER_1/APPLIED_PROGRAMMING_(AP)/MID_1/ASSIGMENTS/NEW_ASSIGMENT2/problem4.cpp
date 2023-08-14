#include <bits/stdc++.h> 
using namespace std; 
  
 
class Node  
{  
    public: 
        int data;  
        Node *next;  
};  
void insert(Node **, int);    
void display(Node *);       
void merge(Node *, Node **);  
  
  

void insert(Node ** head_ref, int new_data)  
{  
    Node* new_node = new Node(); 
    new_node->data = new_data;  
    new_node->next = (*head_ref);  
    (*head_ref) = new_node;  
}  
  
 
void display(Node *head)  
{  
    Node *temp = head;  
    while (temp != NULL)  
    {  
        cout<<temp->data<<" ";  
        temp = temp->next;  
    }  
    cout<<endl; 
}  
  
 
void merge(Node *first, Node **second)  
{  
    Node *firstRef = first; 
    Node *secondRef=*second; 
    
     
    while (firstRef->next != NULL)  
    {  
         firstRef = firstRef->next;
    }  

      
    firstRef->next = secondRef->next->next;
}

int main()  
{  
    Node *first = NULL, *second = NULL;
      
    insert(&first, 5);  
    insert(&first, 4);  
    insert(&first, 3); 
    insert(&first, 2);  
    insert(&first, 1);  
    cout<<"First Linked List:\n";  
    display(first);  
  
 
    insert(&second, 10);  
    insert(&second, 9);  
    insert(&second, 8);  
    insert(&second, 7);  
    insert(&second, 6);  
    cout<<"\nSecond Linked List:\n";  
    display(second);  
  
    merge(first, &second);  
  
   
    cout<<"\nMerged list is: ";  
    display(first);  
  
    return 0;  
}  
 