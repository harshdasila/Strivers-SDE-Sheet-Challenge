int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size();
	int low = 0, high = n-1;
	while(low<high){
		int mid = (low+high)>>1;
		if(mid%2==0){
			if(mid==n-1 || arr[mid]==arr[mid+1]){
				low = mid+1;
			}
			else high = mid;
		}
		else{
			if(mid==0 ||arr[mid]==arr[mid-1]){
				low = mid+1;
			}
			else high = mid;
		}

	}
	return arr[low];
}