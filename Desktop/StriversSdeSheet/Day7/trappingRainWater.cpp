#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    vector<long >prefix(n);
    vector<long >suffix(n);
    prefix[0] = arr[0];
    suffix[n-1] = arr[n-1];
    for(long i=1;i<n;i++){
        prefix[i] = max(prefix[i-1],arr[i]);
    }
    for(long i = n-2;i>=0;i--){
        suffix[i] = max(suffix[i+1],arr[i]);
    }
    long ans = 0;
    for(long i=0;i<n;i++){
        ans+=min(prefix[i],suffix[i])-arr[i];
    }
    return ans;

}