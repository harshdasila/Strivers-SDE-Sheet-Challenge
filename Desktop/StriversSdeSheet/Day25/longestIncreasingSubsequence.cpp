int longestIncreasingSubsequence(int arr[], int n)
{
    int dp[n];
    int ans = 1;
    
    // Initialize all elements of dp with 1
    for(int i=0;i<n;i++) dp[i] = 1;
    
    // Calculate the length of longest increasing subsequence ending at each index
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    
    return ans;
}