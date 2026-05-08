class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        map<int,int> cont;

        int s = 0;
        int ans = 0;

        for(int e = 0; e < nums.size(); e++) {

            cont[nums[e]]++;

            while(cont.rbegin()->first - cont.begin()->first > limit) {

                cont[nums[s]]--;

                if(cont[nums[s]] == 0) {
                    cont.erase(nums[s]);
                }

                s++;
            }

            ans = max(ans, e - s + 1);
        }

        return ans;
    }
};