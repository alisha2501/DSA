#include <stdio.h>
#include <limits.h>

#define INF 99999

// Function to print the solution
void printSolution(int dist[][100], int n, int pi[][100]) {
    printf("Distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    printf("\nPredecessor matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pi[i][j] == -1)
                printf("NIL ");
            else
                printf("%d ", pi[i][j]);
        }
        printf("\n");
    }
}

// Function to implement the Floyd-Warshall algorithm
void floydWarshall(int graph[][100], int n) {
    int dist[100][100], pi[100][100];

    // Initialize the distance and predecessor matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
                pi[i][j] = -1;
            } else if (graph[i][j] != 0) {
                dist[i][j] = graph[i][j];
                pi[i][j] = i;
            } else {
                dist[i][j] = INF;
                pi[i][j] = -1;
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pi[i][j] = pi[k][j];
                }
            }
        }
    }

    printSolution(dist, n, pi);
}

// Main function
int main() {
    int n;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    int graph[100][100];
    printf("Enter the adjacency matrix (use 0 for no edge and 99999 for no direct path):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }

    // Running the Floyd-Warshall algorithm
    floydWarshall(graph, n);

    return 0;
}

