bool dfs_isCycle(vector<vector<int>> &adj, vector<bool> &visited, int node, int parent){
    // Base Case
    if(visited[node]){
        return false;
    }
    visited[node] = true;
    bool ans = false;
    for(int v : adj[node]){
        if(visited[v]){
            if(parent == v) continue;
            else return true;
        }
        else{
            ans = ans || dfs_isCycle(adj, visited, v, node);
        }
    }
    return ans;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // DFS Traversal + Parent Information
    // Time Complexity: O(V + E)
    // Space Complexity: O(V + E)
    // Build the adj. list
    vector<vector<int>> adj(n + 1);
    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    // Visited array and parent
    vector<bool> visited(n + 1, false);
    // DFS 
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            if(dfs_isCycle(adj, visited, i, -1)) return "Yes";
        }
    }
    return "No";
}