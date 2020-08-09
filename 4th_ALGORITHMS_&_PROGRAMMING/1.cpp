#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;

vector<vector<long long>> g;
vector<vector<long long >> c;
vector<long long> U;
vector<long long> d;
vector<long long> p;

void dijkstra(int r, int n)
{
    int v, w, min, i, j;
    for (i = 1; i <= n; i++)
    {
        U[i] = 0;
        p[i] = r;
        d[i] = INF;
    }
    d[r] = p[r] = 0;
    for (i = 1; i <= n; i++)
    {
        v = 0;
        min = INF;
        for (j = 1; j <= n; j++)
            if (U[j] == 0 && d[j] < min)
            {
                v = j;
                min = d[j];
            }
        U[v] = 1;
        for (j = 1; j <= g[v][0]; j++)
        {
            w = g[v][j];
            if (U[w] == 0 && d[v] + c[v][w] < d[w])
            {
                d[w] = d[v] + c[v][w];
                p[w] = v;
            }
        }
    }
}


int main(){
    int v,e;
    cin>>v>>e;
    g.resize(v+1);
    c.resize(v+1);
    int u,v,w;
    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            g[i].push_back(INF);
        }
        g[i][i] = 0;
    }
    
    int u,v,w;
    for(int m=0; m<e; m++){
        cin>>u>>v>>w;
        g[u][v] = w;
    }
    return 0;
}