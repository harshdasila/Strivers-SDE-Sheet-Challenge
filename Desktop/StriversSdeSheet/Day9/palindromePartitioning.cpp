#include <bits/stdc++.h> 

bool isPalin(int start , int end, string &s){
    while(start<=end){
        if(s[start++]!=s[end--]){
            return false;
        }
        
    }
    return true;
}

void f(string &s, vector<vector<string>>&ans, vector<string>&path, int ind){
    int n = s.size();
    if(ind==n){
        ans.push_back(path);
        return;
    }
    for(int i=ind;i<n;i++){
        if(isPalin(ind,i,s)){
            path.push_back(s.substr(ind,i-ind+1));
            f(s,ans,path,i+1);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>>ans;
    vector<string>path;
    f(s,ans,path,0);
    return ans;
}