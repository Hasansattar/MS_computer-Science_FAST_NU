#include <iostream>

using namespace std;

int main()
{
    float x=0;
    cout << "enter value of X: ";
    cin>>x;

    cout<<endl<<"\t\t("<<x<<")^2+"<<"("<<x<<")^3+"<<"("<<x<<"+3.14)";
    cout<<endl<<"F(x)=\t------------------------------------- =  "<<((x*x)+(x*x*x)+(x+3.14))/((x+3.14)*(x+3.14));
    cout<<endl<<"\t\t("<<x<<"+3.14)^2"<<endl;

    return 0;
}
