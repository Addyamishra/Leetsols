class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        int n=strs[0].length();
        for(int i=0;i<n;i++){
            char prev=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(prev>strs[j][i]){
                    ans++;
                    break;
                }
                prev=strs[j][i];
            }
        }
        return ans;
    }
};