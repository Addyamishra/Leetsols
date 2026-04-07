class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obs) {
        int mo=1,r=0,c=0;
        int ans=0;
        set<vector<int>> cont;
        for(auto ind:obs){
            cont.insert(ind);
        }
        for(int i:commands){
            if(i==-2){
                if(mo==1) mo=4;
                else if(mo==2) mo=1;
                else if(mo==3) mo=2;
                else if(mo==4) mo=3;
            }
            else if(i==-1){
                if(mo==1) mo=2;
                else if(mo==2) mo=3;
                else if(mo==3) mo=4;
                else if(mo==4) mo=1;
            }
            else{
                if(mo==1){
                   for(int k=0;k<i;k++) {if(cont.count({r,c+1})) break; else c++;}
                }
                if(mo==2){
                    for(int k=0;k<i;k++) {if(cont.count({r+1,c})) break; else r++;}
                }
                if(mo==3){
                   for(int k=0;k<i;k++) {if(cont.count({r,c-1})) break; else c--;}
                }
                if(mo==4){
                    for(int k=0;k<i;k++) {if(cont.count({r-1,c})) break; else r--;}
                }
            }
            ans=max(ans,r*r+c*c);
            // return ans;
        }
        return ans;
    }
};