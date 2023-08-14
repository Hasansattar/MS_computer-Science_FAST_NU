#include <iostream>

using namespace std;
float numOfLitersPerGallon=0.264179;


    void computeNumberOfMilesPerGallons(int numOfLiterConsumed,int numOfMilesTraveled){
    cout<<"Number of miles per gallon are: "<<numOfMilesTraveled/(numOfLiterConsumed*numOfLitersPerGallon)<<endl;
    }

int main()
{
    float numOfLiterConsumed=0;
    float numOfMilesTraveled=0;
    int choice=1;
    while(choice==1){
    cout << "Enter the number of liters of gasoline consumed: ";
    cin>>numOfLiterConsumed;
        cout << "Enter the number of miles traveled by the car: ";
    cin>>numOfMilesTraveled;
    computeNumberOfMilesPerGallons(numOfLiterConsumed,numOfMilesTraveled);


        cout << "Enter 1 to continue or any other number to exit: ";
    cin>>choice;
    }
    return 0;
}
