#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    // Open the file
    FILE* file = fopen("graph.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read the number of vertices
    Graph G;
    if (fscanf(file, "%d", &G.V) != 1) {
        printf("Error reading number of vertices\n");
        fclose(file);
        return 1;
    }

    // Initialize the edge lists
    G.edges = (EdgeList*)malloc(G.V * sizeof(EdgeList));
    if (!G.edges) {
        printf("Memory allocation failed for edge lists\n");
        fclose(file);
        return 1;
    }

    for (int v = 0; v < G.V; v++) {
        G.edges[v].head = NULL;
    }

    // Read and add edges (adjust for unweighted edges)
    int from, to;
    while (fscanf(file, "%d %d", &from, &to) == 2) {
        add_edge(&G, from - 1, to - 1, 0); // Subtract 1 to convert 1-based index to 0-based
    }

    // Close the file
    fclose(file);

    // Calculate in-degrees
    int* in_degrees = (int*)malloc(G.V * sizeof(int));
    if (!in_degrees) {
        printf("Memory allocation failed for in-degrees array\n");
        free(G.edges);
        return 1;
    }

    for (int i = 0; i < G.V; i++) {
        in_degrees[i] = 0;
    }

    calculate_in_degrees(&G, in_degrees);

    // Print in-degrees
    printf("In-degrees of vertices:\n");
    for (int i = 0; i < G.V; i++) {
        printf("Vertex %d: %d\n", i + 1, in_degrees[i]);
    }

    // Free dynamically allocated memory
    for (int v = 0; v < G.V; v++) {
        EdgeNodePtr current = G.edges[v].head;
        while (current != NULL) {
            EdgeNodePtr temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(G.edges);
    free(in_degrees);

    return 0;
}
