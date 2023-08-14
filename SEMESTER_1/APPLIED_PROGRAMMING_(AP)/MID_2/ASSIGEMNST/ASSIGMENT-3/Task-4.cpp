#include <stdio.h>
#include <stdlib.h>

// node of binary tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *ADD_NODE(int data)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// CALCULATING_SUM()
int CALCULATING_SUM(struct Node *temp)
{
    int sum, sumLeft, sumRight;
    sum = sumRight = sumLeft = 0;

    // Check whether tree is empty
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return 0;
    }
    else
    {

        if (temp->left != NULL)
            sumLeft = CALCULATING_SUM(temp->left);

        if (temp->right != NULL)
            sumRight = CALCULATING_SUM(temp->right);

        sum = temp->data + sumLeft + sumRight;
        return sum;
    }
}

int main()
{
    // Add_NODE nodes to the binary tree
    root = ADD_NODE(5);
    root->left = ADD_NODE(2);
    root->right = ADD_NODE(9);
    root->left->left = ADD_NODE(1);
    root->right->left = ADD_NODE(8);
    root->right->right = ADD_NODE(6);

    printf("Sum of all nodes of binary tree: %d", CALCULATING_SUM(root));
    return 0;
}

// https://www.javatpoint.com/program-to-find-the-sum-of-all-the-nodes-of-a-binary-tree