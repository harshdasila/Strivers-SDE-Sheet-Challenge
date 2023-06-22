#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    int n = price.size();
    stack<pair<int,int>>st;
    vector<int>ans;
    for(int i=0;i<n;i++){
        int cnt=0;
        while(!st.empty() && st.top().first<=price[i]){
            cnt+=st.top().second;
            st.pop();
        }
        cnt++;
        ans.push_back(cnt);
        st.push({price[i],cnt});
    }
    return ans;
}