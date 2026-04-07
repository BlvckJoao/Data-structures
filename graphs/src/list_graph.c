#include <stdio.h>
#include <stdlib.h>
#include "include/list_graph.h"
#include "../stacks_queues/include/stack.h"
#include "../stacks_queues/include/queue.h"

Graph* graph_create(int num_vertices) {
        Graph* g = (Graph*)malloc(sizeof(Graph));
        g->num_vertices = num_vertices;
        g->adj_list = (Node**)malloc(num_vertices * sizeof(Node*));
        for (int i = 0; i < num_vertices; i++) {
                g->adj_list[i] = NULL;
        }
        return g;
}

Graph* graph_destroy(Graph* g) {
        for (int i = 0; i < g->num_vertices; i++) {
                Node* current = g->adj_list[i];
                while (current != NULL) {
                        Node* temp = current;
                        current = current->next;
                        free(temp);
                }
        }
        free(g->adj_list);
        free(g);
        return NULL;
}

int graph_bfs(Graph* g, int start_vertex, int* visited) {
        if (!g || start_vertex < 0 || start_vertex >= g->num_vertices) return -1;

        Queue* q = queue_create();
        int visitado[MAX] = {0};

        visitado[start_vertex] = 1;
        queue_enqueue(q, start_vertex);

        while (!queue_is_empty(q)) {
                int v = queue_dequeue(q);
                printf("%d ", v);
                for (Node* current = g->adj_list[v]; current != NULL; current = current->next) {
                        int u = current->vertex;
                        if (!visitado[u]) {
                                visitado[u] = 1;
                                queue_enqueue(q, u);  
                        }
                }
        }
        return 0;
}

int graph_dfs(Graph* g, int start_vertex, int* visited) {
        if (!g || start_vertex < 0 || start_vertex >= g->num_vertices) return -1;

        Stack* s = stack_create();
        int visitado[MAX] = {0};

        visitado[start_vertex] = 1;
        stack_push(s, start_vertex);

        while (!stack_is_empty(s)) {
                int v = stack_pop(s);
                printf("%d ", v);
                for (Node* current = g->adj_list[v]; current != NULL; current = current->next) {
                        int u = current->vertex;
                        if (!visitado[u]) {
                                visitado[u] = 1;
                                stack_push(s, u);  
                        }
                }
        }
        return 0;
}