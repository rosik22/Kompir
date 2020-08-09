#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs1(int v)
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if (!visited[u])
            dfs1(u);
    }
    ans.push_back(v);
}

void topological_sort(vector<int> items)
{
    ans.clear();
    for (auto i : items)
    {
        if (!visited[i])
            dfs1(i);
    }
    reverse(ans.begin(), ans.end());
}

void print()
{
    for (auto a : ans)
        cout << a << " ";
        cout << endl;
}

int main()
{
    int n = 0; // Number of corners.
    int r = 0; // Number of roads.
    cin >> n >> r;
    adj.resize(n + 1);
    visited.resize(n + 1);

    int c = 1;
    int c1 = 1;

    int r1 = r;
    vector<int> items;

    while (c != 0 || c1 != 0)
    {
        if (r1 == 0)
        {
            break;
        }
        cin >> c >> c1;
        adj[c].push_back(c1);

        if (std::find(items.begin(), items.end(), c) == items.end())
            items.push_back(c);
        if (std::find(items.begin(), items.end(), c1) == items.end())
            items.push_back(c1);

        r1 -= 1;
    }

    for (int v = 0; v < n; v++)
    {
        sort(adj[v].begin(), adj[v].end());
    }

    topological_sort(items);
    print();

    return 0;
}
