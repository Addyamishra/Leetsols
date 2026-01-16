class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1e9 + 7;

        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<long long> hSet, vSet;

        for (int i = 0; i < hFences.size(); i++)
            for (int j = i + 1; j < hFences.size(); j++)
                hSet.insert(hFences[j] - hFences[i]);

        for (int i = 0; i < vFences.size(); i++)
            for (int j = i + 1; j < vFences.size(); j++)
                vSet.insert(vFences[j] - vFences[i]);

        long long maxSide = 0;
        for (auto d : hSet)
            if (vSet.count(d))
                maxSide = max(maxSide, d);

        if (maxSide == 0) return -1;
        return (maxSide * maxSide) % MOD;
    }
};