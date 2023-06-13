#include <bits/stdc++.h> 
static bool cmp(vector<int>a,vector<int>b){
    return a[1]>b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    sort(jobs.begin(),jobs.end(),cmp);
    int maxDead=0;
    for(int i=0;i<n;i++){
        maxDead = max(maxDead,jobs[i][0]);
    }
    int data[maxDead+1];
    for(int i=0;i<=maxDead;i++){
        data[i]=-1;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=jobs[i][0];j>0;j--){
            if(data[j]==-1){
                data[j] = 1;
                ans+=jobs[i][1];
                break;
            }
        }
    }
    return ans;
}
