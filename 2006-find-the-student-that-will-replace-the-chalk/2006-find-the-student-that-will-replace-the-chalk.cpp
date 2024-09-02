class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        vector<long long> presum(chalk.size(), 0);
        presum[0]=chalk.front();

        for(int i=1; i<chalk.size(); i++){
            presum[i]+=chalk[i]+presum[i-1];
        }

        k=k%presum.back();

        return upper_bound(presum.begin(), presum.end(), k) - presum.begin();
    }
};
