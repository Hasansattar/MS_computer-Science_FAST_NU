#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string date1="",date2="";
    cout << "Enter first date(DD/MM/YY): ";
    cin>>date1;
    cout << "Enter second date(DD/MM/YY): ";
    cin>>date2;


    stringstream d1(date1);
    stringstream d2(date2);
    int days1,days2;
    d1>>days1;
    d2>>days2;

    cout<<"The days are "<<days1-days2<<" days apart(Since the end date is excluded)";
    return 0;
}
