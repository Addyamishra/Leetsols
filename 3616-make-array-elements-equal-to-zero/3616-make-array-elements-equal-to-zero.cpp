class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum=0,ans=0;
        for(int i=0;i<nums.size();i++){
          if(nums[i]==0){
            int sum2=0;
            for(int j=i+1;j<nums.size();j++) sum2+=nums[j];
            if(sum==sum2) ans+=2;
            if(abs(sum-sum2)==1) ans++;
          }
          sum+=nums[i];
        }
        return ans;
    }
};