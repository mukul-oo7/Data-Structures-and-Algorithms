class Solution {
public:
    int lcs(vector<pair<int, int>>& arr) {
        if (arr.empty()) return 0;

        vector<pair<int, int>> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end(),
            [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.first != b.first) return a.first < b.first;
                return a.second > b.second;
            });

        vector<int> lis;
        for (auto& p : sorted_arr) {
            auto it = lower_bound(lis.begin(), lis.end(), p.second);
            if (it == lis.end()) {
                lis.push_back(p.second);
            } else {
                *it = p.second;
            }
        }

        return lis.size();
    }


    int maxPathLength(vector<vector<int>>& cd, int k) {
        int n = cd.size();
        int x = cd[k][0], y = cd[k][1];

        vector<pair<int, int>> left, right;
        for (int i = 0; i < n; i++) {
            if (cd[i][0] < x && cd[i][1] < y) left.push_back({cd[i][0], cd[i][1]});
            if (cd[i][0] > x && cd[i][1] > y) right.push_back({cd[i][0], cd[i][1]});
        }

        int l = lcs(left), r = lcs(right);

        return l+r+1;
    }
};