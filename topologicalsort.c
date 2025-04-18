// topologocal sort

#include <stdio.h>
#include <stdlib.h>

#define ver 6

// Function to perform DFS and store the topological sort
void dfs(int graph[ver][ver], int v, int visited[ver], int stack[ver], int *top) {
    visited[v] = 1;

    // Recur for all adjacent vertices
    for (int i = 0; i < ver; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(graph, i, visited, stack, top);
        }
    }

    // Push the current vertex to the stack after processing all its neighbors
    stack[(*top)++] = v;
}

// Function to perform topological sort
void topologicalSort(int graph[ver][ver]) {
    int visited[ver] = {0};  // Array to keep track of visited vertices
    int stack[ver];  // Array to store the topological sort
    int top = 0;

    // Perform DFS from all unvisited vertices
    for (int i = 0; i < ver; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited, stack, &top);
        }
    }

    // Print the topological sorting
    printf("Topological Sort: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    // Adjacency matrix for the graph (example)
    int graph[ver][ver] = {
        {0, 1, 1, 0, 0, 0},  // Vertex 0 -> 1, 2
        {0, 0, 0, 1, 0, 0},  // Vertex 1 -> 3
        {0, 0, 0, 1, 0, 0},  // Vertex 2 -> 3
        {0, 0, 0, 0, 1, 0},  // Vertex 3 -> 4
        {0, 0, 0, 0, 0, 1},  // Vertex 4 -> 5
        {0, 0, 0, 0, 0, 0}   // Vertex 5 (no outgoing edges)
    };

    // Perform the topological sort
    topologicalSort(graph);

    return 0;
}






