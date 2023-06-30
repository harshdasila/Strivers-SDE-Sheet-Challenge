#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
  unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
    }
    //find indegree of all vertiices
    vector<int>indegree(v);
    for(auto i:adj){
        for(auto nbr:i.second){
            indegree[nbr]++;
        }
    }
    queue<int>q;
    //initiallisation of queue
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
            //BFS CONCEPT
          //  step 1
          while(!q.empty()){
            int front=q.front();
            //step 2
            q.pop();
            //step 3
            ans.push_back(front);
            //step 4 find neighbour
            for(auto neighbour:adj[front]){
                indegree[neighbour]--;
                
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
    return ans;
}