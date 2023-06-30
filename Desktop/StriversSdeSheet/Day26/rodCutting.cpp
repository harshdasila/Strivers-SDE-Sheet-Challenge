int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<int> prev(n+1, 0), curr(n+1, 0);
    vector<vector<int>> dp(n, vector<int>(n+1, 0));
    for(int N=0;N<=n;N++) prev[N]=N*price[0];
 
    for(int i=1;i<n;i++){
        for(int N=0;N<n+1;N++){
            int notTake = prev[N];
            int take = INT_MIN;
            if(i+1<=N) take = price[i]+curr[N-(i+1)];
            curr[N]=max(take, notTake);
        }
        prev = curr;
    }
    return prev[n];
}
 