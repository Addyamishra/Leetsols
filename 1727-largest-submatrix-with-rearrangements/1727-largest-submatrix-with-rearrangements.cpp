class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
               if(mat[j][i]==0) continue;
               mat[j][i]+=mat[j-1][i];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            multiset<int> cont;
            int c=0;
            for(int j=0;j<m;j++){
            if(mat[i][j]>0) cont.insert(mat[i][j]),c++;
            }
            int ci=0;
            for(int i:cont){
                ans=max(ans,(c-ci)*i);
                ci++;
            }
        }
     return ans;
    }
};