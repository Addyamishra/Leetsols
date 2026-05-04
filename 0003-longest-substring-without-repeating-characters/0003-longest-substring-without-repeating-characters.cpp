class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cont(129,0);
        int st=0,e=0,n=s.length(),ans=0;
        while(e<n){
          cont[s[e]]++;
          while(cont[s[e]]>1){
            cont[s[st]]--;
            st++;
          }
          ans=max(ans,e-st+1);
          e++;
        }
        return ans;
    }
};