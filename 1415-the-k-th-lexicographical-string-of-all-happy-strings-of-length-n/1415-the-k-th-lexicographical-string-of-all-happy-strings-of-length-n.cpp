class Solution {
public:
      vector<string> ans;
    void get(char prev,int ind,int n,string& temp){
        if(ind>=n){
            ans.push_back(temp);
            return;
        }
       for(char ch='a';ch<='c';ch++){
           if(prev==ch) continue;
           temp+=ch;
           get(ch,ind+1,n,temp);
           temp.pop_back();
       }
    }
    string getHappyString(int n, int k) {
     string temp="";
      get('2',0,n,temp);  
      sort(ans.begin(),ans.end());
      return k-1<ans.size()?ans[k-1]:"";
    }
};