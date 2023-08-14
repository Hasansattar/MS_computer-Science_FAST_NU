#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
    string data;
    Node *next;

public:
    Node()
    {
        data = "";
        next = NULL;
    }

    Node(string d)
    {
        data = d;
        next = NULL;
    }
    void setData(string d)
    {
        data = d;
    }

    string GET_DATA()
    {
        return data;
    }

    void SET_NEXT(Node *n)
    {
        next = n;
    }

    Node *getNext()
    {
        return next;
    }
};

class Stack
{
private:
    Node *head;

public:
    Stack()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }

    void push(string s)
    {
        if (isEmpty())
        {
            head = new Node(s);
            return;
        }
        Node *n = new Node(s);
        n->SET_NEXT(head);
        head = n;
    }

    string pop()
    {
        if (isEmpty())
        {
            return "Empty !!";
        }
        Node *temp = head;
        string re = temp->GET_DATA();
        head = head->getNext();
        delete temp;
        return re;
    }

    string top()
    {
        if (isEmpty())
        {
            return "Empty!!";
        }
        return head->GET_DATA();
    }
};

string SEQUEnCE(string msg)
{
    Stack s;
    for (int i = 0; i < msg.length(); i++)
    {
        if (msg[i] == ' ')
        {
            continue;
        }
        if (msg[i] == '.' || msg[i] == ',' || msg[i] == ':' || msg[i] == ';' || msg[i] == '?' || msg[i] == '!')
        {
            s.push(".");
            continue;
        }
        string temp = "";
        while (msg[i] != ' ' && i < msg.length())
        {
            if (msg[i] == '.' || msg[i] == ',' || msg[i] == ':' || msg[i] == ';' || msg[i] == '?' || msg[i] == '!')
            {
                break;
            }
            temp.push_back(msg[i]);
            i++;
        }
        s.push(temp);
    }
    string re = "";
    while (!s.isEmpty())
    {
        string temp = s.pop();
        if (temp == ".")
        {
            continue;
        }
        re = re + temp + " ";
    }
    return re;
}

int main()
{
    string msg;
    cout << "PUT YOUR SENTENCE\n";
    getline(cin, msg);
    cout << SEQUEnCE(msg) << endl;
    return 0;
}