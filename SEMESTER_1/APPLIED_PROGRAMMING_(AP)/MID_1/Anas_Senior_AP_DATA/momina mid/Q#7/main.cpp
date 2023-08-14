#include <iostream>

using namespace std;

void delete_value_by_index(int a[],int x){
    for(int i=x;i<10;i++){
    a[i]=a[i+1];
    }

    cout<<"new array is : ";
    for(int i=0;i<10;i++){
        cout<<a[i];
    }
}

void delete_value_by_number(int a[],int x){
int n=9;
for(int i=0;i<n;i++){
        if(a[i]==x){
        for(int j=i;j<n;j++){
        a[j]=a[j+1];
            }
        }

    }

    cout<<"new array is : ";
    for(int i=0;i<10;i++){
        cout<<a[i];
    }

}

int main()
{
    int a[10]={0};
    int x=0;
    cout<<"enter 10 elements: ";
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    cout<<endl<<"Enter index to delete value: ";
    cin>>x;
    delete_value_by_index(a,x);
    cout<<endl<<"Enter number to delete from array: ";
    cin>>x;
    delete_value_by_number(a,x);
    return 0;
}
