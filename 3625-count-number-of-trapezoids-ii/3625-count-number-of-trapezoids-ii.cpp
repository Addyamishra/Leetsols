class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n=points.size();
        int result=0;
        unordered_map<float,vector<float>> slopeIntercept;
        unordered_map<int,vector<float>> midPoints;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                int dx=(x2-x1);
                int dy=(y2-y1);
                float slope,intercept;
                if(x2==x1){
                    slope=1e9+7;
                    intercept=x1;
                    slopeIntercept[slope].push_back(intercept);
                }
                else{
                    slope=(float)dy/dx;
                    intercept=(float)(y1*dx-x1*dy)/dx;
                    slopeIntercept[slope].push_back(intercept);
                }
                int midPontKey=(x1+x2)*10000+(y1+y2);
                midPoints[midPontKey].push_back(slope);
            }
        }

        for(auto &it:slopeIntercept){
            map<float,int> mp;
            for(auto intercept:it.second){
                mp[intercept]++;
            }
            int prevLines=0;
            for(auto &line:mp){
                int cnt=line.second;
                result+=cnt*prevLines;
                prevLines+=cnt;
            }
        }

        for(auto &it:midPoints){
            map<float,int> mp;
            for(auto slope:it.second){
                mp[slope]++;
            }
            int prevLines=0;
            for(auto &line:mp){
                int cnt=line.second;
                result-=cnt*prevLines;
                prevLines+=cnt;
            }
        }

        return result;
    }
};