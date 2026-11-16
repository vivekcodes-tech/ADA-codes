#include <stdio.h>

#define MAX 100
#define INF 99999

struct Edge
{
    int u, v, w;
};

int main()
{
    struct Edge edge[MAX];
    int dist[20];
    int n, e, source;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");

    for (i = 0; i < e; i++)
    {
        scanf("%d %d %d",
              &edge[i].u,
              &edge[i].v,
              &edge[i].w);
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initialize distances
    for (i = 0; i < n; i++)
        dist[i] = INF;

    dist[source] = 0;

    // Relax all edges V-1 times
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < e; j++)
        {
            int u = edge[j].u;
            int v = edge[j].v;
            int w = edge[j].w;

            if (dist[u] != INF &&
                dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for (j = 0; j < e; j++)
    {
        int u = edge[j].u;
        int v = edge[j].v;
        int w = edge[j].w;

        if (dist[u] != INF &&
            dist[u] + w < dist[v])
        {
            printf("Negative weight cycle detected.\n");
            return 0;
        }
    }

    // Display shortest distances
    printf("\nShortest distances from source %d:\n",
           source);

    for (i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            printf("Vertex %d : Unreachable\n", i);
        else
            printf("Vertex %d : %d\n", i, dist[i]);
    }

    return 0;
}