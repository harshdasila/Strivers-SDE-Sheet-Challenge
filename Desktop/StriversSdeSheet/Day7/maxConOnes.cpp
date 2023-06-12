int longestSubSeg(vector<int> &arr , int n, int k){
    int ans=0;
    int cnt=0;
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0) cnt++;
        while(cnt>k){
            j++;
            if(arr[j]==0){
                cnt--;
            }
        }
        int len = i-j;
        if(len>ans) ans = len;
        
    }
    return ans;
}
