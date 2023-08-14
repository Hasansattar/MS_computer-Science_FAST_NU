#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *ADD_NODE(int data);
class MirrorTree
{

public:
    void MINIMNAL_HEIGHT(int arr[], int start, int end);
    void PRE_ORDER(Node *node);
};

Node *MINIMNAL_HEIGHT(int arr[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node *root = ADD_NODE(arr[mid]);
    root->left = MINIMNAL_HEIGHT(arr, start, mid - 1);

    root->right = MINIMNAL_HEIGHT(arr, mid + 1, end);
    return root;
}

Node *ADD_NODE(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = NULL;

    node->right = NULL;
    return node;
}
void PRE_ORDER(Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    PRE_ORDER(node->left);
    PRE_ORDER(node->right);
}
int main()
{

    int arr[] = {5, 6, 7, 8, 9, 10, 11};

    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = MINIMNAL_HEIGHT(arr, 0, n - 1);

    cout << "PreOrder Minimal Height BST \n";
    PRE_ORDER(root);
    return 0;
}
