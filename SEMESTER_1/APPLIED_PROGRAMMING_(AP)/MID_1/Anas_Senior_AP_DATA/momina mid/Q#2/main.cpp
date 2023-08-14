#include <iostream>

using namespace std;

void  swapFrontBack(char a[],int n){
    cout<<endl<<"old array is ";
    for(int i=0;i<n;i++){
    cout<<a[i];
    }
    int temp=a[n-1];
    a[n-1]=a[0];
    a[0]=temp;
    cout<<endl<<"array after swap is ";
    for(int i=0;i<n;i++){
    cout<<a[i];
    }
}

int main()
{
    int a[10]={};
    int n=0;
    cout << "How many characters do you want to insert?  ";
    cin>>n;
    while(n<2){
        cout<<"you are not suppose to add less than 2 elements.Enter again: ";
        cin>>n;
    }
    cout<<endl<<"enter elements of array"<<endl;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
swapFrontBack(a,n);
    return 0;
}
