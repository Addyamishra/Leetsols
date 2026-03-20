class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m-k+1, vector<int> (n-k+1));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                vector<int> temp;

                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        temp.push_back(grid[x][y]);
                    }
                }
                sort(temp.begin(), temp.end());
                int ans = INT_MAX;

                for (int i = 1; i < temp.size(); i++) {
                    if (temp[i] == temp[i-1]) continue;

                    ans = min(ans, abs(temp[i] - temp[i-1]));
                }
                if (ans != INT_MAX) result[i][j] = ans;
            }
        }
        return result;
    }
};