class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        for(int i=0;i<n;i++) s+=s[i];
        for(int i=0;i<n;i++) if(s.substr(i,n)==goal) return true;
        return false;
       
    }
};