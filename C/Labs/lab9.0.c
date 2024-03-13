#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int vertex;
    int weight;
    Node* next;
} Node;


typedef struct graph
{
    int numb_vert;
    Node** adjlist;
} Graph;


typedef struct visited
{
    int dist;
    int proc;
    int parent;
} Visited;


Graph* make_graph(int vert)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numb_vert = vert;
    graph->adjlist = (Node**)malloc(vert * sizeof(Node*));

    for (int i = 0; i < vert; i++)
        graph->adjlist[i] = NULL;

    return graph;
}


Node* make_node(int vertex, int weight)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->vertex = vertex;
    new_node->weight = weight;
    new_node->next = NULL;

    return new_node;
}


void add_edge(Graph* graph, int start, int end, int weight)
{
    Node* new_node = make_node(end, weight);
    new_node->next = graph->adjlist[start - 1];
    graph->adjlist[start - 1] = new_node;

    new_node = make_node(start, weight);
    new_node->next = graph->adjlist[end - 1];
    graph->adjlist[end - 1] = new_node;
}


int extract_min(Node* prior_queue, Visited* vist_nodes)
{
    if (!prior_queue)
        return -1;

    int min_dist = INT_MAX;
    int min_vert = -1;
    Node* cur = prior_queue;

    while (cur)
    {
        int vertex = cur->vertex;
        if (!vist_nodes[vertex]->proc && vist_nodes[vertex]->distance <= min_dist)
        {
            min_dist = vist_nodes[vertex]->dist;
            min_vert = vertex;
        }
        cur = cur->next;
    }
    return min_vert;
}


void dejkstra(Graph* graph, int vert_start, int vert_end)
{
    Visited* vist_nodes = (Visited*)malloc(graph->numb_vert * sizeof(Visited));
    for (int i = 0; i < graph->numb_vert; i++)
    {
        vist_nodes[i]->dist = INT_MAX;
        vist_nodes[i]->proc = 0;
        vist_nodes[i]->parent = -1;
    }

    vist_nodes[vert_start - 1].dist = 0;
    Node* prior_queue = NULL;

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->vertex = vert_start - 1;
    new_node->weight = 0;
    new_node->next = NULL;
    prior_queue = new_node;

    while (prior_queue)
    {
        int min_edge = extract_min(prior_queue, vist_nodes);
        if (min_edge == -1)
            break;


        vist_nodes[min_edge].proc = 1;

        Node* temp = graph->adjlist[min_edge];

        while (temp)
        {
            int adj_vert = temp->vertex - 1;
            int alt = vist_nodes[min_edge]->dist + temp->weight;

            if (alt <= vist_nodes[adj_vert].dist)
            {
                vist_nodes[adj_vert]->dist = alt;
                vist_nodes[adj_vert]->parent = min_edge;

                Node* new_node = (Node*)malloc(sizeof(Node));
                new_node->vertex = adj_vert;
                new_node->weight = alt;
                new_node->next = prior_queue;
                prior_queue = new_node;
            }
            temp = temp->next;
        }
    }

    int path[graph->numb_vert];
    int path_len = 0;

    int cur = vert_end - 1;
    while (cur != -1)
    {
        path[path_len++] = cur + 1;
        cur = vist_nodes[cur]->parent;
    }

    for (int i = 0; i < graph->numb_vert; i++)
    {
        if (vist_nodes[i]->dist == INT_MAX)
            printf("oo ");
        else if (vist_nodes[i]->dist > INT_MAX)
            printf("INT_MAX+ ");
        else
            printf("%lld ", vist_nodes[i]->dist - vist_nodes[vert_start - 1]->dist);
    }
    printf("\n");

    int frst_check = 0;
    int sec_check = 0;

    for (int i = 0; i < path_len; i++)
    {
        if (path[i] == vert_start || path[i] == vert_end)
            frst_check++;
        if (vist_nodes[i + 1]->dist >= INT_MAX && vist_nodes[i + 1]->dist != INT_MAX)
            sec_check++;
    }

    if (frst_check != 2 && vert_start != vert_end)
    {
        printf("no path");
        return 0;
    }
    else if (vist_nodes[path_len - 1]->dist > INT_MAX && sec_check > 2)
    {
        printf("overflow");
        return 0;
    }

    for (int i = 0; i < path_len; i++)
        printf("%d ", path[i]);

    printf("\n");
}

int main()
{
    int numb_vert, start, end, numb_edges;
    int edge_start, edge_end;
    int edge_len;
    Graph* graph;

    scanf("%d", &numb_vert);
    scanf("%d", &start);
    scanf("%d", &end);
    scanf("%d", &numb_edges);
    

    graph = make_graph(numb_vert);

    int strcnt = 0;
    for (int i = 0; i < numb_edges; i++)
    {
        scanf("%d", &edge_start);
        scanf("%d", &edge_end);
        scanf("%d", &edge_len);

        if (edge_len < 0 || edge_len > INT_MAX)
        {
            prinrf("bad length");
            exit(0);
        }

        add_edge(graph, edge_start, edge_end, edge_len);
        strcnt++;
    }

    if (strcnt < numb_edges)
    {
        printf("bad number of lines");
        return 0;
    }

    if (numb_vert < 0 || numb_vert > 5000)
    {
        printf("bad number of vertices");
        return 0;
    }
    if (start < 1 || start > numb_vert || end < 1 || end > numb_vert)
    {
        printf("bad vertex");
        return 0;
    }
    if (numb_edges < 0 || numb_edges > numb_vert * (numb_vert + 1) / 2)
    {
        printf("bad number of edges");
        return 0;
    }

    dejkstra(graph, start, end);

    return 0;
}
