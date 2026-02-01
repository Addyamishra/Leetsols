class Solution {
public:
    int finalElement(vector<int>& nums) {
        int ma=*max_element(nums.begin(),nums.end());
        if(ma==nums[0] || ma==nums[nums.size()-1]) return ma;
        return max(nums[0],nums[nums.size()-1]);
    }
};