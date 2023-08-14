#include <iostream>
using namespace std;




class stacknode{
    public:
    int data;
    stacknode *next;
};
class stack{

    stacknode *top;
    public:
    stack();
    void push(int);
    int pop();
    void display();
    int size();
};


stack::stack(){
top=NULL;

}
void stack::push(int element){

    if(top==NULL){
        top=new stacknode;
        top->data=element;
        top->next=NULL;
    }
    else
    {
        stacknode *temp;
        temp=new stacknode;
        temp->data=element;
        temp->next=top;
        top=temp;
    }
    
}



void stack::display(){
stacknode *current;
current=top;
cout<<"Elements in the stack are "<<endl;
while (current !=NULL)
{
    cout<<current->data<<"  ";
    current=current->next;

}
cout<<endl;



}



int stack::pop(){
    if(top==NULL){
        cout<<"stack is empty"<<endl;
        return 0;
    }
    stacknode* temp=top;
    int el=temp->data;
    top=top->next;
    delete temp;
    return el;
}

int stack::size(){

    int count=0;
    if(top=NULL){

        cout<<"No element in the stack "<<endl;
        return count;
    }
    stacknode *current;
    current =top;
    while (current!=NULL)
    {
        count++;
    }
    return count;
    
}


int main(){

stack s1;
s1.push(90);
s1.push(5);
s1.push(32);
cout<<"Element before pop"<<endl;
s1.display();
cout<<"pop element "<<s1.pop()<<endl;
cout<<"pop element"<<s1.pop()<<endl;
s1.display();
return 0;



}