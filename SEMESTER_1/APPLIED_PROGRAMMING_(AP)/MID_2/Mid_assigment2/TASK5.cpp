#include<iostream>
#include<string>
using namespace std;

class node
{
public:
    char data;
     node* next;
};
class que
{

    node* front, * rear;
    int num;
public:
    que()
    {
        front = NULL; rear = NULL; num = 0;
    }
    bool isEmpty()
    {
        return (num == 0);
    }
    void enque(char x)
    {
        node* nNode;
        nNode = new node;
        nNode->data = x;
        nNode->next = NULL;
        if (isEmpty())
        {
            front = nNode; rear = nNode;
        }
        else
        {
            rear->next = nNode; nNode->next = NULL;  rear = nNode;
        }
        num++;
    }
    string deque()
    {
        string ans;
        node* temp;
        if (isEmpty()) { cout << "\nUnderflow\n"; return 0; }
        ans = front->data;
        temp = front->next;
        delete front;
        front = temp;
        num--;

        return ans;
    }
    void checkWinner(que q)
    {
        bool check=0, flag=1;
        int i=0;
        int oCount = 0, gCount = 0;
        node* current = front;
        while (current!=NULL)
        {
            if (current->data == 'o' || current->data == 'O') {
                oCount++;
                i++;
                check = true;
            }
            else {
                gCount++;
                i++;
                flag = false;
            }
            if (i == 1)
            {
                if (check)
                    oCount++;
                else
                    gCount++;
            }
            deque();
            current = current->next;
            
        }

        if (oCount > gCount)
            cout << "\n\n\t -> Winner of eLECTION IS OPPOSITION <-\n\n";
        else if(gCount>oCount)
            cout << "\n\n\t-> Winner of eLECTION IS GOVERNMENT <-\n\n";
    }
    void makeNULL()
    {
        int x;
        while (!isEmpty())
            deque();
    }
    ~que()
    {
        makeNULL();
    }

};
int main()

{
    int x;
    char val;
    //  string s="ogo";
    que obj;
    cout << "\nHow many pEople are in Senate  : "; cin >> x;
    for (int i = 0; i < x; i++)
    {
        cout << "\tEnter Belongings For Person  " << i + 1 << " : "; cin >> val;
        obj.enque(val);

    }
    cout << "\nTotal NUmber of Persons who Takes part in Voting Are  :  " << x << endl << endl;
    cout << endl << "\nThe Votes are in Order  :\n\n\t\t";
    while (!obj.isEmpty())
    {
        cout << obj.deque() << "  ";
    }
    cout << endl;
    obj.checkWinner(obj);
    while (!obj.isEmpty())
    {
        cout << obj.deque() << "  ";
    }
    cout << endl;
    system("pause");
}

