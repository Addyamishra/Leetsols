class Solution {
public:
    bool can(int i,int j,int k,int n,int m){
        int f = k - i + 1;
        f /= 2;
        return j >= f && (m - j - 1) >= f;
    }

    int get(int r1,int c1,int r2,int c2,vector<vector<int>>& cont){
        int sum = 0;
        int mid = (r1 + r2) / 2;
        int d = (r2 - r1) / 2;
        int x = r1, y = c1;
        for(int i=0;i<d;i++) sum += cont[x+i][y-i];
        x = mid; y = c1 - d;
        for(int i=0;i<d;i++) sum += cont[x+i][y+i];
        x = r2; y = c1;
        for(int i=0;i<d;i++) sum += cont[x-i][y+i];
        x = mid; y = c1 + d;
        for(int i=0;i<d;i++) sum += cont[x-i][y-i];

        return sum;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> ans;
        int n = grid.size(), m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                ans.push_back(grid[i][j]); 

                for(int k=i+2;k<n;k+=2){
                    if(can(i,j,k,n,m)){
                        ans.push_back(get(i,j,k,j,grid));
                    }
                }
            }
        }

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        reverse(ans.begin(), ans.end());

        while(ans.size() > 3) ans.pop_back();
        return ans;
    }
};