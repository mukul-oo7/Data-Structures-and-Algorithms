class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());

        vector<vector<int>> new_q(queries.size(), vector<int>(2));
        for(int i=0; i<queries.size(); i++) new_q[i] = {queries[i], i};

        sort(new_q.begin(), new_q.end());

        vector<int> res(queries.size(), 0);
        int mx = 0;

        for(int i=0, j=0; i<new_q.size(); i++){

            while(j<items.size() && items[j][0] <= new_q[i][0]){
                mx = max(mx, items[j][1]); 
                j++;
            }

            res[new_q[i][1]] = mx;
        }

        return res;
    }
};