#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set<int>hashset;
    if(n==0) return 0;
    for(auto it:arr){
        hashset.insert(it);
    }
    int ans=0;
    for(auto it:arr){
        if(!hashset.count(it-1)){
            int cnt=1;
            int num = it;
            while(hashset.count(num+1)){
                cnt++;
                num+=1;
            }
            ans = max(ans,cnt);
        }
    }
    return ans;
}