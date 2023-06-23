#include <stdio.h>
#include <string.h>

int main() {
    int count, src_router, i, j, k, w, v, min;
    int cost_matrix[100][100], dist[100], last[100];
    int flag[100];

    printf("\nEnter the number of routers: ");
    scanf("%d", &count);

    printf("\nEnter the cost matrix values:\n");
    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            printf("%d -> %d: ", i, j);
            scanf("%d", &cost_matrix[i][j]);
            if (cost_matrix[i][j] < 0)
                cost_matrix[i][j] = 1000;  // Assign a high cost for negative values
        }
    }

    printf("\nEnter the source router: ");
    scanf("%d", &src_router);

    // Initialize arrays
    for (v = 0; v < count; v++) {
        flag[v] = 0;  // Flag to track if a router is included in the shortest path set
        last[v] = src_router;  // Array to store the last hop router on the shortest path
        dist[v] = cost_matrix[src_router][v];  // Array to store the cost of reaching each router from the source
    }
    flag[src_router] = 1;  // Mark the source router as visited

    // Dijkstra's algorithm
    for (i = 0; i < count; i++) {
        min = 1000;
        for (w = 0; w < count; w++) {
            if (!flag[w])
                if (dist[w] < min) {
                    v = w;
                    min = dist[w];
                }
        }
        flag[v] = 1;  // Mark the router with the shortest path as visited
        for (w = 0; w < count; w++) {
            if (!flag[w])
                if (min + cost_matrix[v][w] < dist[w]) {
                    dist[w] = min + cost_matrix[v][w];  // Update the cost to reach other routers via the current router
                    last[w] = v;  // Update the last hop router on the shortest path
                }
        }
    }

    // Print shortest paths and costs
    for (i = 0; i < count; i++) {
        printf("\n%d ==> %d\nPath taken: %d", src_router, i, i);
        w = i;
        while (w != src_router) {
            printf(" <-- %d", last[w]);  // Print the routers on the shortest path
            w = last[w];
        }
        printf("\nShortest path cost: %d\n\n", dist[i]);  // Print the cost of the shortest path to each router
    }

    return 0;
}

