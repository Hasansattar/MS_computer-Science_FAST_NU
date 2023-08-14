#include <iostream>
using namespace std;

//  power();
int power(int X, int Y)
{
    if( Y == 1 )
        return X;
    return X * power(X, Y-1);
}

//  factorial();
int factorial(int X)
{
    if( X == 0 || X == 1 )
        return 1;
    return X * factorial(X-1);
}

double sum_of_series(int X, int N)
{
    if( N < 2 )
        return 1.0;
    
    if( N % 4 == 0 )
        return sum_of_series(X, N-2) + (power(X, N)/(double)factorial(N));
    else 
        return sum_of_series(X, N-2) - (power(X, N)/(double)factorial(N));
}

int main()
{
    cout << sum_of_series(1, 2) << endl;
    cout << sum_of_series(1, 4) << endl;
    cout << sum_of_series(1, 6) << endl;
    
    cout << sum_of_series(2, 2) << endl;
    cout << sum_of_series(2, 4) << endl;
    cout << sum_of_series(2, 6) << endl;
    /*
    //  Factorial using loop/iteration
    int x = 5;
    int result = 1;
    while( x != 0 )
    {
        result = result * x;
        cout << "Iteration " << x << endl;
        x--;
    }
    
    cout << result << endl;
    */
    
    return 0;
}
