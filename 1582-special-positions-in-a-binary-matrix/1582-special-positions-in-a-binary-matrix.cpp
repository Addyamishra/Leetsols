class Solution {
public:
int check(vector<vector<int>>& mat,int c,int r){
    int o=0;
    for(int i=0;i<mat.size();i++) if(mat[i][c]==1) o++;
      for(int i=0;i<mat[0].size();i++) if(mat[r][i]==1) o++;
      return o==2;
}
    int numSpecial(vector<vector<int>>& mat) {
        int ans=0;
        for(int i=0;i<mat[0].size();i++){
            for(int j=0;j<mat.size();j++){
              if(mat[j][i]==1 && check(mat,i,j)) ans++;
            }
        }
        return ans;
    }
};