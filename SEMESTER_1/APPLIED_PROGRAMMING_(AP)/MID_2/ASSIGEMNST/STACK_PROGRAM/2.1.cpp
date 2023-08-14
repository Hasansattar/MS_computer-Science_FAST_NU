#include <iostream>
using namespace std;

class stacknode{
    public:
    char data;
    stacknode *next;
};
class stack{

    stacknode *top;
    public:
    stack();
    void push(char);
    char pop();
    void display();
    int size();
};


stack::stack(){
top=NULL;

}
void stack::push(char element){

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



char stack::pop(){
    if(top==NULL){
        cout<<"stack is empty"<<endl;
        return 0;
    }
    stacknode* temp=top;
    char el=temp->data;
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
s1.push('A');
s1.push('B');
s1.push('C');
cout<<"Element before pop"<<endl;
s1.display();
cout<<"pop element "<<s1.pop()<<endl;
cout<<"pop element"<<s1.pop()<<endl;
s1.display();
return 0;



}