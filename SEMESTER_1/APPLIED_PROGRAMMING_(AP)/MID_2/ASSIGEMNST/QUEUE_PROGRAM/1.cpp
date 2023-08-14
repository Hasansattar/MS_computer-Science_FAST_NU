#include <iostream>
using namespace std;

const int size = 5;

class Q
{
    int front, rear;
    int queue[size];

public:
    Q();

    void enqueue(int);
    int dequeue();
    void display();
    int isEmpty();
    int count();
    void shiftElements();
    int FrontElement();
};
Q::Q()
{
    front = rear = -1;
}

void Q::enqueue(int element)
{
    if (((rear - front) == (size - 1)) && (rear == (size - 1)))
    {

        cout << "overflow element cannot be entered\n";
        return;
    }
    else if (front == -1)
    {
        queue[++rear] = element;
        front = 0;
    }
    else if (rear < (size - 1))
    {
        queue[++rear] = element;
    }
}

int Q::isEmpty()
{
    if (front = 0)
    {
        cout << "Queue is empty";
    }
}

void Q::display()
{
    if (front >= 0)
        for (int i = front; i <= rear; i++)
            cout << queue[i] << "  ";
}

int Q::dequeue()
{
    int a;
    if ((rear == -1) || (front == -1))
    {
        cout << "under flow: \n";
        return 0;
    }
    else
    {
        a = queue[front];
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
    return a;
}

int Q::count()
{
    int f, r, c = 0;
    f = front, r = rear;
    while (f++ <= r)
    {
        c++;
    }
    return c;
}

// int FrontElement()
// {
//     if(front==0)
//     {
//         cout<<" queue is empty";
//         return 0;
//     }
//     int x=queue[front];
//     return x;
// }

void Q::shiftElements()
{
    int f = front, t = -1;
    while (f <= rear)
    {
        queue[++t] = queue[f++];
    }
    front = 0;
    rear = t;
    cout << endl
         << "Items shifted in the Q" << endl;
}

int main()
{
    Q q1;
    q1.enqueue(90);
    q1.enqueue(5);
    q1.enqueue(78);
    q1.enqueue(35);
    q1.enqueue(10);

    cout << "Total number of elements :" << q1.count() << endl;
    q1.display();
    cout << "Dequeue item:" << q1.dequeue() << endl;
    cout << "Dequeue item:" << q1.dequeue() << endl;

    cout << "Total number of elements : " << q1.count() << endl;
    q1.display();
    if (q1.isEmpty())
        cout << "Queue is empty" << endl;
    else
    {
        cout << "Not empty" << endl;
    }
}