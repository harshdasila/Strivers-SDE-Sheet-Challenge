int countGreater(vector<int>&row, int mid){
    int l=0,h=row.size()-1;
    while(l<=h){
        int m = (l+h)>>1;
        if(row[m]<=mid) l = m+1;
        else h = m-1;
    }
    return l;
}

int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 1;
    int high = 1e5;
    while(low<=high){
        int mid = (low+high)>>1;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=countGreater(matrix[i],mid);
        }
        if(cnt<=(n*m/2)) low = mid+1;
        else high = mid-1;

    }
    return low;
}