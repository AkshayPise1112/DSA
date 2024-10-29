#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    // Number of Provinces
    // https://www.geeksforgeeks.org/problems/number-of-provinces/1

    void bfs(int start, vector<vector<int>>& adj, vector<int>& vis) {
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int i = 0; i < adj.size(); i++) {
                if (adj[node][i] == 1 && !vis[i]) {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> vis(V, 0);
        int cnt = 0;
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++;
                bfs(i, adj, vis);
            }
        }
        
        return cnt;
    }

    // Print adjacency list
    // https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        int n = V;
        int m = edges.size();
        
        vector<vector<int>> ans(n);
        
        for(int i=0; i<m; i++){
            ans[edges[i].first].push_back(edges[i].second);
            ans[edges[i].second].push_back(edges[i].first);
        }
        
        return ans;
    }

    // BFS of graph
    // https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

    
    void bfs(vector<vector<int>> &adj, vector<int>& visited, vector<int>& ans, int n, int start){
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            ans.push_back(ele);
            
            for(int i=0; i<adj[ele].size(); i++){
                if(visited[adj[ele][i]] == 0){
                    visited[adj[ele][i]] = 1;
                    q.push(adj[ele][i]);
                }
            }
        }
    }
    
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> visited(n, 0);
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                visited[i] = 1;
                bfs(adj, visited, ans, n, i);
            }
        }
        
        return ans;
    }
};