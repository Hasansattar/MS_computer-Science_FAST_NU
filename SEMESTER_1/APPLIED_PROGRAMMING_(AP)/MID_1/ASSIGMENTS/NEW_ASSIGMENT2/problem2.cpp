
#include <bits/stdc++.h>
using namespace std;

void Divisors(int arr[], int n)
{
    int i;
    int j = 0;

    for (j = 0; j < arr[j]; j++)
    {

        cout << "\nAll the divisor of  are: " << arr[j] << "\n";

        for (i = 1; i <= arr[i]; i++)
        {

            if ((arr[j] % i) == 0)
            {
                cout << i << " ";
                cout << "\n";
            }
        }
    }
}

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[3] = {};

    cout << "Enter 3 values" << endl;
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Diviser Array are..:";
    displayArray(arr, n);

    Divisors(arr, n);

    return 0;
}
