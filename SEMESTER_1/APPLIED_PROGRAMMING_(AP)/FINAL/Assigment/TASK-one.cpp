#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T value;
    Node* left, * right;
};

template <class T>
class BST
{
private:
    Node<T>* tree;
    void preorderTraversal(Node<T>* node)
    {
        if (node == NULL)
            return;
        cout << node->value << ' ';
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
    void inorderTraversal(Node<T>* node)
    {
        if (node == NULL)
            return;
        preorderTraversal(node->left);
        cout << node->value << ' ';
        preorderTraversal(node->right);
    }

    void postorderTraversal(Node<T>* node)
    {
        if (node == NULL)
            return;
        preorderTraversal(node->left);
        preorderTraversal(node->right);
        cout << node->value << ' ';
    }

    int findMax(Node<T>* node)
    {
        if (node->right == NULL)
            return node->value;
        findMax(node->right);
    }
    int findMin(Node<T>* node)
    {
        if (node->left == NULL)
            return node->value;
        findMin(node->left);
    }
    Node<T>* DeleteKey(Node<T>* node, T value)
    {
        if (node == NULL)
            return NULL;

        if (value < node->value)
            node->left = DeleteKey(node->left, value);
        else if (value > node->value)
            node->right = DeleteKey(node->right, value);
        else
        {
            if (node->left == NULL)
            {
                Node<T>* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                Node<T>* temp = node->left;
                delete node;
                return temp;
            }
            Node<T>* temp = node->right;
            while (temp->left != NULL)
                temp = temp->left;
            node->value = temp->value;
            node->right = DeleteKey(node->right, temp->value);
        }
        return node;
    }
    bool SearchKey(Node<T>* node, T value)
    {
        if (node == NULL)
            return false;

        if (value > node->value)
            return SearchKey(node->right, value);
        else if (value < node->value)
            return SearchKey(node->left, value);
        else
            return true;
    }
    int treeHeight(Node<T>* node)
    {
        if (node == NULL)
            return 0;
        else
        {
            int left_height = treeHeight(node->left);
            int right_height = treeHeight(node->right);

            if (left_height > right_height)
                return left_height + 1;
            else
                return right_height + 1;
        }
    }
    int treeNodeCount(Node<T>* node)
    {
        if (node == NULL)
            return 0;
        return 1 + treeNodeCount(node->left) + treeNodeCount(node->right);

    }
    int treeLeavesCount(Node<T>* node)
    {
        if (node == NULL)
            return 0;

        if (node->left == NULL && node->right == NULL)
            return 1;
        else
            return treeLeavesCount(node->left) + treeLeavesCount(node->right);
    }
    void printNodeOnEachLevel(Node<T>* node, int level)
    {
        if (node == NULL)
            return;
        if (level == 1)
            cout << node->value << " ";
        else if (level > 1)
        {
            printNodeOnEachLevel(node->left, level - 1);
            printNodeOnEachLevel(node->right, level - 1);
        }
    }
    void printNodeLevel(Node<T>* node)
    {
        int height = treeHeight(node);
        for (int i = 1; i <= height; i++)
        {
            printNodeOnEachLevel(node, i);
            cout << endl;
        }
    }
public:
    BST() : tree(NULL) {}
    void Insert(T value)
    {
        Node<T>* node = new Node<T>();
        node->value = value;
        node->left = node->right = NULL;
        if (tree == NULL)
        {
            tree = node;
        }
        else
        {
            Node<T>* temp = tree;
            Node<T>* parent = NULL;
            // cout << "DEBUG;" << endl;
            while (temp != NULL)
            {
                if (value < temp->value)
                {
                    // cout << "LEFT;" << endl;
                    parent = temp;
                    temp = temp->left;
                }
                else if (value > temp->value)
                {
                    // cout << "RIGHT;" << endl;
                    parent = temp;
                    temp = temp->right;
                }
                else
                {
                    cout << "Node already Exists...\n";
                    return;
                }
            }
            if (value < parent->value)
                parent->left = node;
            else if (value > parent->value)
                parent->right = node;
        }
    }

    int findMax()
    {
        int result = findMax(tree);
        return result;
    }
    int findMin()
    {
        int result = findMin(tree);
        return result;
    }

    void preorderTraversal()
    {
        preorderTraversal(tree);
    }
    void inorderTraversal()
    {
        inorderTraversal(tree);
    }
    void postorderTraversal()
    {
        postorderTraversal(tree);
    }
    void DeleteKey(T value)
    {
        DeleteKey(tree, value);
    }
    void SearchKey(T value)
    {
        if (SearchKey(tree, value) == true)
        {
            cout << "Node with value[" << value << "], has been found" << endl;
        }
        else
        {
            cout << "Node with value[" << value << "], not found" << endl;
        }
    }
    int treeHeight()
    {
        int height = treeHeight(tree);
        return height;
    }
    int treeNodeCount()
    {
        int nodes = treeNodeCount(tree);
        return nodes;
    }
    int treeLeavesCount()
    {
        int leaves = treeLeavesCount(tree);
        return leaves;
    }
    void printNodeLevel()
    {
        printNodeLevel(tree);
    }
};

int main()
{
    BST<int> bst; // 65 55 22 44 61 19 90 10 78 52
    bst.Insert(65);
    bst.Insert(55);
    bst.Insert(22);
    bst.Insert(44);
    bst.Insert(61);
    bst.Insert(19);
    bst.Insert(90);
    bst.Insert(10);
    bst.Insert(78);
    bst.Insert(52);

    bst.DeleteKey(10);
    bst.DeleteKey(65);
    bst.DeleteKey(100); //  This value doesn't exist

    bst.SearchKey(55);
    bst.SearchKey(90);
    bst.SearchKey(100); //  This value doesn't exist

    cout << "findMax(): " << bst.findMax() << endl;
    cout << "findMin(): " << bst.findMin() << endl;

    cout << "Pre Order: ";
    bst.preorderTraversal();
    cout << endl;

    cout << "In Order: ";
    bst.inorderTraversal();
    cout << endl;

    cout << "Post Order: ";
    bst.postorderTraversal();
    cout << endl;

    cout << "treeHeight(): " << bst.treeHeight() << endl;
    cout << "treeNodeCount(): " << bst.treeNodeCount() << endl;
    cout << "treeLeavesCount(): " << bst.treeLeavesCount() << endl;

    cout << "printNodeLevel(): " << endl;
    bst.printNodeLevel();
    cout << endl;

    system("PAUSE");
    return 0;
}
