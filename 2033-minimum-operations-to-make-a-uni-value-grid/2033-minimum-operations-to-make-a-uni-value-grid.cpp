class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
       vector<int>cont;
       for(auto ind:grid){
        for(int i:ind) cont.push_back(i);
       } 
       int ans=0;
       sort(cont.begin(),cont.end());
       int v=cont[cont.size()/2];
       for(int i:cont){
        int diff=abs(i-v);
        if(diff%x!=0) return -1;
        ans+=(diff/x);
       }
       return ans;
    }
};