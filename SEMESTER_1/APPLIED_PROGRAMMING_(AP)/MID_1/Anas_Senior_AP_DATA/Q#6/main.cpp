#include <iostream>
using namespace std;
int main()
{
    int arr[10]={0};
    int rotateNum;
    cout << "Enter 10 values"<< endl;
    for(int i=0;i<10;i++){
    cin>>arr[i];
    }
    cout<<"Enter rotate value:" << endl;
    cin>>rotateNum;

    for(int i=rotateNum;i<10;i++){
    cout<<arr[i];
    }
    for(int i=0;i<rotateNum;i++){
    cout<<arr[i];
    }

    return 0;
}
