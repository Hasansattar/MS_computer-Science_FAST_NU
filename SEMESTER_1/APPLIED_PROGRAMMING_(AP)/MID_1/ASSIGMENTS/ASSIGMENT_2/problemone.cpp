
#include <bits/stdc++.h>
using namespace std;

void arrangeEvenAndOdd(int arr[], int n)
{
    int oddIndex = 1;
    int evenIndex = 0;

    while (true)
    {
        while(evenIndex < n && arr[evenIndex] % 2 == 0)
            evenIndex += 2;

        while(oddIndex < n && arr[oddIndex] % 2 == 1)
            oddIndex += 2;

        if (evenIndex < n && oddIndex < n)
            swap(arr[evenIndex], arr[oddIndex]);

        else
            break;
    }
}


 void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

 int main()
{
    int arr[8] = {};

    cout << "Enter 8 values" << endl;
    for (int i = 0; i < 8; i++)
    {
        cin >> arr[i];
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Input Array :";
    displayArray(arr, n);

    arrangeEvenAndOdd(arr, n);

    cout << "\nOutput Array :";
    displayArray(arr, n);

    return 0;
}
