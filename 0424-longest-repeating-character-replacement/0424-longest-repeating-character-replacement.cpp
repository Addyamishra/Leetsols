class Solution {
public:
    int get(string str,char ch,int k){
        int c=0,s=0,e=0,ans=0;
        while(e<str.length()){
            if(str[e]==ch) c++;
             while((e-s+1-c)>k){
             if(str[s]==ch) c--;
             s++;
            }
            ans=max(ans,e-s+1),e++;
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
     int ans=0;
     for(char ch='A';ch<='Z';ch++) ans=max(ans,get(s,ch,k));
     return ans;
    }
};