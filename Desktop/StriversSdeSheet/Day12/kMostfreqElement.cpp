#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,
    greater<pair<int,int>>>pq;
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto i = mpp.begin();i!=mpp.end();i++){
        pq.push({i->second,i->first});
        if(pq.size()>k){
            pq.pop();
        }
    }
    vector<int>ans;
    while(!pq.empty()){
        int ele = pq.top().second;
        pq.pop();
        ans.push_back(ele);
    }
    sort(ans.begin(),ans.end());
    return ans;
}