
#include <iostream>
using namespace std;

void diviser(int arr[], int n)
{
    int i;
    int w = 0;
    for (w = 0; w < arr[w]; w++)
    {

 cout << "\nAll the divisor: " << arr[w] << "\n";
        for (i = 1; i <= arr[i]; i++)
        {
            if ((arr[w] % i) == 0)
            {
                cout <<i<< " ";
                cout << "\n";
            }
        }
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[3] = {};
    cout <<"Put 3 values" << endl;
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Diviser Array:";
    print(arr, n);

    diviser(arr, n);

    return 0;
}
