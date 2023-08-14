#include <iostream>

#include <stdlib.h>

using namespace std;

typedef struct node

{

int data;

struct node* l;

struct node* r;

}BST;

BST* insert(int value)
{

BST* node = (BST*)malloc(sizeof(BST));

node->data = value;

node->l = NULL;

node->r = NULL;

return node;

}

BST* nodeInsert(BST* root, int value)

{

if(root == NULL)

return insert(value);

if(value < root->data)

root->l = nodeInsert(root->l, value);
else

root->r = nodeInsert(root->r, value);
return root;

}

BST* deleteNode(BST* root, int value)

{

if (root == NULL)

return root;

if (value < root->data)

root->l = deleteNode(root->l, value);

else if (value> root->data)

root->r = deleteNode(root->r, value);
else
{

if (root->l== NULL)

{

BST *temp = root->r;

free(root);

return temp;

}

else if (root->r== NULL)

{

BST *temp = root->l;

free(root);

return temp;

}

BST* temp = root->r;

while (temp->l != NULL)

temp = temp->l;

root->data = temp->data;

root->r = deleteNode(root->r, temp->data);

}

return root;

}

int findMin(BST* root)

{

BST *temp = root;

while(temp->l)

temp = temp->l;

return temp->data;

}

int findMax(BST* root)

{

BST *temp = root;

while(temp->r)

temp = temp->r;

return temp->data;

}

void printInorder(BST* root)
{

if(root == NULL) return;

printInorder(root->l);

cout<<root->data <<" ";

printInorder(root->r);

}

int search(BST* root, int value)

{

if (root == NULL || root->data == value)

return 1;

if (root->data < value)

return search(root->r, value);

return search(root->l, value);

return 0;

}

int main()

{

BST* root = NULL;

root = insert(4);

nodeInsert(root,7);

nodeInsert(root,9);

nodeInsert(root,1);

nodeInsert(root,5);

nodeInsert(root,18);

nodeInsert(root,8);

nodeInsert(root,2);

nodeInsert(root,1);

nodeInsert(root,20);

cout << "Here is the inorder : ";

printInorder(root);

cout << endl;

int min = findMin(root);

int max = findMax(root);

cout << "Here is The Minimum element is : " << min << endl;

cout << "Here is the Maximum element is : " << max << endl;

if(search(root, 13))

cout << "Found IN THIS PROGRAM" << endl;

else

cout << "Not found IN THIS PROGRAM " << endl;

if(search(root, 8))

cout << "Found IN THIS PROGRAM " << endl;

else

cout << "Not found IN THIS PROGRAM" << endl;

if(search(root, 29))

cout << "Found IN THIS PROGRAM " << endl;

else

cout << "Not found IN THIS PROGRAM" << endl;

root = deleteNode(root, 219);

printInorder(root);

cout << endl;

root = deleteNode(root, 2);

printInorder(root);

cout << endl;

root = deleteNode(root, 8);

printInorder(root);

cout << endl;

root = deleteNode(root, 3);

printInorder(root);

cout << endl;

root = deleteNode(root, 5);

printInorder(root);

cout << endl;

return 0;

}