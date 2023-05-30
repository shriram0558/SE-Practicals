#include<bits/stdc++.h>
using namespace std;

// 6

void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis){

    vis[u] = 1;
    cout << u << " ";

    for(int v : adj[u]){
        if(!vis[v])
            dfs(v, adj, vis);
    }
}

void bfs(int u, vector<vector<int>>& adj, vector<bool>& vis){

    queue<int> q;
    q.push(u);
    vis[u] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int v : adj[u]){
        if(!vis[v]){
            q.push(v);
            vis[v] = true;
        }
    }
    }
}

int main(){

    int n, m; // no of vertices, no of edges
    cout << "Enter Number of vertices: ";
    cin >> n;
    cout << "Enter Number of Edges: ";
    cin >> m;
    
    vector<vector<int>> adj(n); // adjacency list

    // Taking Input for edges
    cout << "Enter edges: " << endl;
    int u, v;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // printing DFS
    cout << "DFS: ";
    vector<bool> vis(n, false);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i, adj, vis);
        }
    }
    cout << endl;

    // printing BFS
    cout << "BFS: ";
    vis = vector<bool>(n, false);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            bfs(i, adj, vis);
        }
    }
    cout << endl;
    
    return 0;
}