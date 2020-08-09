#include <iostream>
#include <iomanip>
#include <vector>
#define INF 1000000000
using namespace std;

vector<vector<long long int>> G;
vector<vector<long long int>> path;

void printPath(int v, int u)
{
	if (path[v][u] == v)
		return;

	printPath(v, path[v][u]);
	cout << path[v][u] << " ";
}

void floydWarshell(int V){
	for (int v = 0; v < V; v++){
		for (int u = 0; u < V; u++){
			if (v == u)
				path[v][u] = 0;
			else if (G[v][u] != INF)
				path[v][u] = v;
		}
	}

	for (int k = 1; k <= V; k++){
		for (int v = 1; v <= V; v++){
			for (int u = 1; u <= V; u++){
				if (G[v][k] != INF && G[k][u] != INF
					&& G[v][k] + G[k][u] < G[v][u])
				{
					G[v][u] = G[v][k] + G[k][u];
					path[v][u] = path[k][u];
				}
			}

			if (G[v][v] < 0)
			{
				cout << "Negative Weight Cycle Found!!";
				return;
			}
		}
	}

}

int main()
{	
	int V,E;
	cin>>V>>E;
    G.resize(V+1);
	path.resize(V+1);
	for (int i = 1; i <= V; i++){
        for (int j = 1; j <= V; j++){
            G[i].push_back(INF);
			path[i].push_back(-1);
        }
        G[i][i] = 0;
    }

	int u,v,w;
    for(int m=0; m<E; m++){
        cin>>u>>v>>w;
        G[u][v] = w;
    }

	floydWarshell(V);
	for(auto a: G){
		for(auto q:a){
			cout<<q<<" ";
		}
		cout<<endl;
	}

	for(auto a: path){
		for(auto q:a){
			cout<<q<<" ";
		}
		cout<<endl;
	}

	int u1, v1;
	cin>>u1>>v1;
	cout<<"("<<u1<<" ";
	printPath(u1,v1);
	cout<<" "<<v1;
	return 0;
}