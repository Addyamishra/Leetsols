class Robot {
    public:
        int pos;
        int health;
        int idx;
        char dir;

        Robot(int p, int h, int i, char d) {
            pos = p;
            health = h;
            idx = i;
            dir = d;
        }
    };

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        int n = p.size();
        vector<Robot*> robots;
        for (int i = 0; i < n; i++) {
            robots.push_back(new Robot(p[i], h[i], i, d[i]));
        }
        sort(robots.begin(), robots.end(), [](Robot* a, Robot* b) {
            return a->pos < b->pos;
        });

        stack<int> st;

        for (int i = 0; i < n; i++) {
            bool destroyed = false;
            while (!st.empty() && (robots[st.top()]->dir == 'R' && robots[i]->dir == 'L')){          
                int j = st.top();
                st.pop();
                if (robots[j]->health > robots[i]->health) { 
                    robots[j]->health -= 1;
                    st.push(j);
                    destroyed = true;
                    break;
                } 
                else if (robots[j]->health < robots[i]->health) {
                    robots[i]->health -= 1;
                } 
                else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(i);
            }
        }

        vector<int> res(n, -1);
        while (!st.empty()) {
            int i = st.top(); 
            st.pop();
            res[robots[i]->idx] = robots[i]->health;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (res[i] != -1) ans.push_back(res[i]);
        }

        for (auto r : robots) delete r;
        return ans;
    }
};