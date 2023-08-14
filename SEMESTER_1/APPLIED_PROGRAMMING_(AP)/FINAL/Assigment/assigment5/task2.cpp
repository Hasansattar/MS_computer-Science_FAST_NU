(a)

// C program for the above approach
#include <stdio.h>
  
// N vertices and M Edges
int N, M;
  
// Function to create Adjacency Matrix
void createAdjMatrix(int Adj[][N + 1],
                     int arr[][2])
{
  
    // Initialise all value to this
    // Adjacency list to zero
    for (int i = 0; i < N + 1; i++) {
  
        for (int j = 0; j < N + 1; j++) {
            Adj[i][j] = 0;
        }
    }
  
    // Traverse the array of Edges
    for (int i = 0; i < M; i++) {
  
        // Find X and Y of Edges
        int x = arr[i][0];
        int y = arr[i][1];
  
        // Update value to 1
        Adj[x][y] = 1;
        Adj[y][x] = 1;
    }
}
  
// Function to print the created
// Adjacency Matrix
void printAdjMatrix(int Adj[][N + 1])
{
  
    // Traverse the Adj[][]
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
  
            // Print the value at Adj[i][j]
            printf("%d ", Adj[i][j]);
        }
        printf("n");
    }
}
  
// Driver Code
int main()
{
  
    // Number of vertices
    N = 8;
  
    // Given Edges
    int arr[][2]
        = { { 1, 2 }, { 2, 3 }, 
            { 4, 5 }, { 1, 5 },
            { 6, 1 }, { 7, 4 },
            { 3, 8 }, };
  
    // Number of Edges
    M = sizeof(arr) / sizeof(arr[0]);
  
    // For Adjacency Matrix
    int Adj[N + 1][N + 1];
  
    // Function call to create
    // Adjacency Matrix
    createAdjMatrix(Adj, arr);
  
    // Print Adjacency Matrix
    printAdjMatrix(Adj);
  
    return 0;
}

 

(b)

//Adjascency List representation in C

#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};
struct node* createNode(int);

struct Graph {
  int numVertices;
  struct node** adjLists;
};

// Create a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Create a graph
struct Graph* createAGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  int i;
  for (i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int s, int d) {
  // Add edge from s to d
  struct node* newNode = createNode(d);
  newNode->next = graph->adjLists[s];
  graph->adjLists[s] = newNode;

  // Add edge from d to s
  newNode = createNode(s);
  newNode->next = graph->adjLists[d];
  graph->adjLists[d] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("n Vertex %dn: ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("n");
  }
}

int main() {
  struct Graph* graph = createAGraph(8);
  addEdge(graph, 0, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 4, 5);
addEdge(graph, 1, 5);
addEdge(graph, 6, 1);
addEdge(graph, 7, 4);
addEdge(graph, 3, 8);

  printGraph(graph);

  return 0;
}