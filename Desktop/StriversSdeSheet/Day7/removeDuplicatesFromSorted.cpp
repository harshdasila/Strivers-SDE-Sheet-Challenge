class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return n;
        int left=0;
        for(int right=1;right<n;right++){
            if(nums[left]!=nums[right]){
                left++;
                nums[left] = nums[right];
            }
        }
        return left+1;
    }
};