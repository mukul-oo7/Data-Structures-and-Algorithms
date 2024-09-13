class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for(int i=1; i<arr.size(); i++) arr[i]^=arr[i-1];

        vector<int> res;

        for(auto q: queries){
            if(q[0]==0) res.push_back(arr[q[1]]);
            else res.push_back(arr[q[1]]^arr[q[0]-1]);
        }

        return res;
    }
};