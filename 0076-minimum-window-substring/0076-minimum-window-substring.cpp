class Solution {
public:
    string minWindow(string s, string t) {
        int st = 0, n = s.length(), start = -1;
        int e = 0;
        int len = INT_MAX;
        vector<int> cont(128, 0), temp(128, 0);
        for (char ch : t) cont[ch]++;
        int count = t.size();
        while (e < n) {
            int i = s[e];
            if (cont[i] > 0 && temp[i] < cont[i]) count--;
            temp[i]++;  
            while (count == 0) { 
                if ((e - st + 1) < len) {
                    len = (e - st + 1);
                    start = st;
                }
                temp[s[st]]--;
                if (cont[s[st]] > 0 && temp[s[st]] < cont[s[st]])
                    count++;
                st++;
            }
            e++;
        }

        if (start != -1) return s.substr(start, len);
        return "";
    }
};