
#include <iostream>

using namespace std;

void arrangeWithInd(int arr[], int n)
{
    int oddInd      =   1;
    int evInd     =   0;

    while(true)
    {
        while(evInd < n && arr[evInd] % 2 == 0 )
            evInd += 2;

        while(oddInd < n && arr[oddInd] % 2 == 1 )
            oddInd += 2;

        if (evInd < n && oddInd < n )
            swap(arr[evInd], arr[oddInd] );

        else
            break;
    }
}


 void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

 int main()
{
    int arr[10] = {};

    cout << "Enter 10 values" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Input:";
    printArray(arr, n);

    arrangeWithInd(arr, n);
    

    cout << "\nOutput:";



    printArray(arr, n);
    return 0;
}
