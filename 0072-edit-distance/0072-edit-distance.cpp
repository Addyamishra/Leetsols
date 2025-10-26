class Solution {
public:
int get(int i,int j,string frst,string scnd){
  if(j>=scnd.length()) return frst.length()-i;
  if(i>=frst.length()) return scnd.length()-j;
  if(frst[i]==scnd[j]) return get(i+1,j+1,frst,scnd);
  else{
    return 1+min({get(i,j+1,frst,scnd),get(i+1,j,frst,scnd),get(i+1,j+1,frst,scnd)});
  }
}
    int minDistance(string word1, string word2) {
        // return get(0,0,word1,word2);
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> cont(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) cont[i][0]=i;
        for(int i=0;i<=m;i++) cont[0][i]=i;
        for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]){
                    cont[i][j]=cont[i-1][j-1];
            }
            else{
              cont[i][j]=1+min({cont[i-1][j],cont[i][j-1],cont[i-1][j-1]});
            }
          }
        }
        return cont[n][m];
    }
};