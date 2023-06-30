int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    //top-down
    int t[n+1][w+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(weights[i-1]<=j){
                t[i][j]=max(values[i-1]+t[i-1][j-weights[i-1]],
                t[i-1][j]);
            }
            else t[i][j]=t[i-1][j];
        }
    }
    return t[n][w];
 
    
}