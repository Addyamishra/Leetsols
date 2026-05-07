class Solution {
public:
    int hIndex(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int c=0;
        for(int i=nums.size()-1;i>=0;i--){
          c++;
          if(nums[i]==c) ans=max(ans,nums[i]);
          if(nums[i]>c) ans=max(ans,c);
        }
        return ans;
    }
};