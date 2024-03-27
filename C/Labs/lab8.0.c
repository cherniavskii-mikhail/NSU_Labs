include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <malloc.h>

#define MAX_VERTEX 5000
#define EDGE_MAX ((numb_vert * (numb_vert + 1)) / 2)

typedef struct edge
{
	int edge_start;
	int edge_end;
	int edge_len;
	bool visited;
} Edge;


typedef struct graph
{
	int numb_vert;
	bool visited;
	Edge** adj_list;
} Graph;

void add_edge(Graph* graph, int edge_start, int edge_end, int edge_len)
{
	Edge* new_edge = (Edge*)malloc(sizeof(Edge));
	new_edge->edge_start = edge_start;
	new_edge->edge_end = edge_end;
	new_edge->edge_len = edge_len;
	graph->adj_list[edge_start - 1] = new_edge;
}

Graph* make_graph(int numb_vert)
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->numb_vert = numb_vert;
	graph->adj_list = (Edge**)malloc(numb_vert * sizeof(Edge*));

	for (int i = 0; i < numb_vert; i++)
		graph->adj_list[i] = NULL;

	return graph;
}

void make_skeleton(Graph* graph, Graph* skl_graph, int numb_edges, int i_cnt, int min_len)
{
	for (int i = 0; i < numb_edges; i++)
		if (graph->adj_list[i]->edge_len <= min_len && graph->adj_list[i]->visited == false)
			if (graph->adj_list[i]->edge_len < min_len)
			{
				min_len = graph->adj_list[i]->edge_len;
				i_cnt = i + 1;
			}

	skl_graph->adj_list[i_cnt] = graph->adj_list[i_cnt];
	graph->adj_list[i_cnt]->visited = true;
	i_cnt = skl_graph->adj_list[i_cnt]->edge_end;

	for (int i = 0; i < numb_edges; i++)
		if (graph->adj_list[i_cnt]->visited == false)
			make_skeleton(graph, skl_graph, numb_edges, i_cnt, min_len);

	return skl_graph;
}

void Kraskal(Graph* graph, int numb_edges, int numb_vert)
{
	int i_cnt = 1, min_len = 100;

	Graph* skl_graph = make_graph(numb_vert);

	make_skeleton(graph, skl_graph, numb_edges, i_cnt, min_len);

	for (int i = 0; i < numb_edges; i++)
		if (skl_graph->adj_list[i]->edge_len < min_len)
			min_len = graph->adj_list[i]->edge_len;

	for (int i = 0; i < numb_edges; i++)
		if (skl_graph->adj_list[i]->edge_len == min_len)
			printf("%d %d", skl_graph->adj_list[i]->edge_start, skl_graph->adj_list[i]->edge_end);
}

int main()
{
	int numb_vert = 0, numb_edges = 0;
	int edge_start = 0, edge_end = 0, edge_len = 0;

	int* vert_buf;

	Graph* graph;

	scanf_s("%d", &numb_vert);
	scanf_s("%d", &numb_edges);

	graph = make_graph(numb_vert);

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

		add_edge(graph, edge_start, edge_end, edge_len);
	}

	Kraskal(graph, numb_edges, numb_vert);

	return 0;
	
}
