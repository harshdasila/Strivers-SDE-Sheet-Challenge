 #include<stack>
 int largestRectangle(vector < int > & heights) {
   int n = heights.size();
        vector<int>leftSmaller(n,0),rightSmaller(n,n-1);
        stack<pair<int,int>>st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().second>=heights[i]){
            st.pop();
            }
            if(!st.empty()){
            leftSmaller[i] = st.top().first+1;
            }
            st.push({i,heights[i]});
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]<=st.top().second){
                st.pop();
            }
            if(!st.empty()){
            rightSmaller[i] = st.top().first-1;
            }
            st.push({i,heights[i]});
        }
    
        int maxA=0;
        for(int i=0;i<n;i++){
            maxA = max(maxA,heights[i]*(rightSmaller[i]-leftSmaller[i]+1));
        }
        return maxA;

 }