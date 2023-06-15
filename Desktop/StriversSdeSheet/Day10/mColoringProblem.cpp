#include <bits/stdc++.h> 

bool isSafe(vector<vector<int>>&mat, int n, vector<int>&color, int col, int ind){
    for(int k=0;k<n;k++){
        if(k!=ind && mat[k][ind]==1 && color[k]== col){
            return false;
        }
    }
    return true;
}

bool f(int ind,vector<vector<int>>&mat, int m, int n,vector<int>&color){
    if(ind==n) {
        return true;
    }
    for(int i=1;i<=m;i++){
        if(isSafe(mat,n,color,i,ind)){
            color[ind]=i;
            if(f(ind+1,mat,m,n,color)) return true;
            color[ind]=0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    vector<int>color(n,0);
    if(f(0,mat,m,n,color)) return "YES";
    else return "NO";
}