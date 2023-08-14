#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

class Stack
{
    Node *Top;

public:
    Stack()
    {
        Top = NULL;
    }
    bool PUSH(char data)
    {
        Node *temp = new Node;
        if (temp == NULL)
            return false;
        temp->data = data;
        temp->next = Top;
        Top = temp;
        return true;
    }
    char POP()
    {
        if (isEmpty())
            return 0;
        Node *temp = Top;
        Top = Top->next;
        return temp->data;
    }
    bool isEmpty()
    {
        if (Top == NULL)
            return true;
        return false;
    }
    void display()
    {
        Node *temp = Top;
        //    cout << "[ ";
        while (temp != NULL)
        {
            cout << temp->data;
            temp = temp->next;
        }
        //   cout << "]";
        cout << endl;
    }
    //  Missing this function
    char top()
    {
        return Top->data;
    }
};

//  INFIX_To_POSTFIX
int PRECDENCE_OP(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    return 0;
}

string INFIX_To_POSTFIX(string str)
{
    Stack stack;
    string result;

    char c;
    int size = str.length();
    for (int i = 0; i < size; i++)
    {
        c = str[i];

        if (/*isalpha(c) || */ isdigit(c)) //  We don't need a-z A-Z, Only digits are allowed.
            result += c;
        else if (c == '(')
            stack.PUSH('(');
        else if (c == ')')
        {
            while (!stack.isEmpty() && stack.top() != '(')
            {
                result += stack.POP();
            }
            if (stack.top() == '(')
            {
                stack.POP();
            }
        }
        else
        {
            while (!stack.isEmpty() && PRECDENCE_OP(str[i]) <= PRECDENCE_OP(stack.top()))
            {
                result += stack.POP();
            }
            stack.PUSH(c);
        }
    }
    while (!stack.isEmpty())
    {
        result += stack.POP();
    }
    return result;
}

int ADD_OP(int a, int b, char op)
{
    int result = 0;
    switch (op)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    case '%':
        result = a % b;
        break;
    }
    return result;
}

int EVALUTE(string str)
{
    str = INFIX_To_POSTFIX(str);
    cout << "Postfix: " << str << endl;

    Stack values;

    int value1, value2;
    int size = str.length();

    char c;
    for (int i = 0; i < size; i++)
    {
        c = str[i];
        if (/*isalpha(c) || */ isdigit(c))
            values.PUSH(c - '0'); //   char->int
        else
        {
            value1 = values.POP();
            value2 = values.POP();
            cout << "Evaluating: " << value1 << c << value2 << endl;
            values.PUSH(ADD_OP(value2, value1, c));
        }
    }
    return values.POP();
}

int main()
{
    string str = "(7+(6*3+2)-(6/3))";
    int result = EVALUTE(str);
    cout << "NOW Result is : " << result << endl;

    system("PAUSE");
    return 0;
}
