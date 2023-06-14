#include <bits/stdc++.h> 
void f(vector<int>&num, vector<int>&ans, int ind, int sum){
    int n = num.size();
    if(ind==n){
        ans.push_back(sum);
        return;
    }
    f(num,ans,ind+1,sum+num[ind]);
    f(num,ans,ind+1,sum);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int>ans;
    f(num,ans,0,0);
    sort(ans.begin(),ans.end());
    return ans;

}