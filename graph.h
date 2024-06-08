#ifndef GRAPH_H
#define GRAPH_H

typedef struct edge {
    int to_vertex;
    int weight;
} Edge;

typedef struct edgeNode {
    Edge edge;
    struct edgeNode *next;
} *EdgeNodePtr;

typedef struct edgeList {
    EdgeNodePtr head;
} EdgeList;

typedef struct graph {
    int V;
    EdgeList *edges;
} Graph;

void add_edge(Graph* self, int from, int to, int w);
void calculate_in_degrees(Graph* self, int* in_degrees);

#endif // GRAPH_H
