#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<vector<int>> &adj, vector<bool> &visited,  int v) {
    visited[v] = true;
    cout << v << " ";
    for (auto neighbour: adj[v])
    {
        if(!visited[neighbour]) {
            dfs(adj, visited, neighbour);
        }
    }
    
}

void bfs(vector<vector<int>> &adj, int start) {
    vector<bool>visited(adj.size(), false);

    visited[start] = true;
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        cout << v << " ";
        for(auto neighbor : adj[v]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> adj(V);

    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    vector<bool> visited(V, false);
    cout << "DFS Traversal: ";
    dfs(adj, visited, start);
    cout << endl;

    cout << "BFS Traversal: ";
    bfs(adj, start);
    cout << endl;

    return 0;
}