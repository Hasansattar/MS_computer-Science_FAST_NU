#include <iostream>
using namespace std;
class Stack
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    bool push(int x)
    {
        Node *temp = new Node;
        if (temp == NULL)
            return false;
        temp->data = x;
        temp->next = top;
        top = temp;
        return true;
    }
    int pop()
    {
        int x = -1;
        if (top == NULL)
            return x;
        Node *temp = top;
        top = top->next;
        x = temp->data;
        delete temp;
        return x;
    }
    bool isEmpty()
    {
        return top == NULL;
    }
    void display()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int evaluate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}
int main()
{
    Stack s;
    string exp;
    cout << "Enter an expression: ";
    cin >> exp;
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == ' ')
            i++;
        else if (isdigit(exp[i]))
        {
            int val = 0;
            while (i < exp.length() &&
                   isdigit(exp[i]))
            {
                val = (val * 10) + (exp[i] - '0');
                i++;
            }
            i--;
            s.push(val);
        }
        else
        {
            int val1 = s.pop();
            int val2 = s.pop();
            switch (exp[i])
            {
            case '+':
                s.push(val2 + val1);
                break;
            case '-':
                s.push(val2 - val1);
                break;
            case '*':
                s.push(val2 * val1);
                break;
            case '/':
                s.push(val2 / val1);
                break;
           
            }
        }
        i++;
    }
    cout << "Result: " << s.pop();
    return 0;
}