#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph new_graph(int num_vertices) {
    Graph G;
    G.V = num_vertices;
    G.edges = (EdgeList*)malloc(num_vertices * sizeof(EdgeList));

    for (int i = 0; i < num_vertices; i++) {
        G.edges[i].head = NULL;
    }

    return G;
}

void add_edge(Graph* G, int from_vertex, int to_vertex, int weight) {
    EdgeNodePtr new_node = (EdgeNodePtr)malloc(sizeof(struct edgeNode));
    new_node->edge.to_vertex = to_vertex;
    new_node->edge.weight = weight;
    new_node->next = G->edges[from_vertex].head;
    G->edges[from_vertex].head = new_node;
}

void calculate_in_degrees(Graph G) {
    int* in_degrees = (int*)malloc(G.V * sizeof(int));
    if (in_degrees == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < G.V; i++) {
        in_degrees[i] = 0;
    }

    for (int i = 0; i < G.V; i++) {
        EdgeNodePtr current = G.edges[i].head;
        while (current != NULL) {
            in_degrees[current->edge.to_vertex]++;
            current = current->next;
        }
    }

    // Print in-degrees
    printf("In-degrees:\n");
    for (int i = 0; i < G.V; i++) {
        printf("Vertex %d: %d\n", i, in_degrees[i]);
    }

    // Free dynamically allocated memory
    free(in_degrees);
}


void free_graph(Graph* G) {
    for (int i = 0; i < G->V; i++) {
        EdgeNodePtr current = G->edges[i].head;
        while (current != NULL) {
            EdgeNodePtr temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(G->edges);
}
