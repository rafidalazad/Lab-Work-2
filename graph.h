#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#ifndef GRAPH_H
#define GRAPH_H

typedef struct edge {
    int to_vertex;
    int weight;
} Edge;

typedef struct edgeNode {
    Edge edge;
    struct edgeNode* next;
} *EdgeNodePtr;

typedef struct edgeList {
    EdgeNodePtr head;
} EdgeList;

typedef struct graph {
    int V;
    EdgeList* edges;
} Graph;

Graph new_graph(int num_vertices);
void add_edge(Graph* G, int from_vertex, int to_vertex, int weight);
void calculate_in_degrees(Graph G);
void free_graph(Graph* G);

#endif
#pragma once
