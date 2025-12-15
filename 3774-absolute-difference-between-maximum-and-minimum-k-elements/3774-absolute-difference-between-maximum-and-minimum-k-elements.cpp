class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<k;i++) ans-=nums[i];
         for(int i=nums.size()-k;i<nums.size();i++) ans+=nums[i];
         return ans;
    }
};