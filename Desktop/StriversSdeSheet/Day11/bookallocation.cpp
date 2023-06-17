#include <bits/stdc++.h> 

bool allocationPossible(long long int mid, int x, vector<int>&time){
	long long int cnt=1;
	long long int sum=0;
	for(int i=0;i<time.size();i++){
		if(time[i]>mid) return false;
		if(sum+time[i]>mid){
			cnt+=1;
			sum=time[i];
		}
		else{
			sum+=time[i];
		}
		
	}
	if(cnt>x) return false;
	return true;
	
	
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long int sum=0,res=1;
	int mini = INT_MAX;
	for(int i=0;i<m;i++){
		sum+=time[i];
		mini = min(time[i],mini);
	}
	long long int low = mini;
	long long int high = sum;
	while(low<=high){
		long long int mid = (low+high)>>1;
		if(allocationPossible(mid,n,time)){
			res = mid;
			high = mid-1;
		}
		else low = mid+1;
	}
	return res;
}