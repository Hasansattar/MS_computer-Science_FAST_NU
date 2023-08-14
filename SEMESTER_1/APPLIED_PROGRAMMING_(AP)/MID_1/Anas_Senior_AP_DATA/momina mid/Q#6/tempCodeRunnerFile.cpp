#include <iostream>

using namespace std;

    void Insert_value_by_index(int arr[],int x,int y){
    for(int i=12;i>y;i--){
        arr[i]=arr[i-1];
    }
    arr[y]=x;
    cout<<endl<<"new array is: ";
    for(int i=0;i<12;i++){
    cout<<arr[i];
    }
    }
    void Insert_value_by_number(int arr[],int x,int y){
    int index=0;
    for(int i=0;i<12;i++){
        if(arr[i]==y){
        index=i+1;
        }
    }
    for(int i=12;i>index;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=x;
    cout<<endl<<"new array is: ";
    for(int i=0;i<12;i++){
    cout<<arr[i];
    }
    }
int main()
{
    int arr[12]={};
    int x,y;

    cout << "Enter 8 values" << endl;
    for(int i=0;i<8;i++){
    cin>>arr[i];
    }

    cout<<endl<<"Enter number to be inserted: ";
    cin>>x;
    cout<<endl<<"Enter Index where number to be inserted: ";
    cin>>y;
    Insert_value_by_index(arr,x,y);
    cout<<endl<<"Enter number to be inserted: ";
    cin>>x;
    cout<<endl<<"Enter number after which new number to be inserted: ";
    cin>>y;
    Insert_value_by_number(arr,x,y);



    return 0;
}
