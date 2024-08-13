class Solution {
private:
    vector<vector<int>> ans;

    void helper(int i, int target, vector<int> &v, vector<int> &cand, vector<vector<int>> &dp){
        if(i>=cand.size()){
            if(target==0){
                ans.push_back(v);
            }

            return;
        }

        int next = upper_bound(cand.begin(), cand.end(), cand[i])-cand.begin();

        if(cand[i]<=target){
            v.push_back(cand[i]);
            helper(i+1, target-cand[i], v, cand, dp);
            v.pop_back();
        }

        helper(next, target, v, cand, dp);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> dp(candidates.size(), vector<int>(target+1, -1));
        vector<int> v;

        helper(0, target, v, candidates, dp);

        return ans;
    }
};