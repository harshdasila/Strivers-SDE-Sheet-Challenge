#include <bits/stdc++.h> 
void f(vector<vector<int>>&ans,vector<int>&temp,vector<int>&arr, int ind){
    ans.push_back(temp);
    for(int i=ind;i<arr.size();i++){
        if(i!=ind && arr[i]==arr[i-1]){
            continue;
        }
        temp.push_back(arr[i]);
        f(ans,temp,arr,i+1);
        temp.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>>ans;
    vector<int>temp;
    sort(arr.begin(),arr.end());
    f(ans,temp,arr,0);
    return ans;
}