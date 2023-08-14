#include <iostream>
using namespace std;
class Deque
{

private:
    int *Array;

    int Size;

    int front, rear;

public:
    Deque(int s)
    {

        Size = s;

        Array = new int[Size];

        front = rear = -1;
    }

    bool isEmpty()
    {

        if (front == -1)
        {

            return true;
        }

        else
        {

            return false;
        }
    }

    bool isFull()
    {

        if (((rear + 1) % Size) == front)
        {

            return true;
        }

        else
        {

            return false;
        }
    }

    bool insertion_at_front(int data)
    {

        if (isFull())
        {

            cout << "Deque OverFlow." << endl;

            return false;
        }

        else if (isEmpty())
        {

            front = rear = 0;
        }

        else if (front == 0)
        {

            front = Size - 1;
        }

        else
        {

            front = (front - 1) % Size;
        }
    }

    bool insertion_at_rear(int data)
    {

        if (isFull())
        {

            cout << " Deque OverFlow." << endl;

            return false;
        }

        else if (isEmpty())
        {

            front = rear = 0;
        }

        else
        {

            rear = (rear + 1) % Size;
        }

        Array[rear] = data;

        return true;
    }

    bool deletion_at_front()
    {

        if (isEmpty())
        {

            cout << "All the cars are removed ." << endl;
            return false;
        }

        else if (front == rear)
        {

            front = rear = -1;
        }

        else
        {

            Array[rear] = 0;

            front = (front + 1) % Size;
        }
    }

    bool deletion_at_rear()
    {

        if (isEmpty())
        {

            cout << "All the cars are removed ." << endl;

            return false;
        }

        else if (front == rear)
        {

            front = rear = -1;
        }

        else
        {

            Array[rear] = 0;

            rear = (rear + 1) % Size;
        }
    }

    void Display()
    {

        cout << " Insertion";

        for (int i = 0; i < Size; i++)
        {

            cout << Array[i] << "  ";
        }
    }
};

int main()

{

    int size;

    cout << " Enter the total number of cars  :  ";

    cin >> size;

    Deque o1(size);

    int data, index;

    while (true)
    {

        cout << " Enter 1 : to insert at front" << endl;
        cout << " Enter 2 : to insert at rear" << endl;
        cout << " Enter 3 : to delete at front" << endl;
        cout << " Enter 4 : to delete at rear" << endl;
        cout << " Enter 5 : to display deque" << endl;
        cout << " Enter 6 : to exit the program" << endl;

        cout << " Enter your choice  :  ";

        cin >> index;

        if (index == 1)
        {
            cout << "Enter the car " << endl;
            cin >> data;

            o1.insertion_at_front(data);
        }

        else if (index == 2)
        {
            cout << "Enter the car " << endl;
            cin >> data;

            o1.insertion_at_rear(data);
        }

        else if (index == 3)
        {

            o1.deletion_at_front();
        }

        else if (index == 4)
        {

            o1.deletion_at_rear();
        }

        else if (index == 5)
        {
            o1.Display();
        }
        else
        {
            exit;
        }
    }

    cout << endl;
    system("pause");

    return 0;
}
