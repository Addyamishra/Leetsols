class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int count_odd = 0;
        int counttt = 0;
        int prefix = 0;

        while (right < nums.size()) {
            if (nums[right] % 2 != 0) {
                count_odd++;
                prefix = 0;
            }

            while (count_odd == k) {
                if (nums[left] % 2 != 0) count_odd--;
                left++;
                prefix++;
            }

            counttt += prefix;
            right++;
        }

        return counttt;
    }
};