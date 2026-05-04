class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int z=0;
        int s=0;
        int e=0;
        int ans=0;
        while(e<nums.size()){
          if(nums[e]==0) z++;
          while(z>k){
            if(nums[s]==0) z--;
            s++;
          }
          ans=max(ans,e-s+1);
          e++;
        }
        return ans;
    }
};