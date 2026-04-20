class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int col2=-1,ans=0;
        for(int i=0;i<colors.size();i++){
            if(col2==-1 && colors[i]!=colors[0]){
                col2=i;
            }
            if(colors[i]!=colors[0]){
                ans=max(ans,i);
            }
            if(col2!=-1 && colors[i]!=colors[col2]){
                ans=max(ans,i-col2);
            }
        }
        return ans;
    }
};