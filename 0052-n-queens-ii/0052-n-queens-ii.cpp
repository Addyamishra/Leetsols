class Solution {
public:
int a;
bool safe(vector<vector<int>>&cont,int r,int c){
    int tr=r,tc=c;
    while(tr>=0 && tc>=0){
        if(cont[tr][tc]==1) return false;
        tr--;
        tc--;
    }
    tr=r,tc=c;
    while(tr>=0 && tc<a){
         if(cont[tr][tc]==1) return false;
         tr--;
         tc++;
    }
    for(int i=0;i<a;i++){
        if(cont[i][c]) return false;
    }
    return true;
}
int get(int row,vector<vector<int>>& cont){
    if(row==a) return 1;
    int ans=0;
    for(int i=0;i<a;i++){
        if(safe(cont,row,i)){
            cont[row][i]=1;
            ans+=get(row+1,cont);
            cont[row][i]=0;
        }
    }
    return ans;
}
    int totalNQueens(int n) {
        a=n;
        vector<vector<int>>cont(n,vector<int>(n,0));
    return get(0,cont);
    }
};