#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
        string temp2="";
    int num[20]={0};
    int i=0;
    ifstream obj ("File.txt");
	if (!obj)
	{
		cout << "File could not open\n";
	}
    while (!obj.eof())
    {
			obj>>temp2;
			stringstream ss(temp2);
			ss>>num[i];
			i++;
    }
cout<<"old array"<<endl;
for(i=0;i<15;i++){
    cout<<num[i]<<endl;
}

for(i=0;i<15;i++){
    for(int j=0;j<15;j++){
        if(num[i]<num[j]){
            int temp=num[j];
            num[j]=num[i];
            num[i]=temp;
        }
    j++;
    }
i++;
}

for(i=1;i<15;i++){
    for(int j=1;j<15;j++){
        if(num[i]>num[j]){
            int temp=num[j];
            num[j]=num[i];
            num[i]=temp;
        }
    j++;
    }
i++;
}

cout<<"new array"<<endl;
for(i=0;i<15;i++){
    cout<<num[i]<<endl;
}

    ofstream obj2 ("newFile.txt");
	if (!obj2)
	{
		cout << "File could not open\n";
	}
	else{
        for(i=0;i<15;i++){
    obj2<<num[i]<<endl;
        }
	}



	obj.close();
    return 0;
}
