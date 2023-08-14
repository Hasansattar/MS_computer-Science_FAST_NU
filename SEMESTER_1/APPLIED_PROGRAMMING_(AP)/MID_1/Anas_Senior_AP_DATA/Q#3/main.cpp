#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
        string temp2="";
    int noOfLines=0;
    int noOfVowels=0;
    int noOfWords=0;
    int noOfSmallLetters=0;
    int noOfCapitalLetters=0;
    int noOfPalindrome=0;
    string paragraph="";


    ifstream obj ("File.txt");
	if (!obj)
	{
		cout << "File could not open\n";
	}

    cout<<"1 - number of capital letters"<<endl;
    cout<<"2 - number of small letters"<<endl;
    cout<<"3 - number of number of lines"<<endl;
    cout<<"4 - number of number of vowels"<<endl;
    cout<<"5 - number of number of words"<<endl;
    cout<<"6 - reverse"<<endl;
    cout<<"7 - pallindrome"<<endl;
    char choice;
    cin>>choice;
    switch(choice){
    case '1':
                while (!obj.eof())
		{
			getline(obj,temp2);
			for(int i=0;i<temp2.length();i++){
                if((!islower(temp2[i]))&&(temp2[i]!=' ')){
                noOfCapitalLetters++;
                }
			}
		}
    cout <<"total number of Capital Letters is "<<noOfCapitalLetters<< endl;
        break;
    case '2':
        while (!obj.eof())
		{
			getline(obj,temp2);
			for(int i=0;i<temp2.length();i++){
                if((islower(temp2[i]))&&(temp2[i]!=' ')){
                noOfSmallLetters++;
                }
			}
		}
    cout <<"total number of Small Letters is "<<noOfSmallLetters<< endl;
        break;
    case '3':
        	while (!obj.eof())
		{
			getline(obj,temp2);
			noOfLines++;
		}
    cout <<"total number of lines is "<<noOfLines<< endl;
        break;
    case '4':
        while (!obj.eof())
		{
			getline(obj,temp2);
			for(int i=0;i<temp2.length();i++){
                if((temp2[i]=='a')||(temp2[i]=='e')||(temp2[i]=='i')||(temp2[i]=='o')||(temp2[i]=='u')){
                noOfVowels++;
                }
			}
		}
    cout <<"total number of vowels is "<<noOfVowels<< endl;
        break;
    case '5':
        while (!obj.eof())
		{
			getline(obj,temp2);
			for(int i=0;i<temp2.length();i++){
                if(temp2[i]==' '){
                noOfWords++;
                }
			}
			noOfWords++;
		}
		    cout <<"total number of words is "<<noOfWords<< endl;
        break;
    case '6':
         while (!obj.eof())
		{
			getline(obj,temp2);
			paragraph=paragraph+temp2;
        }
		   for(int i=paragraph.length()-1;i>=0;i--){
                cout<<paragraph[i];
			}
        break;
    case '7':
        while (!obj.eof())
		{

			getline(obj,temp2);
		    int flag=0;
			for(int i=0;i<temp2.length();i++){
                if(temp2[i]==' '){
                			if(temp2[i]!=temp2[temp2.length()-1-i]){
                            flag=1;
                            break;
                			}
                }
			}
			if(flag!=1){
                noOfPalindrome++;
			}
		}
		    cout <<"total number of palindrome words is "<<noOfPalindrome<< endl;

        break;


    }
	obj.close();
    return 0;
}
