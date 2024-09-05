class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();

        long long sum =0;
        for(int roll: rolls) sum+=roll;
        long long target = mean*(n+m)-sum;

        if(target > 6*n || target<n) return {};
        int div = target/n;
        int rem = target%n;

        vector<int> ans(n, div);
        for(int i=0; i<n && rem>0; i++){
            ans[i]++;
            rem--;
        }

        return ans;
    }
};

