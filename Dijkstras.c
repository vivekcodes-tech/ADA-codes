#include <stdio.h>

#define MAX 20
#define INF 99999

int main()
{
    int graph[MAX][MAX];
    int dist[MAX], visited[MAX];
    int n, source;
    int i, j, count, min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (count = 0; count < n - 1; count++)
    {
        min = INF;
        u = -1;

        for (i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < n; j++)
        {
            if (!visited[j] &&
                graph[u][j] != INF &&
                dist[u] + graph[u][j] < dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("\nShortest distances from source %d:\n", source);

    for (i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            printf("Vertex %d : Unreachable\n", i);
        else
            printf("Vertex %d : %d\n", i, dist[i]);
    }

    return 0;
}