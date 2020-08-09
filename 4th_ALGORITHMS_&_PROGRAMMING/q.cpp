#include <iostream>
#include <vector>
#include <iomanip>
#define INF 1000000000
using namespace std;

vector<vector<long long int>> cost;
vector<vector<long long int>> path;

void printPath(int v, int u)
{
	if (path[v][u] == v)
		return;

	printPath(v, path[v][u]);
	cout << path[v][u] << " ";
}

void printSolution(int N)
{
	for (int v = 0; v < N; v++)
	{
		for (int u = 0; u < N; u++)
		{
			if (u != v && path[v][u] != -1)
			{
				cout << "Shortest Path from " << v << " -> " << u << " is (" << v << " ";
				printPath(v, u);
				cout << u << ")" << endl;
			}
		}
	}
}

// Function to run Floyd-Warshell algorithm
void floydWarshell(vector<vector<long long int>> adjMatrix, int N)
{
	for (int v = 0; v < N; v++)
	{
		for (int u = 0; u < N; u++)
		{
			cost[v].push_back(adjMatrix[v][u]);

			if (v == u)
				path[v].push_back(0);
			else if (cost[v][u] != INF)
				path[v].push_back(v);
			else
				path[v].push_back(-1);
		}
	}

	for (int k = 0; k < N; k++)
	{
		for (int v = 0; v < N; v++)
		{
			for (int u = 0; u < N; u++)
			{
				if (cost[v][k] != INF && cost[k][u] != INF
					&& cost[v][k] + cost[k][u] < cost[v][u])
				{
					cost[v][u] = cost[v][k] + cost[k][u];
					path[v][u] = path[k][u];
				}
			}

			if (cost[v][v] < 0)
			{
				cout << "Negative Weight Cycle Found!!";
				return;
			}
		}
	}

    //	printSolution(N);
}

int main()
{
	int vertices, edges;
    cin>>vertices>>edges;
    cost.resize(vertices);
    path.resize(vertices);
    vector<vector<long long int>> adjMatrix(vertices);

    for (int i = 0; i < vertices; i++){
        for (int j = 0; j < vertices; j++){
            adjMatrix[i].push_back(INF);
        }
        adjMatrix[i][i] = 0;
    }

    int u,v,w;
    for(int m=0; m<edges; m++){
        cin>>u>>v>>w;
        adjMatrix[--u][--v] = w;
    }

	floydWarshell(adjMatrix, vertices);

    int c,z;
    cin>>c>>z;
    if(path[--c][--z] != -1)
        printPath(c,z);

	return 0;
}