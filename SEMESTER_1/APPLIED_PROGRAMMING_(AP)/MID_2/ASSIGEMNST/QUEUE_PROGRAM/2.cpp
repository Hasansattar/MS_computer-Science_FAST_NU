#include <iostream>
using namespace std;

class qnode
{
    public:
    int info;
    qnode *next;
};

class queue
{
    qnode *front,*rear;
    public:
     queue();
    void enqueue(int);
    int dequeue();
    void display();
    int isEmpty();
};

  queue::queue()
  {
    front=NULL;
    rear=NULL;
  }

void queue::enqueue(int x)
{
    if(rear==NULL)
    {
        rear=new qnode;
        rear->next=NULL;
        rear->info=x;
        front=rear;
    }
    else
    {
        qnode *temp;
        temp=new qnode;
        temp->info=x;
        temp->next=NULL;
        rear->next=temp;
        rear=temp;
    }
    
}

int queue::dequeue()
{
    int x=front->info;
    if(front==NULL)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        qnode *temp=front;
        if (front==rear)
        {
            front=NULL;
            rear=NULL;
            delete temp;
            return x;
        }
        front=front->next;
    }
    return x;
    
}


void queue:: display()
{
    qnode *current;
    if (front==NULL)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    current=front;
    while (current!=rear)
    {
        cout<<current->info<<endl;
        current=current->next;
    }
    cout<<current->info<<endl;
    
}





int queue::isEmpty()
{
    int flag=0;
    if(front==NULL){
        flag=1;
    }
    return flag;
}

int main()
{
queue q1;
q1.enqueue(40);
q1.enqueue(27);
if(q1.isEmpty())
{
    cout<<"Q is empty"<<endl;
}
q1.display();
int j;
j=q1.dequeue();
cout<<"element deleted "<<j<<endl;
q1.display();
j=q1.dequeue();
cout<<"element deleted "<<j<<endl;
if(q1.isEmpty()){
    cout<<"Q is empty"<<endl;
}
q1.display();
j=q1.dequeue();
cout<<"element deleted "<<j<<endl;
q1.display();


 
}
