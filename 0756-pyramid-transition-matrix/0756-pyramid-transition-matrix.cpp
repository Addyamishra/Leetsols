class Solution {
public:
    map<pair<char,char>, vector<char>> cont;
    unordered_map<string, bool> memo;

    bool dfs(string curr) {
        if (curr.size() == 1) return true;
        if (memo.count(curr)) return memo[curr];

        int n = curr.size();
        vector<string> nexts;
        build(curr, 0, "", nexts);

        for (string &nx : nexts) {
            if (dfs(nx)) return memo[curr] = true;
        }
        return memo[curr] = false;
    }

    void build(string &curr, int i, string path, vector<string> &nexts) {
        if (i == curr.size() - 1) {
            nexts.push_back(path);
            return;
        }

        auto key = make_pair(curr[i], curr[i+1]);
        if (!cont.count(key)) return;

        for (char ch : cont[key]) {
            build(curr, i + 1, path + ch, nexts);
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed) {
            cont[{s[0], s[1]}].push_back(s[2]);
        }
        return dfs(bottom);
    }
};
