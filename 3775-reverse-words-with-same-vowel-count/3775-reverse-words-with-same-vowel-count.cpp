class Solution {
public:
int is(string s){
    int v=0;
    for(char ch:s) if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') v++;
    return v;
}
    string reverseWords(string s) {
        string ans="";
        string frst="",str="";
        vector<string> cont;
        for(char c:s){
            if(c==' ') cont.push_back(str),str="";
            else str+=c;
        }
        cont.push_back(str);
        int v=is(cont[0]);
        ans=cont[0];
        for(int i=1;i<cont.size();i++){
            ans+=" ";
            if(is(cont[i])==v) reverse(cont[i].begin(),cont[i].end());
            ans+=cont[i];
        }
      return ans;
    }
};