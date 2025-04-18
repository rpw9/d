#include <stdio.h>
#define V 4 // Number of vertices in the graph

// Function to print the solution
void printSolution(int color[])
{
    printf("Solution  :\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    printf("\n");
}

// Function to check if the current color assignment is safe for vertex v
int isSafe(int v, int graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && c == color[i])
            return 0; // Not safe
    }
    return 1; // Safe
}

// Recursive utility function to solve m coloring problem
int graphColoringUtil(int graph[V][V], int m, int color[], int v)
{
    // If all vertices are assigned a color then return true
    if (v == V)
        return 1;

    // Consider this vertex v and try different colors
    for (int c = 1; c <= m; c++) {
        // Check if assignment of color c to v is fine
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1))
                return 1;

            color[v] = 0;
        }
    }

    return 0;  
}

// Function to solve the m coloring problem using Backtracking.
int graphColoring(int graph[V][V], int m) 
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (graphColoringUtil(graph, m, color, 0) == 0)
    {
        printf("Solution does not exist\n");
        return 0;
    }

    printSolution(color);
    return 1;
}

int main()
{
    // Adjacency matrix representation of the graph
    int graph[V][V] =
    {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors
    graphColoring(graph, m);

    return 0;
}
