class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(),
             [](auto &a, auto &b) { return a[1] < b[1]; });

        vector<int> endt(n), pref(n);
        for (int i = 0; i < n; i++) {
            endt[i] = events[i][1];
            pref[i] = events[i][2];
            if (i) pref[i] = max(pref[i], pref[i - 1]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int idx = lower_bound(endt.begin(), endt.end(), events[i][0]) - endt.begin() - 1;
            if (idx >= 0) ans = max(ans, events[i][2] + pref[idx]);
            else ans = max(ans, events[i][2]);
        }
        return ans;
    }
};
