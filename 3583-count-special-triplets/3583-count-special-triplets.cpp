class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9+7;
        map<int,int> cont, cont2;
        long long ans = 0;
        long long z = 0;
        for(int i : nums) {
            if(i == 0) {
                ans = (ans + (z * (z - 1) / 2) % MOD) % MOD;
                z++;
            }
            if(i % 2 == 0 && cont2[i/2]) {
                ans = (ans + cont2[i/2]) % MOD;
            }
            cont[i]++;
            if(i != 0 && cont[i*2]) {
                cont2[i] += cont[i*2];
            }
        }
        return ans % MOD;
    }
};
