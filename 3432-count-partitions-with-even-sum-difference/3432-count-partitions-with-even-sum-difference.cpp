class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int s=0;
        int ans=0;
        for(int i:nums){
            s+=i;
            if(abs(s-(sum-s))%2==0) ans++;
        }
        return max(ans-1,0);
    }
};