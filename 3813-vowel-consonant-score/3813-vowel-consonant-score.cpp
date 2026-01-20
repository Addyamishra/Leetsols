class Solution {
public:
bool isd(char c){
    for(char ch='0';ch<='9';ch++) if(ch==c) return true;
    return false;
}
bool isv(char c){
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}
    int vowelConsonantScore(string s) {
        int c=0,v=0;
        for(char ch:s){
            if(ch==' ' || isd(ch)) continue;
            else if(isv(ch)) v++;
            else c++;
        }
        return c>0?v/c:0;
    }
};