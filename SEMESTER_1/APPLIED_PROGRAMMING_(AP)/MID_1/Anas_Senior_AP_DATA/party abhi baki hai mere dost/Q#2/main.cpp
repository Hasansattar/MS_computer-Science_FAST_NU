#include <iostream>
#include <fstream>

using namespace std;

int totalExpense(int size,int ids[],int expenses[]){
        int id;
        int total=0;
        cout<<"Enter id: ";
        cin>>id;
        for(int i=0;i<size;i++){
            if(id==ids[i]){
                total=total+expenses[i];
            }
        }
        return total;
}

int main()
{
    int sizeOfWords=0;
    int expense[10];
    int patientIds[10];

    int i;
    ifstream readExpenseAndId("expense.txt");

    i=0;
    while(!readExpenseAndId.eof()){
        readExpenseAndId>>patientIds[i];
        readExpenseAndId>>expense[i];
    i++;
    }
sizeOfWords=i;

cout<<"total expenses are "<<totalExpense(sizeOfWords,patientIds,expense);
    return 0;
}
