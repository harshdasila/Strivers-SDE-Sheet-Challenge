int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n);
    sort(dt,dt+n);
    int i=0,j=1,cnt=1;
    int ans=1;
    while(i<n && j<n){
        if(dt[i]>=at[j]){
            j++;
            cnt++;
        }
        else{
            i++;
            cnt--;

        }
        ans = max(ans,cnt);
    }
    return ans;
}