#include <iostream>

using namespace std;

std::string lookupName(std::string targetName,std::string names[],std::string numbers[],int n){
    for(int i=0;i<n;i++){
        if(targetName==names[i]){
            return numbers[i];
        }
    }
        return "";

}

int main()
{
    string names[]={"Momina","Ali","Ratul","Farah","Alina"};
    string numbers[]={"03336547856","03215468759","03005468795","03115468777","03456895446"};
    string targetName,targetPhone;
    char c;
    do{
                cout << "Enter a name to find corresponding phone number: " << endl;
                getline(cin,targetName);
                targetPhone=lookupName(targetName,names,numbers,4);
                if(targetPhone.length()>0){
                    cout<<"Phone number is: "<<targetPhone<<endl;
                }
                else{
                    cout<<"Name not found: "<<endl;
                }
                    cout<<"Lookup another name? (y/n): ";
                 cin>>c;
                 cin.ignore();
    }while(c=='y');
    return 0;
}
