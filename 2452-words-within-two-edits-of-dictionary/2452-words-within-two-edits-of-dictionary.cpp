class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(string str:queries){
            bool f=false;
           for(string ch:dictionary){
            int c=0;
            for(int i=0;i<str.length();i++){
                if(str[i]!=ch[i]) c++;
            }
            if(c<=2 && f==false) {ans.push_back(str),f=true;}
           }
        }
        return ans;
    }
};