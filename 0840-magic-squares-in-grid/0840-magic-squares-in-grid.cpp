class Solution {
public:
bool check(vector<vector<int>>& cont,int r,int c){
set<int> s({
    cont[r][c],
    cont[r-1][c],
    cont[r-2][c],
    cont[r-1][c-1],
    cont[r-2][c-1],
    cont[r-1][c-2],
    cont[r-2][c-2],
    cont[r][c-1],
    cont[r][c-2]
});
int start=1;
for(auto ind:s){
  if(ind!=start) return false;
  start++;
}
    int a=cont[r-1][c]+cont[r-2][c]+cont[r][c];
    int b=cont[r-1][c-1]+cont[r-2][c-1]+cont[r][c-1];
    int cc=cont[r-1][c-2]+cont[r-2][c-2]+cont[r][c-2];
    int d=cont[r][c-1]+cont[r][c-2]+cont[r][c];
    int e=cont[r-1][c-1]+cont[r-1][c-2]+cont[r-1][c];
    int f=cont[r-2][c-1]+cont[r-2][c-2]+cont[r-2][c];
    int g=cont[r-1][c-1]+cont[r-2][c-2]+cont[r][c]; 
    int h=cont[r-2][c]+cont[r-1][c-1]+cont[r][c-2];

    return a==b && b==cc && cc==d && d==e && e==f && f==g && s.size()==9 && g==h;
}
    int numMagicSquaresInside(vector<vector<int>>& grid) {
      int ans=0;
      for(int i=2;i<grid.size();i++){
        for(int j=2;j<grid[0].size();j++){
            if(check(grid,i,j)) ans++;
        }
      }        
      return ans;
    }
};