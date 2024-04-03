#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <malloc.h>

#define MAX_VERTEX 5000
#define EDGE_MAX ((numb_vert * (numb_vert + 1)) / 2)

typedef struct Graph
{
    int numb_vert;
    int* adj_list;
    int* input_edge;
} Graph;

Graph* make_graph(int numb_vert)
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->numb_vert = numb_vert;
	graph->adj_list = (Graph**)malloc(numb_vert * sizeof(Graph*));

	for (int i = 0; i < numb_vert; i++)
		graph->adj_list[i] = NULL;

	return graph;
}

int top_sort(Graph* graph, int* result)
{
	int front = 0, node, ind_i = -1, res_ind = 0;
	int* queue = (int*)malloc(graph->numb_vert * sizeof(int));

	for (int i = 0; i < graph->numb_vert; i++)
		if (graph->input_edge[i] == 0)
			queue[++ind_i] = i;

	while (front <= ind_i)
	{
		node = queue[front++];
		result[res_ind++] = node;

		for (int i = 0; i < graph->numb_vert; i++)
		{
			if (graph->numb_vert[node * graph->numb_vert + i] == 1)
			{
				graph->input_edge[i]--;
				if (graph->input_edge[i] == 0)
					queue[++ind_i] = i;
			}
		}
	}
	free(queue);

	if (res_ind != graph->numb_vert)
		return -1;

	return 0;
}


int main()
{
	int numb_vert = 0, numb_edges = 0;
	int edge_start = 0, edge_end = 0, edge_len = 0;

	int* vert_buf;

	Graph* graph;

	scanf_s("%d", &numb_vert);
	scanf_s("%d", &numb_edges);

	graph->numb_vert = numb_vert;
	graph->adj_list = (int*)calloc(numb_vert * sizeof(int));
	graph->input_edge = (int*)calloc(numb_vert, sizeof(int));

	if (numb_vert < 0 || numb_vert > MAX_VERTEX)
	{
		puts("bad number of vertices");
		return -1;
	}

	if (numb_edges < 0 || numb_edges > EDGE_MAX)
	{
		puts("bad number of edges");
		return -1;
	}

	for (int i = 0; i < numb_edges; i++)
	{
		scanf_s("%d %d %d", &edge_start, &edge_end, &edge_len);

		if (edge_len < 0 || edge_len > INT_MAX)
		{
			puts("bad length");
			return 0;
		}

		if (edge_start < 1 || edge_start > numb_vert || edge_end < 1 || edge_end > numb_vert)
		{
			puts("bad vertex");
			return 0;
		}
	}

	return 0;
}
