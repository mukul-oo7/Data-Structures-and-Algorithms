class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        pair<int, int> frn = {times[targetFriend][0], times[targetFriend][1]};

        sort(times.begin(), times.end());

        int tf;

        for(int i=0; i<times.size(); i++){
            if(frn.first == times[i][0] && frn.second == times[i][1]){
                tf = i;
                break;
            }
        }
        
        vector<int> sit;
        int ans;

        for(int i=0; i<=tf; i++){
            int j;

            for(j=0; j<sit.size(); j++){
                if(sit[j]<=times[i][0]){
                    ans = j;
                    sit[j] = times[i][1];
                    break;
                }
            }

            if(j==sit.size()){
                ans = j;
                sit.push_back(times[i][1]);
            }
        }


        return ans;
    }
};

