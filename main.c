#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file.\n");
        return 1;
    }

    int num_vertices;
    fscanf(input_file, "%d", &num_vertices);

    // Create a new graph
    Graph G = new_graph(num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        int num_edges;
        fscanf(input_file, "%d", &num_edges);

        for (int j = 0; j < num_edges; j++) {
            int to_vertex, weight;
            fscanf(input_file, "%d,%d", &to_vertex, &weight);
            add_edge(&G, i, to_vertex, weight);
        }
    }

    // Calculate and print in-degrees
    calculate_in_degrees(G);

    // Free dynamically allocated memory
    free_graph(&G);

    fclose(input_file);
    return 0;
}
