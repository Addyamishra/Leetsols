#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
       int n = nums.size();
        vector<int> res(n);
        
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int minAns = INT_MAX;
            bool found = false;
            
            for (int b = 0; b <= 30; b++) {
                if ((num >> b) & 1) {
                    int cand = num & ~(1 << b);
                    
                    if (cand >= 0) {
                        if ((cand | (cand + 1)) == num) {
                            if (cand < minAns) {
                                minAns = cand;
                                found = true;
                            }
                        }
                    }
                }
            }
            
            res[i] = found ? minAns : -1;
        }
        
        return res;
    }
};