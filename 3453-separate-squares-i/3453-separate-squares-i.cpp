class Solution {
public:
    bool check(double mid, vector<vector<int>>& squares) {
        double below = 0.0, above = 0.0;

        for (auto &sq : squares) {
            double y = sq[1];
            double side = sq[2];
            double top = y + side;

            if (top <= mid) {
                below += side * side;
            }
            else if (y >= mid) {
                above += side * side;
            }
            else {
                double lowerHeight = mid - y;
                double upperHeight = top - mid;

                below += lowerHeight * side;
                above += upperHeight * side;
            }
        }

        return below >= above;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low = 0.0, high = 1e9;

        for (int i = 0; i < 80; i++) { 
            double mid = (low + high) / 2.0;

            if (check(mid, squares))
                high = mid;
            else
                low = mid;
        }

        return low;
    }
};
