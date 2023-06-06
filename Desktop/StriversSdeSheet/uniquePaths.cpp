#include <bits/stdc++.h> 

int f(int i, int j, int m, int n, vector<vector<int>>&dp){
	if(i==m-1 && j==n-1) return 1;
	if(i>=m || j>=n) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	else return dp[i][j] = f(i+1,j,m,n,dp)+f(i,j+1,m,n,dp);
}

int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
	return f(0,0,m,n,dp);
}


//optimized

// #include <bits/stdc++.h> 
// int uniquePaths(int m, int n) {
// 	int N = m+n-2;
// 	int r = m-1;
// 	double res=1;
// 	for(int i=1;i<=r;i++){
// 		res = res*(N-r+i)/i;
// 	}
// 	return (double) res;
// }