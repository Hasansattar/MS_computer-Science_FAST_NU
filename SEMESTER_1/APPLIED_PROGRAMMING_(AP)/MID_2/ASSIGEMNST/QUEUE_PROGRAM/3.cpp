#include <iostream>
using namespace std;

const int size=4;
class CQ
{
  int queue [size];
  int front,rear;
  public:
  CQ(){
    front=-1;
    rear=-1;
  }
  void insert(int );
  void display();
  int remove();
  int empty();


};


  void CQ:: insert (int n)
  {
    if((rear+1)% size!=front){

        rear=(rear+1) % size;
        queue[rear]=n;
        if(front<0)
        front=0;
    }
    else
    {
        cout<<"Queue overflow, element not inserted: \n";
    }
    
  }

int CQ::remove(){
    int a=0;
    if(!empty()){
        if (front==rear)
        {
           a=queue[front];
           front=rear=-1;
        }
        else
        {
            a=queue[front];
            front=(front+1)%size;
        }
        
        
    }
    else
    {
        cout<<"Queue underflow : \n";
    }
    return a;
    
}




int CQ::empty()
{
    if(front==-1)
    return 1;
    else
    {
        return 0;
    }
    
}



void CQ:: display()
{
    if(empty()){
        cout<<"Empty queue : ]\n";
    }
    else
    {
        int r,f;
        r=rear;
        f=front;
        while (f!=r)
        {
            cout<<queue[f]<<endl;
            f=(f+1) % size;
        }
        cout<<queue[f]<<endl;
        
    }
    
}




int main()
{
    CQ q1;
    q1.insert(10);
    q1.insert(45);
    q1.insert(90);
    q1.insert(21);

    cout<<"Elements in the queue are "<<endl;
    q1.display();
    q1.remove();
    q1.remove();
    q1.remove();
    cout<<"Elements after removal "<<endl;
    q1.display(); q1.display();

     q1.insert(17);
    q1.insert(56);
    q1.insert(34);
cout<<"Elements in the queue are "<<endl;
 q1.display();
  q1.remove();
    q1.remove();
    cout<<"Elements after removal " <<endl;
    q1.display();


}