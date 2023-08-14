// C++ implementation to arrange
// odd and even numbers
#include <bits/stdc++.h>
using namespace std;

// function to arrange odd and even numbers
void arrangeOddAndEven(int arr[], int n)
{
int oddInd = 1;
	int evenInd = 0;
	while (true)
	{
		while (evenInd < n && arr[evenInd] % 2 == 0)
			evenInd += 2;
			
		while (oddInd < n && arr[oddInd] % 2 == 1)
			oddInd += 2;
			
		if (evenInd < n && oddInd < n)
			swap (arr[evenInd], arr[oddInd]);
			
		else
			break;
	}
}

// function to print the array
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// Driver program to test above
int main()
{
	int arr[] = { 3, 6, 12, 1, 5, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"n"<<n;

	cout << "Original Array: ";
	printArray(arr, n);

	arrangeOddAndEven(arr, n);

	cout << "\nModified Array: ";
	printArray(arr, n);

	return 0;
}
