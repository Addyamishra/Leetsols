class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        set<long long> cont;
        long long sum=0;
        for(long long i=0;i<grid.size();i++){
          for(long long j=0;j<grid[0].size();j++){
            sum+=grid[i][j];
          }
         
          cont.insert(sum);
        }
        if(sum%2==0 && cont.count(sum/2)) return true;
        sum=0;
        set<long long> cont2;
        for(long long i=0;i<grid[0].size();i++){
          for(long long j=0;j<grid.size();j++){
            sum+=grid[j][i];
          }
          cont2.insert(sum);
        }
        if(sum%2==0 && cont2.count(sum/2)) return true;
        return false;
    }
};