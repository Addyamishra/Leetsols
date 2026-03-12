class Solution {
public:
    int maxProduct(vector<int>& nums) {
     int mi=nums[0],ma=nums[0],ans=nums[0];
     for(int j=1;j<nums.size();j++){
        int i=nums[j];
        if(i<0) swap(mi,ma);
        mi=min(mi*i,i),ma=max(ma*i,i);
        ans=max(ans,ma);
     }
     return ans;
    }
};