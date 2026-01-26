class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        for(int i=nums.size()-1;i>=1;i--){
            if(nums[i]<=nums[i-1]) return i;
        }
        return 0;
    }
};