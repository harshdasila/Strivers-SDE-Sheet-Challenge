#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	//find the condidate element
	int ele = arr[0];
	int cnt=1;
	for(int i=1;i<n;i++){
		if(arr[i]==ele) cnt++;
		else cnt--;
		if(cnt==0){
			ele = arr[i];
			cnt=1;
		}
	}
	//for checking for the candidate if it is possible 
	int count=0;
	for(int i=0;i<n;i++){
		if(arr[i]==ele){
			count++;
		}
	}
	return (count>(n/2))? ele : -1;
}