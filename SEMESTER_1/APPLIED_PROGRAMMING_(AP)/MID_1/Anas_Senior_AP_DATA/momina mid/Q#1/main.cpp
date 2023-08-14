#include <iostream>

using namespace std;

void  delete_repeats(char a[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]==a[i]){
                for(int k=j;k<n;k++){
                    a[k]=a[k+1];
                }
                n--;
            }
        }
    }

    cout<<"new array is ";
    for(int i=0;i<n;i++){
    cout<<a[i];
    }
    cout<<endl<<"Size of array is "<<n;

}

int main()
{
    char a[10]={};
    int n=0;
    cout << "How many characters do you want to insert?  ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
delete_repeats(a,n);
    return 0;
}
