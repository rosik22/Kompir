#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;

int const MAX = 100;
vector<vector<long long int>> G;
//vector<vector<long long int>> c;
int visited[MAX], c[MAX][MAX],
    endVertices[MAX], distances[MAX], vertices, edges, startingVertex;

void dijkstra(int startingVertex)
{
    int v, w, min, i, j;
    for (i = 1; i <= vertices; i++)
    {
        visited[i] = 0;
        endVertices[i] = startingVertex;
        distances[i] = INF;
    }
    distances[startingVertex] = endVertices[startingVertex] = 0;
    for (i = 1; i <= vertices; i++)
    {
        v = 0;
        min = INF;
        for (j = 1; j <= vertices; j++)
            if (visited[j] == 0 && distances[j] < min)
            {
                v = j;
                min = distances[j];
            }
        visited[v] = 1;
        for (j = 1; j <= G[v][0]; j++)
        {
            w = G[v][j];
            if (visited[w] == 0 && distances[v] + c[v][w] < distances[w])
            {
                distances[w] = distances[v] + c[v][w];
                endVertices[w] = v;
            }
        }
    }
}

void getShortestPath(int end){
    if(endVertices[end]>0){
        getShortestPath(endVertices[end]);
        cout<<endVertices[end]<<" -> "<<end<<endl;
    }
}

int main()
{
    int u, v, w, i, j;
    cin>>vertices>>edges>>startingVertex;
    G.resize(edges);

    for (i = 1; i <= vertices; i++)
    {
        G[i].push_back(0);
        for (j = 1; j <= vertices; j++)
            c[i][j] = INF;
        if (i == j)
            c[i][j] = 0;
    }

    for (i = 1; i <= edges; i++)
    {   
        cin>>u>>v>>w;
        G[u].push_back(v);
        G[v].push_back(u);
        G[u][0]++;
        G[v][0]++;
        c[u][v] = c[v][u] = w;
    }
    dijkstra(startingVertex);
    for (i = 1; i <= vertices; i++)
        cout<<"vertices: "<<endVertices[i]<<" -> "<<i<<endl;

    cout<<"Shortest path from "<<startingVertex<<" to "<<vertices<<": "<<endl;
    getShortestPath(vertices);
    return 0;
}
