#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  unordered_map<int,int>mpp;
  int sum=arr[0];
  int ans=0;
  for(int i=1;i<arr.size();i++){
      sum+=arr[i];
      if(sum==0){
        ans = i+1;
      }
      else{
        if(mpp.find(sum)!=mpp.end()){
          ans = max(ans,i-mpp[sum]);
        }
        else mpp[sum]=i;
      }
  }
  return ans;

}