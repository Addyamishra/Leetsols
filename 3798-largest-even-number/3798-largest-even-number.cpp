class Solution {
public:
    string largestEven(string s) {
        string ans="";
        reverse(s.begin(),s.end());
        for(char ch:s){
            if(ch=='2' && ans=="") ans="2";
            else if(ans!="") ans=ch+ans;
        }
        return ans;
    }
};