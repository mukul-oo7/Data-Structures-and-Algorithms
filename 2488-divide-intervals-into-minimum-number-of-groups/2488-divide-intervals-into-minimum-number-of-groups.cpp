class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int ans = 0;
        multiset<int> ms;

        for(int i=0; i<intervals.size(); i++){
            int s = intervals[i][0], e = intervals[i][1];

            // auto it = ms.lower_bound(s);
            // int d = distance(it, ms.end());
            // ans = max(ans, d+1);
            // ms.insert(e);

            while(!ms.empty() && *ms.begin()<s){
                ms.erase(ms.begin());
            }

            ms.insert(e);

            ans = max(ans, (int)ms.size());
        }

        return ans;
    }
};