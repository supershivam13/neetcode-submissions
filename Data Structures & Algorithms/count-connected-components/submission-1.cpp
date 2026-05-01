class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited){
        visited[node] = 1;

        for(auto neighbor : adj[node]){
            if(visited[neighbor] == 0)
                dfs(neighbor, adj, visited);
        }
    }
    
    // CODE starts here
    int countComponents(int n, vector<vector<int>>& edges) {

        // Step 1 : Prepare Adjacency List
        vector<vector<int>> adj(n);

        for(auto edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2 : Perform DFS to find connected components
        vector<int> visited(n, 0);
        int count = 0;

        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                dfs(i, adj, visited);
                count++;
            }
        }

        return count;
    }
};