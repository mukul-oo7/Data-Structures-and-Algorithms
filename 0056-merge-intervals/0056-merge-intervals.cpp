class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        int s = intervals[0][0], e = intervals[0][1];

        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0]<=e){
                e = max(e, intervals[i][1]);
            } else{
                ans.push_back({s, e});
                s=intervals[i][0], e=intervals[i][1];
            }
        }

        ans.push_back({s, e});

        return ans;
    }
};