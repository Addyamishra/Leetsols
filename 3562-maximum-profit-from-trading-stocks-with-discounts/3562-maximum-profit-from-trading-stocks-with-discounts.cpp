class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> G(n);
        for (auto& edge : hierarchy) {
            G[edge[0] - 1].push_back(edge[1] - 1);
        }
        vector T1(n, vector<int>(budget + 1, -1));
        vector T2(n, vector<int>(budget + 1, -1)); 
        function<void(int)> dfs = [&](int u) {
            vector<int> P1(budget + 1, 0), P2(budget + 1, 0); 
            for (auto& v : G[u]) {
                dfs(v);
                vector<int> tmp1(budget + 1, 0), tmp2(budget + 1, 0);
                for (int b1 = 0; b1 <= budget; b1++) {
                    for (int b2 = 0; b2 <= budget - b1; b2++) {
                        tmp1[b1 + b2] = max(tmp1[b1 + b2], P1[b1] + T1[v][b2]);
                        tmp2[b1 + b2] = max(tmp2[b1 + b2], P2[b1] + T2[v][b2]);
                    }
                }
                P1 = tmp1;
                P2 = tmp2;
            }
            // don't buy
            for (int i = 0; i <= budget; i++) {
                T1[u][i] = T2[u][i] = P1[i];
            }
            for (int i = present[u]; i <= budget; i++) {
                T1[u][i] = max(T1[u][i], (future[u] - present[u]) + P2[i - present[u]]);
            }
            int buyPrice = present[u] / 2;
            for (int i = buyPrice; i <= budget; i++) {
                T2[u][i] = max(T2[u][i], (future[u] - buyPrice) + P2[i - buyPrice]);
            }
        };
        dfs(0);
        return T1[0][budget];
    }
};