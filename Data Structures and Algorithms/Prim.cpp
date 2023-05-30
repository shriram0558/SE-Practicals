#include<bits/stdc++.h>
using namespace std;

// 7

class data {
    public:
    int wt;
    int node;
    int parent;

    data(int wt, int node, int parent) {
        this->wt = wt;
        this->node = node;
        this->parent = parent;
    }
};

class compare {
    public:
    bool operator()(data d1, data d2){
        return (d1.wt >= d2.wt);
    }
};

// function to get MST using Prim's Algorithm
// Assuming graph to be connected
vector<pair<int, int>> primsAlgo(int n, vector<vector<pair<int, int>>>& adj){

    vector<pair<int, int>> mst;

    priority_queue<data, vector<data>, compare> pq; // minimum heap for edges according to their weights
    vector<bool> visited(n, 0);
    int sum = 0;
    pq.push(data(0, 0, -1));

    while(!pq.empty()){
        int wt = pq.top().wt;
        int node = pq.top().node;
        int parent = pq.top().parent;
        pq.pop();

        if(visited[node])
            continue;

        visited[node] = true;

        if(parent != -1)
            mst.push_back({parent, node});

        for(auto p : adj[node]){
            int adjNode = p.first;
            int adjWt = p.second;
            if(!visited[adjNode]){
                pq.push(data(adjWt, adjNode, node));
            }
        }
    }
    return mst;
}

void printMST(vector<pair<int, int>>& mst){
    cout << "Edges in the MST:\n";
    for(auto edge : mst){
        cout << edge.first << " " << edge.second << endl;
    }
}

int main() {

    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    // creation of adjacency list
    vector<vector<pair<int, int>>> adj(n);

    // taking input for weighted edges
    cout << "Enter edges (from, to, weight):\n";
    int u, v, wt;
    for(int i=0; i<m; i++){
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    // Get Minimum spanning tree
    vector<pair<int, int>> minSpanningTree = primsAlgo(n, adj);

    // Printing MST
    printMST(minSpanningTree);
}