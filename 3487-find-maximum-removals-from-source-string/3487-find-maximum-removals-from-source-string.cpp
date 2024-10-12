class Solution {
public:
    int helper(int i, int j, string &s, string &p, set<int> &st, vector<vector<int>> &dp){
        if(j>=p.size()){
            return distance(lower_bound(st.begin(), st.end(), i), st.end());
        }
        if(i>=s.size()) return -1e5;

        if(dp[i][j]!=-1) return dp[i][j];

        if(st.find(i)!=st.end()){
            if(s[i]==p[j]){
                return dp[i][j] = max(1+helper(i+1, j, s, p, st, dp), helper(i+1, j+1, s, p, st, dp));
            } else{
                return dp[i][j] = 1+helper(i+1, j, s, p, st, dp);
            }
        }
        
        if(s[i]==p[j]){
            return dp[i][j] = helper(i+1, j+1, s, p, st, dp);
        }

        return dp[i][j] = helper(i+1, j, s, p, st, dp);
    }
    int maxRemovals(string source, string pattern, vector<int>& ti) {
        set<int> st;

        for(auto e: ti) st.insert(e);
        vector<vector<int>> dp(source.size(), vector<int>(pattern.size(), -1));

        return helper(0, 0, source, pattern, st, dp);
    }
};