#include <bits/stdc++.h> 
void f(vector<int>&arr,vector<vector<int>>&ans, vector<int>&ds, int n, int k, int ind){
    if(ind==n){
        if(k==0){
            ans.push_back(ds);
        }
        return;
    }
    
    if(arr[ind]<=k){
        ds.push_back(arr[ind]);
        f(arr,ans,ds,n,k-arr[ind],ind);
        ds.pop_back();
    }
    f(arr,ans,ds,n,k,ind+1);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>>ans;
    vector<int>ds;
    f(arr,ans,ds,n,k,0);
    return ans;
}