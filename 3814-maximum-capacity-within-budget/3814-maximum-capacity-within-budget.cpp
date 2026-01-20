class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<int> dp(budget, 0);
        int mx = 0;
        int n = costs.size();
        vector<pair<int,int>> items;
        for (int i = 0; i < n; i++) {
            items.push_back({costs[i], capacity[i]});
        }
        sort(items.begin(), items.end());
        for (auto &[cost, cap] : items) {
            if (cost >= budget) break;
            mx = max(mx, cap);
            if (cost + cost < budget) {
                mx = max(mx, dp[cost] + cap);
            }

            dp[cost] = max(dp[cost], cap);
        }
        vector<int> mxs(budget / 2, 0);
        for (int i = 0; i < (int)mxs.size(); i++) {
            if (i == 0) mxs[i] = dp[i];
            else mxs[i] = max(mxs[i - 1], dp[i]);
        }
        for (int i = budget - 1; i > 0; i--) {
            if (dp[i] == 0) continue;
            int j = min(budget - i - 1, i - 1);
            if (j >= 0)
                mx = max(mx, dp[i] + mxs[j]);
        }

        return mx;
    }
};
