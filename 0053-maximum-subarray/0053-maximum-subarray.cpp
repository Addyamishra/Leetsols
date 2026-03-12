class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,ans=INT_MIN;
        for(int i:nums){
          ans=max(ans,sum+=i);
          if(sum<=0) sum=0;
        }
        return ans;
    }
};