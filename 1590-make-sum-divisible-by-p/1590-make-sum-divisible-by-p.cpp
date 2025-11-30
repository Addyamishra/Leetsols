class Solution {
public:
    typedef long long ll;
    int minSubarray(vector<int>& nums, int p) {
        ll ts = 0;
        for (int i : nums) ts = (ts + i) % p;
        if (ts == 0) return 0;
        ll cs = 0;
        ll ans = nums.size();
        map<ll, ll> cont;
        cont[0] = -1;  
        for (ll i = 0; i < nums.size(); i++) {
            cs = (cs + nums[i]) % p;
            ll need = (cs - ts + p) % p;
            if (cont.count(need)) {
                ans = min(ans, i - cont[need]);
            }
            cont[cs] = i;
        }
        return ans == nums.size() ? -1 : ans;
    }
};
