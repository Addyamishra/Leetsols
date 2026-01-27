class Solution {
public:
map<int,vector<pair<int,int>>> cont;
int N;
int get() {
    int n = cont.size();
    vector<int> ans(N, INT_MAX);
    ans[0] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, 0});

    while (!q.empty()) {
        auto [dist, u] = q.top();
        q.pop();
        if (dist > ans[u]) continue;

        for (auto &[v, w] : cont[u]) {
            if (ans[v] > dist + w) {
                ans[v] = dist + w;
                q.push({ans[v], v});
            }
        }
    }

    return ans[N - 1]==INT_MAX?-1:ans[N-1];
}

    int minCost(int n, vector<vector<int>>& edges) {
        N=n;
        for(auto c:edges){
            cont[c[0]].push_back({c[1],c[2]});
            cont[c[1]].push_back({c[0],c[2]*2});
        }
        return get();
    }
};