class Solution {
public:
    bool checkOnesSegment(string s) {
        int a=0;
        for(int i=1;i<s.length();i++){
            if(s[i]=='0' && s[i-1]=='1')  a++;
            else if(s[i]=='1' && s[i-1]=='0')  a++;
        }
        return a<=1;
    }
};