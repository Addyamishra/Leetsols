class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long LIMIT = 1e14 + 5;

        vector<long long> p(n+1,1);

        for(int i=n-1;i>=0;i--){
            if(p[i+1] > LIMIT / nums[i])
                p[i] = LIMIT;
            else
                p[i] = p[i+1] * nums[i];
        }

        for(int i=0;i<n;i++){
            if(sum == p[i+1]) return i;
            sum += nums[i];
        }

        return -1;
    }
};