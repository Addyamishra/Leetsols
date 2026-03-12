class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int ans=INT_MIN;
        for(int i:nums){
          sum+=i;
          ans=max(ans,sum);
          if(sum<=0) sum=0;
        }
        return ans;
    }
};