#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<pair<int,pair<int,int>>, 
    vector<pair<int,pair<int,int>>>, 
    greater<pair<int,pair<int,int>>>>pq; //min-heap

    vector<int>ans;
    
    for(int i=0;i<kArrays.size();i++){
        pq.push({kArrays[i][0],{i,0}});
    }
    while(pq.size()>0){
        int data = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();
        ans.push_back(data);
        if(col+1<kArrays[row].size()){
            pq.push({kArrays[row][col+1],{row,col+1}});
        }
    }
    return ans;

}
