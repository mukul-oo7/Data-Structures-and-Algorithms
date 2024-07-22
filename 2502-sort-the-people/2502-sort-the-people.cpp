class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

        for(int i=0; i<heights.size(); i++){
            pq.push({heights[i], i});
        }

        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(names[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};