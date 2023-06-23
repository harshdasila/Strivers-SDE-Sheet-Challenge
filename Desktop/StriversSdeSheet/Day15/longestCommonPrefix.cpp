#include<bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    sort(arr.begin(),arr.end());
    string ans="";
    string first = arr[0];
    string last =arr[n-1];
    for(int i=0;i<min(first.size(),last.size());i++){
        if(first[i]!=last[i]){
            return ans;
        }
        ans+=first[i];
    }
    return ans;
}


