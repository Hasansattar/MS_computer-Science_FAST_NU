#include <iostream>

using namespace std;

int main()
{
    string name="";
    cout << "Enter name without spaces: " << endl;
    cin>>name;
    bool error=false;
    int num=0;
    for(int i=0;i<name.length();i++)
        {
        if(
            (name[i]==' ')||(name[i]=='.')||(name[i]==',')||
            (name[i]=='0')||
            (name[i]=='1')||
            (name[i]=='2')||
            (name[i]=='3')||
            (name[i]=='4')||
            (name[i]=='5')||
            (name[i]=='6')||
            (name[i]=='7')||
            (name[i]=='8')||
            (name[i]=='9'))
            {
            error=true;
            }
        }

    if(error==true){
        cout<<endl<<"Invalid name"<<endl;
    }
    else{

        cout<<"=";
        for(int i=0;i<name.length();i++)
        {
        if((name[i]=='A')||(name[i]=='a'))
            {
            num=num+1;
            cout<<"1";
            }
        else if((name[i]=='B')||(name[i]=='b'))
            {
            num=num+2;
            cout<<"2";
            }
        else if((name[i]=='C')||(name[i]=='c'))
            {
            num=num+3;
            cout<<"3";
            }
        else if((name[i]=='D')||(name[i]=='d'))
            {
            num=num+4;
            cout<<"4";
            }
        else if((name[i]=='E')||(name[i]=='e'))
            {
            num=num+5;
            cout<<"5";
            }
        else if((name[i]=='F')||(name[i]=='f'))
            {
            num=num+6;
            cout<<"6";
            }
        else if((name[i]=='G')||(name[i]=='g'))
            {
            num=num+7;
            cout<<"7";
            }
        else if((name[i]=='H')||(name[i]=='h'))
            {
            num=num+8;
            cout<<"8";
            }
        else if((name[i]=='I')||(name[i]=='i'))
            {
            num=num+9;
            cout<<"9";
            }
        else if((name[i]=='J')||(name[i]=='j'))
            {
            num=num+10;
            cout<<"10";
            }
        else if((name[i]=='K')||(name[i]=='k'))
            {
            num=num+11;
            cout<<"11";
            }
        else if((name[i]=='L')||(name[i]=='l'))
            {
            num=num+12;
            cout<<"12";
            }
        else if((name[i]=='M')||(name[i]=='m'))
            {
            num=num+13;
            cout<<"13";
            }
        else if((name[i]=='N')||(name[i]=='n'))
            {
            num=num+14;
            cout<<"14";
            }
        else if((name[i]=='O')||(name[i]=='o'))
            {
            num=num+15;
            cout<<"15";
            }
        else if((name[i]=='P')||(name[i]=='p'))
            {
            num=num+16;
            cout<<"16";
            }
        else if((name[i]=='Q')||(name[i]=='q'))
            {
            num=num+17;
            cout<<"17";
            }
        else if((name[i]=='R')||(name[i]=='r'))
            {
            num=num+18;
            cout<<"18";
            }
        else if((name[i]=='S')||(name[i]=='s'))
            {
            num=num+19;
            cout<<"19";
            }
        else if((name[i]=='T')||(name[i]=='t'))
            {
            num=num+20;
            cout<<"20";
            }
        else if((name[i]=='U')||(name[i]=='u'))
            {
            num=num+21;
            cout<<"21";
            }
        else if((name[i]=='V')||(name[i]=='v'))
            {
            num=num+22;
            cout<<"22";
            }
        else if((name[i]=='W')||(name[i]=='w'))
            {
            num=num+23;
            cout<<"23";
            }
        else if((name[i]=='X')||(name[i]=='x'))
            {
            num=num+24;
            cout<<"24";
            }
        else if((name[i]=='Y')||(name[i]=='y'))
            {
            num=num+25;
            cout<<"25";
            }
        else if((name[i]=='Z')||(name[i]=='z'))
            {
            num=num+26;
            cout<<"26";
            }
        cout<<"+";
        }
    }

while(num>9){
        cout<<endl<<"="<<num/10<<"+"<<num%10<<"+";
        num=(num/10)+(num%10);

}
         cout<<endl<<"="<< num;
    return 0;
}
