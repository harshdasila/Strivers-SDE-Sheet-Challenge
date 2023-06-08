#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    int n =arr.size();
    int cnt=0;
    int xorr=0;
    unordered_map<int,int>mpp;
    for(auto it:arr){
        xorr = xorr^it;
        if(xorr==x){
            cnt++;
        }
        if(mpp.find(xorr^x)!=mpp.end()){
            cnt += mpp[xorr^x];
        }
        mpp[xorr]+=1;
    }
    return cnt;
}