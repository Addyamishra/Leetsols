class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        return multiset<char>{s1[0], s1[2]} == multiset<char>{s2[0], s2[2]} &&
               multiset<char>{s1[1], s1[3]} == multiset<char>{s2[1], s2[3]};
    }
};