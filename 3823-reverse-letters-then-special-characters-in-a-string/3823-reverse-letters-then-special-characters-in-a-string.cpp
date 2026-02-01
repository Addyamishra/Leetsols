class Solution {
public:
    string reverseByType(string s) {
        int n = s.length();

        int i = n - 1;   
        int j = n - 1;  
        int c = 0;

        string ans = "";

        while (ans.length() != s.length()) {

            while (i >= 0 && !(s[i] >= 'a' && s[i] <= 'z')) {
                i--;
            }

            while (j >= 0 && (s[j] >= 'a' && s[j] <= 'z')) {
                j--;
            }
            if (s[c] >= 'a' && s[c] <= 'z') {
                ans += s[i];
                i--;
            } else {
                ans += s[j];
                j--;
            }

            c++;
        }

        return ans;
    }
};
