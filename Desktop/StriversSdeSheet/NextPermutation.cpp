#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &arr, int n)
{
    int k,j;
    for(k=n-2;k>=0;k--){
        if(arr[k]<arr[k+1]) break;
        
    }
    if(k<0){
        reverse(arr.begin(),arr.end());
        return arr;
    }
    else{
        for(j=n-1;j>k;j--){
            if(arr[j]>arr[k]){
                break;
            }
        }
    }
    swap(arr[j],arr[k]);
    reverse(arr.begin()+k+1,arr.end());
    return arr;
}