class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> cont;
        map<vector<int>,vector<string>> temp;
        for(auto& str:strs){
            vector<int> s(26,0);
            for(char ch:str){
                s[ch-'a']++;
            }
            temp[s].push_back(str);
        }
        for(auto a:temp) cont.push_back(a.second);
        return cont;
    }
};