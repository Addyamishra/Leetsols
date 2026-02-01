class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans=nums[0];
        sort(nums.begin()+1,nums.end());
        return ans+nums[1]+nums[2];
    }
};