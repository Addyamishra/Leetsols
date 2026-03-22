class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
     vector<int> cont;
     for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat.size();j++){
            cont.push_back(target[i][j]);
        }
     }   
     int ind=0;
     bool ans=true;
     for(int i=0;i<mat.size();i++){
        for(int j=mat.size()-1;j>=0;j--){
            if(cont[ind]!=mat[j][i]) ans=false;
            ind++;
        }
     }
     if(ans)
     return true;
     ind=0;
     ans=true;
     for(int i=mat.size()-1;i>=0;i--){
        for(int j=mat.size()-1;j>=0;j--){
            if(cont[ind++]!=mat[i][j]) ans=false;
        }
     }
     if(ans) return true;
     ans=true;
     ind=0;
     for(int i=mat.size()-1;i>=0;i--){
        for(int j=0;j<mat.size();j++){
          if(cont[ind++]!=mat[j][i]) ans=false;
        }
     }
     return ans || mat==target;
    }
};