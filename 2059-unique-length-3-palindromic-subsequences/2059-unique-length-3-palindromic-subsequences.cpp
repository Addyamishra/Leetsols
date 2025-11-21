class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,int> first, last;
        int n = s.length();
        for (int i = 0; i < n; i++)
            if (!first.count(s[i])) first[s[i]] = i;
        for (int i = n - 1; i >= 0; i--)
            if (!last.count(s[i])) last[s[i]] = i;
        int ans = 0;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (!first.count(ch)) continue;

            int st = first[ch], ee = last[ch];
            if (ee - st < 2) continue;

            vector<int> seen(26, 0);
            int cnt = 0;

            for (int i = st + 1; i < ee; i++) {
                if (!seen[s[i] - 'a']) {
                    seen[s[i] - 'a'] = 1;
                    cnt++;
                }
            }

            ans += cnt;
        }

        return ans;
    }
};
