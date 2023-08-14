#include <iostream>
using namespace std;

const int size=5;

class stacks{
int stack[size];
int top;
public:
stacks(){
    top=-1;
}
int push(int);
int pop();
void display();
void count_elements();
int isEmpty();

};


int stacks::push(int element)
{
if (top==(size-1))
{
    cout<<"overflow more elements cannot be inserted \n";
    return 0;
}
else{
    stack[++top]=element;
}
return 1;

}

int stacks::pop(){

    int temp=0;
    if(top==-1){
        cout<<"underflow:\n";
    }
    else{
        temp=stack[top--];
    }

    return temp;
}


int stacks::isEmpty(){
if(top==-1) return 1;
else return 0;

}



void stacks:: display(){
    for (int  i = top; i >=0; i--)
     cout<<stack[i]<<" ";
     cout<<endl;
    
}


void stacks::count_elements(){

    int cnt=0;
    int  t=top;
    while(t>=0){
        cnt++;
        t--;
    }
    cout<<"Total number of elements in stack are "<<cnt<<endl;
}

int main(){

    int n,n1;
    stacks s1;
    if(s1.isEmpty())
    cout<<"stack is empty"<<endl;
    else
    cout<<"stcak is not empty";
    s1.push(10);
    s1.push(5);
    s1.push(14);
  s1.count_elements();

  s1.push(90);
  s1.push(299);
  cout<<"Element (s) in the stack are : "<<endl;
  s1.display();
  n=s1.pop();
  cout<<"Element poped is "<<n<<endl;
  
  return 0;


}






