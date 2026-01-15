class Solution {
public:
    static inline int streakcount(vector<int>& arr, int stop) {
        sort(arr.begin(), arr.end());
        int maxstreak = 0, n = arr.size();
        for (int i = 0; i < n && maxstreak < stop; i++) {
            int streak = 0;
            for (int v = arr[i] + 1; i + 1 < n && arr[i + 1] == v; i++) {
                streak++;
                v++;
            }
            maxstreak = max(maxstreak, streak);
        }
        return maxstreak;
    }
    static int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h = streakcount(hBars, 100);
        int v = streakcount(vBars, h);
        int side = min(h, v) + 2;
        return side * side;
    }
};