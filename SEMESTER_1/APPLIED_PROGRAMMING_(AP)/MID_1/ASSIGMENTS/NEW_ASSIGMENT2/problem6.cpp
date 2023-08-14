#include <iostream>
using namespace std;

struct Node
{
	char data;
	Node* next, * prev;
};

void Insert(Node*& head, char value)
{
    Node* node = new Node();
    node->data = value;
    if (head == NULL)
    {
        node->next = node->prev = node;
        head = node;
    }
    else
    {
        Node* last = head->prev;
        node->next = head;
        head->prev = node;
        node->prev = last;
        last->next = node;
    }
}

void PrintList(Node*& head)
{
    Node* ptr = head;
    if (ptr != NULL)
    {
        do
        {
            cout << ptr->data;
            ptr = ptr->next;
        } while (ptr != head);
    }
}

void PigLatin(Node*& head, string str)
{
    string vowel = "aeiouyAEIOUY";  
    for (int i = 0; i < str.length(); i++)
    {
        Insert(head, str[i]);
    }

     
    for (int i = 0; i < vowel.length(); i++)
    {
        if (vowel[i] == head->data)
        {
            Insert(head, '-');
            Insert(head, 'w');
            Insert(head, 'a');
            Insert(head, 'y');
            return;
        }
    }
    
    
    bool check_for_vowel = false;
    Node* ptr = head;
    do
    {
        for (int i = 0; i < vowel.length(); i++)
        {
            if (vowel[i] == ptr->data)
            {
                check_for_vowel = true;
                break;
            }
        }
        if (check_for_vowel)
            break;
        ptr = ptr->next;
    } while (ptr != head);

    if (!check_for_vowel)    
    {
        Insert(head, '-');
        Insert(head, 'w');
        Insert(head, 'a');
        Insert(head, 'y');
        return;
    }

 
    Insert(head, '-');
    ptr = head; 
    do
    {
        for (int i = 0; i < vowel.length(); i++)
        {
            if (vowel[i] == ptr->data)
            {
                head = ptr;
                Insert(head, 'a');
                Insert(head, 'y');
                return;
            }
        }
        ptr = ptr->next;
    } while (ptr != head);
}

int main()
{
    Node* node = NULL;

    cout << "Running Test case for: eye\nResult: ";
    PigLatin(node, "eye");
    PrintList(node);
    cout << endl;

    Node* node2 = NULL;
    cout << "Running Test case for: There\nResult: ";
    PigLatin(node2, "There");
    PrintList(node2);
    cout << endl;

    Node* node3 = NULL;
    cout << "Running Test case for: 1234\nResult: ";
    PigLatin(node3, "1234");
    PrintList(node3);
    cout << endl;

	system("PAUSE");
	return 0;
}
