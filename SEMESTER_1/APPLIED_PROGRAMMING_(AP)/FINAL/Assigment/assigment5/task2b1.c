
#include <stdio.h>

// V vertices and E Edges
int V, E;

void createAdjMatrix(int Adj[][V + 1],
                     int arr[][2])
{

    for (int i = 0; i < V + 1; i++)
    {

        for (int j = 0; j < V + 1; j++)
        {
            Adj[i][j] = 0;
        }
    }

    for (int i = 0; i < E; i++)
    {

        int x = arr[i][0];
        int y = arr[i][1];

        // Update value to 1
        Adj[x][y] = 1;
        Adj[y][x] = 1;
    }
}

void printAdjMatrix(int Adj[][V + 1])
{


    for (int i =  1 ;  i  <   V + 1 ;  i++)
    {
        for (int j  =  1 ;  j <  V + 1 ;  j++)
        {

            printf ( " %d  ",  Adj[i][j]);
        }
        printf ( "\n" ) ; 
    }
}

int main()
{

    V = 8;

    int arr[][2] = {{1, 2}, {2, 3}, {4, 5}, {1, 5}, {6, 1}, {7, 4}, {3, 8}};

    E = sizeof(arr) / sizeof(arr[0]);

    int Adj[V + 1][V + 1];

    createAdjMatrix(Adj, arr);

    printAdjMatrix(Adj);

    return 0;
}