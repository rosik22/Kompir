#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std; 


void getShortestPath(int end, int endVertices[]){
    if(endVertices[end] > 0){
        getShortestPath(endVertices[end],endVertices);
        cout<<end<<" ";
    }
}

void BellmanFord(int graph[][3], int V, int E, int src) { 
    int dis[V];
    int endVertices[V];
    int temp[V+1][1];

    for (int i = 1; i <= V; i++){
        dis[i] = INF;
        endVertices[i] = src;
    }

    dis[src] = 0;
    endVertices[src] = 0;

    for (int i = 0; i < V - 1; i++) { 
  
        for (int j = 0; j < E; j++) { 
            if (dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]]){
                dis[graph[j][1]] =  dis[graph[j][0]] + graph[j][2];
                endVertices[graph[j][1]] = graph[j][0];
            }
        }
    } 
    for(int i=1; i<=V; i++){
        temp[i][1] = dis[i];
    }

    getShortestPath(V,endVertices);
    
} 


int main() 
{ 
    int src, V, E;
    cin>>V>>E;
    int graph[E][3];
    
    int u,v,w;
    for(int i=0; i<E; i++){
        cin>>u>>v>>w;
        graph[i][0] = u;
        graph[i][1] = v;
        graph[i][2] = w;
    }
    cin>>src;
    BellmanFord(graph,V, E, src); 
    return 0; 
} 