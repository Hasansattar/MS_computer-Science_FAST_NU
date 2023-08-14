#include <iostream>

using namespace std;

    void calculateHat(float weight,float height){
    cout<<endl<<"hat size is: "<<((weight/height)*2.9);
    }
    void calculateJacket(float weight,float height,int age){
        float size;
        if (age>=30)
        {
        if((age % 10) !=0)
        age = age-(age%10);
        int temp= (age-30)/10;
        size =((height * weight) / 288)+((1.0/8)*temp);
        }
        else
        size =((height*weight)/288);
    cout<<endl<<"Jacket size is: "<<size;
    }


    float calculateWaist(float weight, int age)
    {
        float waist = weight / 5.7;
        if (age > 28) {
            waist += (age - 28) / 2 * 0.1;
        }
        cout<<endl<<"waist is "<<waist;
    }
int main()
{
    float height,weight;
    int age=0;
    char choice='y';
    while(choice=='y'){
    cout << "Enter height in inches: ";
    cin>>height;
    cout <<endl<< "Enter weight in pounds: ";
    cin>>weight;
    cout <<endl<< "Enter age: ";
    cin>>age;
    calculateHat(weight,height);
    calculateJacket(weight,height,age);
    calculateWaist(weight,age);



    cout<<endl<<"do you want to continue? (y/n): ";
    cin>>choice;
    }
    return 0;
}
