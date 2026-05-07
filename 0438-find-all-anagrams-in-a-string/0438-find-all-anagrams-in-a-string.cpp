class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> frst(26,0),scnd(26,0),ans;
        for(char ch:p) frst[ch-'a']++;
        int st=0,e=p.length(),n=s.length();
        for(int i=0;i<min(e,n);i++) scnd[s[i]-'a']++;
        while(e<=n){
            if(frst==scnd) ans.push_back(st);
            if(e==n) break;
            scnd[s[e]-'a']++,scnd[s[st]-'a']--,st++,e++;
        }
        return ans;
    }
};