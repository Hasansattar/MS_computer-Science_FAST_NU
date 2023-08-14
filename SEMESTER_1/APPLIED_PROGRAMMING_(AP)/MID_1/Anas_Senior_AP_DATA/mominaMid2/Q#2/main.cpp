#include <iostream>

using namespace std;

int main()
{
    int age=0;
    float weight=0;
    cout << "Enter age: ";
    cin>>age;
    cout << "Enter weight: ";
    cin>>weight;

    cout<<endl;

    if(age<20)
            {
        cout<<"You are below the age to worry about weight";
            }
    else if(age>79)
            {
        cout<<"You are above the age. Just keep healthy diet and exercise";
            }

    else if(
            ((age>=20 && age<=39)&&(weight>198.8))||
            ((age>=40 && age<=59)&&(weight>201.7)) ||
            ((age>=60 && age<=79)&&(weight>199.7))
            )
            {
        cout<<"You are over weighted";
            }
    else if(
            ((age>=20 && age<=39)&&(weight<186.8))||
            ((age>=40 && age<=59)&&(weight<199.5)) ||
            ((age>=60 && age<=79)&&(weight<189.3))
            )
            {
        cout<<"You need to gain weight";
            }
    else{
        cout<<"You are not over weighted";
        }

    return 0;
}
