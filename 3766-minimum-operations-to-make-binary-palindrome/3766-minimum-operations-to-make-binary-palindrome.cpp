class Solution {
public:
vector<int> re() {
    vector<int> res;

    for (int x = 1; x < 100000; x++) {
        int n = x;
        int rev = 0;
        while (n > 0) {
            rev = (rev << 1) | (n & 1);
            n >>= 1;
        }

        if (rev == x)
            res.push_back(x);
    }

    return res;
}
    vector<int> minOperations(vector<int>& nums) {
        vector<int> pr=re();
        vector<int> ans;
        for(int i:nums){
            int a=INT_MAX;
            for(int j:pr) a=min(a,abs(j-i));
            ans.push_back(a);
        }
        return ans;
    }
};