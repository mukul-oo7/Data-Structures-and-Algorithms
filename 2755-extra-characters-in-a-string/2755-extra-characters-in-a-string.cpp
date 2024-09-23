class Solution {
public:
    int helper(int ind, string &s, vector<string>& dic, vector<int> &dp){
        if(ind==s.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        dp[ind] = 1+helper(ind+1, s, dic, dp);

        for(auto str: dic){
            if(s.compare(ind, str.size(), str)==0){
                dp[ind] = min(dp[ind], helper(ind+str.size(), s, dic, dp));
            }
        }

        return dp[ind];
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size(), -1);
        return helper(0, s, dictionary, dp);
    }
};