#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void add_edge(Graph* self, int from, int to, int w) {
    EdgeNodePtr newNode = (EdgeNodePtr)malloc(sizeof(struct edgeNode));
    if (!newNode) {
        printf("Memory allocation failed for new edge node\n");
        exit(EXIT_FAILURE);
    }
    newNode->edge.to_vertex = to;
    newNode->edge.weight = w;
    newNode->next = self->edges[from].head;
    self->edges[from].head = newNode;
}

void calculate_in_degrees(Graph* self, int* in_degrees) {
    for (int i = 0; i < self->V; i++) {
        EdgeNodePtr current = self->edges[i].head;
        while (current != NULL) {
            in_degrees[current->edge.to_vertex]++;
            current = current->next;
        }
    }
}
