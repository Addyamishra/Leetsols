class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int m = players.size(), n = trainers.size();
        int a=0,b=0,ans=0;
        while(a<m && b<n){
            if(players[a]<=trainers[b]){
                ans++;
                a++;
            }
                b++;
        }
        return ans;
    }
};