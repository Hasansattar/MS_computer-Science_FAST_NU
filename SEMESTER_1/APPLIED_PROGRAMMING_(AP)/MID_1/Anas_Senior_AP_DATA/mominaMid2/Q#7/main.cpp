#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
        string temp2="";
    int noOfWords=0;
    int noOfSentences=0;

    ifstream obj ("File.txt");
	if (!obj)
	{
		cout << "File could not open\n";
	}

    cout<<"1 - number of number of words"<<endl;
    cout<<"2 - number of number of Sentences"<<endl;
    char choice;
    cin>>choice;
    switch(choice){
    case '1':
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
		    cout <<"total number of words are "<<noOfWords<< endl;
        break;

        case '2':
        while (!obj.eof())
		{
			getline(obj,temp2);
			for(int i=0;i<temp2.length();i++){
                if(temp2[i]=='.'){
                noOfSentences++;
                }
			}
		}
		    cout <<"total number of sentences are "<<noOfSentences<< endl;

        break;


    }
	obj.close();
    return 0;
}
