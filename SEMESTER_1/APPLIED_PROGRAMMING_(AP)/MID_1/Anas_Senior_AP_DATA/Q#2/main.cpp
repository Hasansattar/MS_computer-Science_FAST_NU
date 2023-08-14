#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    string temp2="";
    int oddNumbers=0;
    int evenNumbers=0;
    int primeNumbers=0;

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
                primeNumbers++;
			}


			//even check
			if(temp%2==0){
                evenNumbers++;
			}
			else{
                oddNumbers++;
			}
		}
	}
	obj.close();



ofstream inputobj ("FileMax.txt");
	if (!inputobj)
	{
		cout << "File could not open\n";
	}
	else{

    inputobj<<"total prime numbers: "<<primeNumbers<<endl<<"total even numbers: "<<evenNumbers<<endl<<"total odd numbers: "<<oddNumbers;
	}
	obj.close();


    return 0;
}
