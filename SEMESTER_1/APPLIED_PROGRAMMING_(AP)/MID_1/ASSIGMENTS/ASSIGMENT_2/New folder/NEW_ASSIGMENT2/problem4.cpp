#include <iostream> 
using namespace std; 
  
 
class Node  
{   public: 
        int data;  
        
        Node *next;  
};  
void insert(Node **, int); 


void print(Node *);       



void merge(Node *, Node **);  
  
  
int main()  
{  
    Node *first = NULL, *second = NULL;
      
    insert(&first, 3); 

    insert(&first, 2);  
    
    insert(&first, 1);  


    cout<<"First List:\n";  


    print(first);  
  
 
    insert(&second, 10);  

    insert(&second, 9);  

    insert(&second, 8); 

    insert(&second, 7); 

    insert(&second, 6); 

    insert(&second, 5); 

    insert(&second, 4);
    cout<<"\nSecond List:\n";  
    print(second);  
  
    merge(first, &second);  
  
   
    cout<<"\nMerged list is: ";  
    print(first);  
  
    return 0;  
}  
 
void insert(Node ** head_ref, int new_data)  
{  
    Node* new_node = new Node(); 

    new_node->data = new_data;  
    new_node->next = (*head_ref); 


    (*head_ref) = new_node;  
}  
  
 
void print(Node *head)  
{  
    Node *temp = head; 
      
    while (temp  != NULL )  
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