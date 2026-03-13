class Solution {
public:
    bool check(long long t, int mh, vector<int>& wt){
        long long removed = 0;
        for(long long w : wt){
            long long val = (long long)(sqrt(1 + 8.0 * t / w) - 1) / 2;
            removed += val;
            if(removed >= mh) return true;
        }
        return false;
    }
    long long minNumberOfSeconds(int mh, vector<int>& wt) {
        long long s = 0, e = 1e18;
        long long ans = e;
        while(s <= e){
            long long mid = (s + e) / 2;
            if(check(mid, mh, wt)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};