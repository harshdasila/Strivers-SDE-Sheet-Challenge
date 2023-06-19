#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	priority_queue<pair<int,pair<int,int>>>pq;
	sort(a.begin(),a.end(),greater<int>());
	sort(b.begin(),b.end(),greater<int>());
	vector<int>ans;
	set<pair<int,int>>st;
	pq.push({a[0]+b[0],{0,0}});
	st.insert({0,0});
	while(true){
		int ele = pq.top().first;
		int arr1 = pq.top().second.first;
		int arr2 = pq.top().second.second;
		pq.pop();
		ans.push_back(ele);
		if(arr1+1<a.size() && st.find({arr1+1,arr2})==st.end()){
			pq.push({a[arr1+1]+b[arr2],{arr1+1,arr2}});
			st.insert({arr1+1,arr2});
		}
		if(arr2+1<a.size() && st.find({arr1,arr2+1})==st.end()){
			pq.push({a[arr1]+b[arr2+1],{arr1,arr2+1}});
			st.insert({arr1,arr2+1});
		}
		if(ans.size()==k) break;
	}
	return ans;
	
}