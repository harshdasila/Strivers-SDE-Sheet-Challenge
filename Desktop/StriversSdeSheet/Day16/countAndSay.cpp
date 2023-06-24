#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	if(n==1) return "1";
	string s = writeAsYouSpeak(n-1);
	string ans="";
	int cnt=0;
	for(int i=0;i<s.size();i++){
		cnt++;
		if(i==s.size()-1 || s[i]!=s[i+1]){
			
			ans+=to_string(cnt)+s[i];
			cnt=0;
		}
	}	
	return ans;
}