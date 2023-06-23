class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        if(n==0) return 0;
        int i=0;
        while(i<n && s[i]==' '){
            i++;
        }
        s = s.substr(i);
        int sign = +1;
        long ans=0;
        if(s[0]=='-') sign = -1;
        i = (s[0]=='+' || s[0]=='-')? 1 : 0;
        int maxi = INT_MAX;
        int mini = INT_MIN;
        while(i<n){
            if(s[i]==' ' || !isdigit(s[i])){
                break;
            }
            ans = ans*10 + s[i]-'0';
            if(sign==-1 && sign*ans<mini) return mini;
            else if(sign==1 && sign*ans>maxi) return maxi;
            i++;

        }
        return sign*ans;
    }
};

// coding ninjas
// #include <bits/stdc++.h>
// int atoi(string str) {
//   int num = 0;
//   for (auto i : str) {
//     if (isdigit(i))
//         num = (num * 10) + (i - '0');
//   }

//   return str[0] == '-' ? -num : num;
// }