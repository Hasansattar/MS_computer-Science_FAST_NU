#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    string temp2="";
    int max=0;
    int prime=0;
    ifstream obj ("File.txt");
	if (!obj)
	{
		cout << "File could not open\n";
	}
	else{
		while (!obj.eof())
		{
			getline(obj,temp2);
			    stringstream ss(temp2);
			    int temp;
			    ss>>temp;
			    int counter=0;
			for(int i=1;i<=temp;i++){
                if((temp%i==0)){
                counter++;
                }
			}
			if(counter==2){
                prime=temp;
                    if(prime>max){
                        max=prime;
                    }
			}
		}
	}
	obj.close();
    cout <<"maximum prime number is "<<max<< endl;

    return 0;
}
