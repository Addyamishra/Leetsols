#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // freq map
        // storing the freq
        // pushing the pairs into pq
        // taking out k freq strings 
        map<string,int> freq;
        for(auto str:words){
            freq[str]++;
        }
        map<int,set<string>> freq_to_string;
        for(auto p:freq){
            //Line 14: Char 23: error: member reference type 'std::pair<const std::basic_string<char>, int>' is not a pointer; did you mean to use '.'?
//    14 |             string s=p->first;
            string s=p.first;
            int f=p.second;
            freq_to_string[f].insert(s);
        }
        vector<vector<string>> current;
        for(auto se:freq_to_string){
            set<string> curr=se.second;
            vector<string> temp(curr.begin(),curr.end());
            current.push_back(temp);
        }
        vector<string> ans;
        for(int i=current.size()-1;i>=0;i--){
             for(string str:current[i]){
                 ans.push_back(str);
                 if(ans.size()==k) return ans;
             } 
        }
        return ans;
    }
};