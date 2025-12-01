class Solution {
public:
typedef long long ll;
// bool check(ll m, int n,vector<int>&arr){

// }
    long long maxRunTime(int n, vector<int>& nums) {
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<=sum/n) return sum/n;
            sum-=nums[i];
            n--;
        }
        return sum/n*1LL;
        }
};