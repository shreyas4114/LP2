#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

bool compare(Edge a, Edge b) {
    return (a.weight < b.weight);
}

int findParent(vector<int>& parent, int u) {
    if(parent[u] != u) {
        parent[u] = findParent(parent, parent[u]);
    }
    return parent[u];
}

void unionSet(vector<int>& parent, vector<int>& rank, int x, int y) {
    int xroot = findParent(parent, x);
    int yroot = findParent(parent, y);

    if(xroot != yroot) {
        if(rank[xroot] < rank[yroot]) {
            parent[xroot] = yroot;
        }
        else if(rank[xroot] > rank[yroot]) {
            parent[yroot] = xroot;
        }
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
}

vector<Edge> kruskal(vector<Edge>& edges, int V) {
    vector<Edge> result;
    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    int i=0;
    while (result.size() < V-1 && i < edges.size()) 
    {
        Edge next_edge = edges[i++];

        int x = findParent(parent, next_edge.src);
        int y = findParent(parent, next_edge.dest);

        if(x != y) {
            result.push_back(next_edge);
            unionSet(parent, rank, x, y);
        }
    }
    
    return result;
}

int main()
{
    int V, E;
    vector<Edge> edges;

    while (true) {
        cout << "\n=== MENU ===\n";
        cout << "1. Enter Graph Details\n";
        cout << "2. Compute MST using Kruskal's Algorithm\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter number of vertices: ";
                cin >> V;
                cout << "Enter number of edges: ";
                cin >> E;

                edges.clear();
                for (int i = 0; i < E; i++) {
                    Edge edge;
                    cout << "Enter edge " << i + 1 << " (source destination weight): ";
                    cin >> edge.src >> edge.dest >> edge.weight;
                    edges.push_back(edge);
                }
                break;
            }

            case 2: {
                if (edges.empty()) {
                    cout << "No edges entered. Please enter graph details first.\n";
                    break;
                }

                vector<Edge> mst = kruskal(edges, V);

                cout << "\nEdges in the Minimum Spanning Tree:\n";
                for (Edge edge : mst) {
                    cout << edge.src << " -> " << edge.dest << " == " << edge.weight << endl;
                }
                break;
            }

            case 3:
                cout << "Exiting program. Thank you!\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}