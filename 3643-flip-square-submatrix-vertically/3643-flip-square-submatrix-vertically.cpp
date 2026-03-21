class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int s=x+k-1;
        for(int i=x;i<x+k;i++){
            for(int j=y;j<y+k;j++){
                swap(grid[i][j],grid[s][j]);
            }
            s--;
            if(i>=s) break;
        }
        return grid;
    }
};