class Solution {
public:
string ans="";
set<string> cont;
void get(string curr,int n){
    if(curr.length()==n){
        if(cont.count(curr)==0) ans=curr;
        return;
    }
    get(curr+'0',n);
    get(curr+'1',n);
}
    string findDifferentBinaryString(vector<string>& nums) {
        for(string str:nums){
            cont.insert(str);
        }
        get("",nums.size());
        return ans;
    }
};