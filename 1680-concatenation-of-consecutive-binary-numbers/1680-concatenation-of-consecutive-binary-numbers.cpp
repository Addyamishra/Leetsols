class Solution {
public:
    int concatenatedBinary(int n) {
        vector<int> cont;

        int st = 0;

        for(int i = n; i >= 1; i--){
            int val = i;
            int bits = 32 - __builtin_clz(i);

            for(int j = 0; j < bits; j++){
                if(val & 1) cont.push_back(st);
                val >>= 1;
                st++;
            }
        }

        long long ans = 0;
        long long p = 1;

        int idx = 0;

        const long long MOD = 1e9+7;

        if(!cont.empty() && cont[0] == 0){
            ans = 1;
            idx = 1;
        }

        for(int i = 1; i <= st; i++){
            p = (p * 2) % MOD;

            if(idx < (int)cont.size() && cont[idx] == i){
                ans = (ans + p) % MOD;
                idx++;
            }
        }

        return (int)ans;
    }
};