class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto a:queries){
            for(int i=a[0];i<=a[1];i+=a[2]){
                long long frst=nums[i]%1000000007;
                long long scnd=a[3]%1000000007;
                long long a=(frst*scnd)%1000000007;
                nums[i]=a;
            }
        }
        int ans=0;
        for(int i:nums) ans=ans^i;
        return ans;
    }
};