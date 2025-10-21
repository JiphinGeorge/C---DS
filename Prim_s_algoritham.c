#include <stdio.h>  // Include standard input/output library
#include <limits.h> // Include header file for INT_MAX constant (used for infinity representation)

#define MAX 100 // Define maximum number of vertices that can be used in the graph

// Function to find the vertex with the minimum key value not yet included in MST
int minKey(int key[], int mstSet[], int n)
{
    int min = INT_MAX; // Initialize minimum value as infinity
    int min_index;     // Variable to store index of vertex with minimum key value

    // Loop through all vertices to find the one with the smallest key not yet in MST
    for (int v = 0; v < n; v++)
        // Check if vertex 'v' is not included in MST and has a smaller key value
        if (mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];  // Update minimum value
            min_index = v; // Store index of vertex with minimum key
        }

    return min_index; // Return the index of vertex with smallest key value
}

// Function to print the constructed MST and its total cost
void printMST(int parent[], int graph[MAX][MAX], int n)
{
    int totalCost = 0; // Variable to store total cost of the MST

    printf("\nEdges in the Minimum Cost Spanning Tree:\n");
    printf("Edge\tWeight\n");

    // Loop from 1 because the first vertex (index 0) is the root and has no parent
    for (int i = 1; i < n; i++)
    {
        // Print the edge between parent[i] and i with its weight
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
        // Add the weight of this edge to total cost
        totalCost += graph[i][parent[i]];
    }

    // Print the total cost of the MST
    printf("\nMinimum Cost of Spanning Tree = %d\n", totalCost);
}

// Function to construct MST using Prim’s Algorithm
void primMST(int graph[MAX][MAX], int n)
{
    int parent[MAX]; // Array to store the MST (parent[i] gives the parent of vertex i)
    int key[MAX];    // Array to store the minimum weight edge connecting each vertex
    int mstSet[MAX]; // Array to keep track of vertices included in MST (1 = included, 0 = not included)

    // Step 1: Initialize all keys as infinite and mark all vertices as not included in MST
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX; // Set all key values to infinity
        mstSet[i] = 0;    // Set all vertices as not included in MST
    }

    // Step 2: Start with the first vertex (index 0)
    key[0] = 0;     // Cost to include the first vertex is 0
    parent[0] = -1; // First vertex has no parent (it's the root of MST)

    // Step 3: Construct MST with (n - 1) edges
    for (int count = 0; count < n - 1; count++)
    {
        // Pick the vertex with the smallest key that is not yet in MST
        int u = minKey(key, mstSet, n);

        // Mark this vertex as included in MST
        mstSet[u] = 1;

        // Step 4: Update key values and parent index for adjacent vertices
        for (int v = 0; v < n; v++)
            // Update key[v] only if:
            // (1) graph[u][v] is non-zero (there is an edge)
            // (2) vertex v is not yet in MST
            // (3) edge weight (u,v) is smaller than current key[v]
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;        // Set parent of v to u
                key[v] = graph[u][v]; // Update key value with the new smaller edge weight
            }
    }

    // Step 5: Print the resulting MST
    printMST(parent, graph, n);
}

int main()
{
    int n;               // Variable to store number of vertices
    int graph[MAX][MAX]; // 2D array to store adjacency matrix of the graph

    // Input: number of vertices in the graph
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input: adjacency matrix of the graph
    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++)        // Loop through rows
        for (int j = 0; j < n; j++)    // Loop through columns
            scanf("%d", &graph[i][j]); // Read edge weight

    // Call Prim’s algorithm function to find and print the MST
    primMST(graph, n);

    return 0; // End of program
}
