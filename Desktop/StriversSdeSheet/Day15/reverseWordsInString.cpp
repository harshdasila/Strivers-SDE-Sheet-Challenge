#include <bits/stdc++.h>
string reverseString(string &str){
	stack<string>st;
	string temp="";
	for(auto it: str){
		if(it==' '){
			if(temp!=""){
				st.push(temp);
				temp="";
			}
		}
		else{
			temp+=it;
		}
	}
	if(temp!="") st.push(temp);
	string ans;
	while(!st.empty()){
		ans+=st.top();
		st.pop();
		if(!st.empty()) ans+=" ";
	}
	return ans;
}