#include <iostream>

using namespace std;

int main()
{
    int num;
    cout << "enter integer (as long as 9 digits): ";
    cin>>num;

    int even=0;
    int odd=0;
    for(int i=0;i<10;i++){
        if((num%10)%2==0){
            even=even+(num%10);
        }
        else{
            odd=odd+(num%10);
        }
        num=num/10;
    }

    cout<<endl<<"Sum of even = "<<even<<endl<<"Sum of odd = "<<odd<<endl;
    return 0;
}
