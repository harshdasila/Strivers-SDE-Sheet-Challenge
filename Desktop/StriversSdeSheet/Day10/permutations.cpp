#include <bits/stdc++.h> 

void f(string &s, vector<string>&ans, int ind){
    vector<string>temp;
    if(ind==s.size()){
        ans.push_back(s);
        return;
    }
    for(int i=ind;i<s.size();i++){
        swap(s[ind],s[i]);
        f(s,ans,ind+1);
        swap(s[ind],s[i]);
    }
}
vector<string> findPermutations(string &s) {
    int n = s.size();
    vector<string>ans;
    f(s,ans,0);
    return ans;
}