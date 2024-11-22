class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;

        for(auto v: matrix){
            string rev="", str="";

            for(int i=0; i<v.size(); i++){
                rev.push_back((v[i]==0)?1:0);
                str.push_back((v[i]==0)?0:1);
            }

            mp[rev]++;
            mp[str]++;
        }

        int ans = 0;

        for(auto [s, c]: mp) ans = max(ans, c);

        return ans;
    }
};