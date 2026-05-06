class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size(),m=box[0].size();
        vector<vector<int>> cont(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=0;j<m;j++){
             if(box[i][j]=='#') curr++;
             if(((j+1)<m  && box[i][j+1]=='*') || j==(m-1)){
                cont[i][j]=curr;
                curr=0;
             }
             if(box[i][j]=='#') box[i][j]='.';
            }
        }
        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=m-1;j>=0;j--){
               if(cont[i][j]>0) curr=cont[i][j];
               if(curr){
                box[i][j]='#';
                curr--;
               }
            }
        }
        vector<vector<char>> ans;
        for(int i=0;i<m;i++){
            vector<char>temp;
            for(int j=n-1;j>=0;j--){
                temp.push_back(box[j][i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};