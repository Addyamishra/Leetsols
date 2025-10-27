class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        int prev=-1;
        for(string str:bank){
          int o=0;
          for(char ch:str) if(ch=='1') o++;
          if(prev>0 && o>0){ ans+=(prev*o); prev=o;}
          if(prev==-1 && o>0) prev=o;
        }
        return ans;
    }
};