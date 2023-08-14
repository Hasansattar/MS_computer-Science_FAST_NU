#include <iostream>
#include<fstream>

using namespace std;


  void printNameOfStudentWithHighestMarks(std::string names[],int marks[],int n){
  int max=marks[0];
  int maxIndex=0;
  for(int i=0;i<n;i++){
    if(marks[i]>max){
        max=marks[i];
        maxIndex=i;
    }
  }
  cout<<endl<<names[maxIndex]<<" got the highest marks "<<max;
  }

int main()
{
    string names[10]={};
    int marks[10]={};
    int n;
    cout << "how many students do you want to add? ";
    cin>>n;
    cout<<endl << "Enter names of students: ";
    for(int i=0;i<n;i++){
        cin>>names[i];
    }
    cout<<endl << "Enter marks of students: ";
    for(int i=0;i<n;i++){
        cin>>marks[i];
    }
    printNameOfStudentWithHighestMarks(names,marks,n);
    return 0;
}
