class Solution {
public:

int expandFromCenter(string str, int i, int j){
    while(i>=0 && j<str.size() && str[i]==str[j]){
        i--;
        j++;
    }
    return j-i-1;
}
    string longestPalindrome(string str) {
        int start = 0;
        int end = 0;
        for(int i=0;i<str.size();i++){
            int len1 = expandFromCenter(str,i,i+1);
            int len2 = expandFromCenter(str,i,i);
            int len = max(len1,len2);
            if(end-start<len){
                start = i-(len-1)/2;
                end = i+len/2;
            }
        }
        return str.substr(start,end-start+1);
    }
};