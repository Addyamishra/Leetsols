class Solution {
public:
int n,m;
vector<vector<vector<int>>> dp;
int get(int r,int c,int k,vector<vector<int>>& cont){
    if(r==n || c==m || k<0) return INT_MIN;
    if(r==n-1 && c==m-1){
        if(cont[r][c]!=0) k--;
        if(k>=0) return cont[r][c];
        else return INT_MIN;
    }
    if(dp[r][c][k]!=-1) return dp[r][c][k];
    int frk=cont[r][c]==0?0:1;
    int right=get(r,c+1,k-frk,cont);
    int left=get(r+1,c,k-frk,cont);
    return  dp[r][c][k]=cont[r][c]+max(left,right);
}
    int maxPathScore(vector<vector<int>>& grid, int k) {
         n=grid.size(),m=grid[0].size();
        if(k>400) k=400;
        dp.resize(n+1,vector<vector<int>>(m+1,vector<int>(401,-1)));
        int ans=get(0,0,k,grid);
        return( ans<0)?-1:ans;
    }
};