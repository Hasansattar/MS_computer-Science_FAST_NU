#include <iostream>
using namespace std;
struct Node
{
    int data;

    Node *left, *right;
};
struct Node *ADD_NODE(int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void BST_GREATER(Node *root, int *sum)
{
    if (root == NULL)
    {
        return;
    }

    BST_GREATER(root->right, sum);
    *sum += root->data;
    root->data = *sum;
    BST_GREATER(root->left, sum);
}
void convertBST_GREATER(Node *root)
{
    int sum = 0;
    BST_GREATER(root, &sum);
}
void InORDER(Node *root)
{
    if (root == NULL)

    {
        return;
    }

    InORDER(root->left);

    cout << root->data << "-> ";

    InORDER(root->right);
}
int main()
{
    Node *root = ADD_NODE(5);
    root->left = ADD_NODE(2);
    root->right = ADD_NODE(7);
    root->left->left = ADD_NODE(1);
    root->left->right = ADD_NODE(3);
    root->right->left = ADD_NODE(6);
    root->right->right = ADD_NODE(8);
    root->left->left->left = NULL;
    root->left->right->right = ADD_NODE(4);
    root->right->right->left = NULL;
    root->right->right->right = ADD_NODE(9);
    cout << "Binary Search Tree is:\n";
    InORDER(root);
    convertBST_GREATER(root);
    cout << "\n\nBST_GREATER :\n";
    InORDER(root);
    return 0;
}
