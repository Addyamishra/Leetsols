class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
     sort(nums.begin(),nums.end());
     int s=0;
     int e=1;
     int ans=INT_MIN;
     while(e<nums.size()){
        int curr=INT_MIN;
        if(s!=0) curr=nums[s]+nums[e]-nums[0];
        if(e!=nums.size()-1) curr=max(curr,nums[s]+nums[e]-nums[nums.size()-1]);
        ans=max(ans,curr);
        s++,e++;
     }
return ans;
    }
};