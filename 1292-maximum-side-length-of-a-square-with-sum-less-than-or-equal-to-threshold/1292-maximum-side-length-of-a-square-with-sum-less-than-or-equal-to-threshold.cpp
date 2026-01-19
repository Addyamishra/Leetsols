class Solution {
public:
int get(int r,int c,vector<vector<int>>& cont,int thresh){
     int cr=r;
     int cc=c;
     int ans=0;
     while(cr>=0 && cc>=0){
        cr--;
        cc--;
        int lft=cc>=0?cont[r][cc]:0;
        int rt=cr>=0?cont[cr][c]:0;
        int ext=(cr>=0 && cc>=0 )?cont[cr][cc]:0;
        if(cont[r][c]-lft-rt+ext<=thresh) ans=max(ans,r-cr);
     }
     return ans;
}
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        for(int i=0;i<mat.size();i++){
            for(int j=1;j<mat[0].size();j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        for(int i=0;i<mat[0].size();i++){
            for(int j=1;j<mat.size();j++){
                mat[j][i]+=mat[j-1][i];
            }
        }
        int ans=0;
      for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            ans=max(ans,get(i,j,mat,threshold));
        }
      }
      return ans;
    }
};