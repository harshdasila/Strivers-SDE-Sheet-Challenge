#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n = prices.size();
    int ans=-1;
    int min = prices[0];
    for(int i=1;i<n;i++){
        if(prices[i]<min){
            min = prices[i];
        }
        int dif = prices[i]-min;
        ans = max(ans,dif);
    }
    return ans;
}