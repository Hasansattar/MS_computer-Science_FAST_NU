#include <bits/stdc++.h>
 #include <stack>
using namespace std;
 
 
class app1{
    public:
    void parenth(char*);
    int open_brack(char);
    int close_brack(char);
    int matching(char,char);
    int empty();
};

int app1::matching(char sym,char expr)
{
    int ans=0;
    if((sym=='(' &&  expr==')') || (sym=='{' && expr=='}' ) || (sym=='[' && expr==']') )
    ans=1;
    return ans;
}

int app1::open_brack(char b){


    int flag=0;
    if(b=='(' || b=='{' || b=='[')
    flag=1;
    return flag;
}

int app1::close_brack(char b)
{
    int flag=0;
    if(b==')' || b=='}' || b==']')
    flag=1;
    return flag;
}

void app1::parenth(char expr[])
{
int i=0;
stack<char> s1;
while (expr[i])
{
    if (open_brack(expr[i]))
    s1.push(expr[i]);
    else
    {
        if (close_brack(expr[i]))
        {
         if (!s1.empty())
           {
            char symbol=s1.pop();
            if (!matching(symbol,expr[i]))
            {
            cout<<"Not a matching parenthesis"<< endl;
            return;

            }
            
           }
           else
           {
            cout<<"Extra closing"<<endl;
            return;
           }
           
         }
         
        }
        i++;
        
    }
    
    if (s1.empty())
    cout<<"Brackets are matching "<<endl;
    else
    cout<<"Non Matching Brackets"<<endl;
  
    
    
}




int main(){
app1 a1;
char x[]="[(3+(9.4)+]";
a1.parenth(x);
return 0;

}







