#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    int n = s.size();
        vector<int>mpp(256,-1);
        int left=0,right=0;
        int length=0;
        while(right<n)
        {
            if(mpp[s[right]]!=-1) left = max(mpp[s[right]]+1,left);
            mpp[s[right]] = right;
            length = max(length,right-left+1);
           right++;
        }
        return length;
}