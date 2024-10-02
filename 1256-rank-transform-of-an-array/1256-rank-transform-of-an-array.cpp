class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans(arr.size());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i=0; i<arr.size(); i++) pq.push({arr[i], i});

        int rank=0, pre=-1;

        while(!pq.empty()){
            int pos = pq.top().second;
            pq.pop();

            if(pre!=arr[pos]) ans[pos] = ++rank;
            else ans[pos] = rank;

            pre = arr[pos];
        }

        return ans;
    }
};