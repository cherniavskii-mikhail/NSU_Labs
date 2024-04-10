#include<stdio.h>

#define MAX_VERTEX 5000
#define EDGE_MAX ((numb_vert * (numb_vert + 1)) / 2)

typedef struct Graph
{
	int vert_numb;
	int edge_numb;
	char* adj_list;
	char* inv_list;
	int* visited;
} Graph;

typedef struct Stack 
{
	int value;
	struct Stack* next;
}Stack;

Stack* create_stack() 
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->next = NULL;

	return stack;
}

void push(Stack* stack, int value) 
{
	Stack* new_stack = (Stack*)malloc(sizeof(Stack));

	new_stack->value = value;
	new_stack->next = stack->next;
	stack->next = new_stack;
}

int isEmpty(Stack* stack) 
{
	return stack->next == NULL;
}

int pop(Stack* stack) 
{
	if (isEmpty(stack))
		return -1;

	Stack* next_stack = stack->next;

	int val = next_stack->value;
	stack->next = next_stack->next;

	free(next_stack);

	return val;
}
void dfs(Graph* graph, int index, Stack* Stack) 
{
	graph->visited[index] = 1;

	for (int i = 0; i < graph->vert_numb; ++i)
		if (graph->adj_list[index * graph->vert_numb + i] && !graph->visited[i])
			dfs(graph, i, Stack);

	push(Stack, index);
}

void paint_dfs(Graph* graph, int vertex, int colour) 
{
	graph->visited[vertex] = colour;

	for (int i = 0; i < graph->vert_numb; ++i)
		if (graph->inv_list[vertex * graph->vert_numb + i] && !graph->visited[i])
			paint_dfs(graph, i, colour);
}

void kosorajo(Graph* graph)
{
	int vertex;
	int colour = 0;
	Stack* Stack = create_stack();

	for (int i = 0; i < graph->vert_numb; i++)
		if (!graph->visited[i])
			dfs(graph, i, Stack);

	for (int i = 0; i < graph->vert_numb; i++)
		graph->visited[i] = 0;

	while (!isEmpty(Stack)) {
		vertex = pop(Stack);

		if (!graph->visited[vertex])
			paint_dfs(graph, vertex, ++colour);
	}

	int max_comp = max(graph->visited, graph->vert_numb);

	for (int i = 1; i < max_comp + 1; i++) {
		printf("COMPONENT %d\n", i);

		for (int j = 0; j < graph->vert_numb; j++)
			if (graph->visited[j] == i)
				printf("%d ", j + 1);

		puts("");
	}

	free(Stack);
}

int main()
{
	int numb_vert = 0, numb_edges = 0;
	Graph* graph;

	scanf_s("%d", &numb_vert);
	scanf_s("%d", &numb_edges);

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

	kosorajo(graph);
	return 0;
}
