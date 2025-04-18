#include <stdio.h>
#include <limits.h>

#define V 2  // Number of verticesp
// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Dijkstra's algorithm to find the shortest path from the source vertex
void dijkstra(int graph[V][V], int src) {
    int dist[V];  // Array to store the shortest distance to each vertex
    int sptSet[V];  // Array to keep track of vertices included in the shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;  // Distance of source vertex from itself is always 0

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);  // Get the vertex with the minimum distance
        sptSet[u] = 1;  // Mark the selected vertex as processed

        // Update the distance value of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distance to each vertex
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d\t\tUnreachable\n", i);
        } else {
            printf("%d\t\t%d\n", i, dist[i]);
        }
    }
}

int main() {
    // Example graph (adjacency matrix)
    int graph[V][V],i,j;
    /*int graph[V][V] = {
        {0, 10, 0, 0, 0},
        {10, 0, 5, 0, 0},
        {0, 5, 0, 15, 20},
        {0, 0, 15, 0, 10},
        {0, 0, 20, 10, 0}
    };*/
    printf("\n Enter matrix elements \n");
    for(i=0;i<V;i++)
    for(j=0;j<V;j++)
    scanf("%d",&graph[i][j]);

    int source = 0;  // Source vertex (0th vertex)
    dijkstra(graph, source);

    return 0;
}





