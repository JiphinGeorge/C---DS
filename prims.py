#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 9999999

int main() {
    int G[MAX][MAX], visited[MAX], n;
    int i, j, no_edges = 0;
    int min, a, b;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 if there is no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
            if (G[i][j] == 0)
                G[i][j] = INF;  // No edge
        }
        visited[i] = 0;
    }

    visited[0] = 1;  // Start from vertex 0

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (no_edges < n - 1) {
        min = INF;
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && G[i][j] < min) {
                        min = G[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", a, b, G[a][b]);
        visited[b] = 1;
        no_edges++;
    }

    return 0;
}
