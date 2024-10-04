class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = accumulate(skill.begin(), skill.end(), 0LL);
        unordered_map<int, int> mp;
        for(int sk: skill) mp[sk]++;
        int n=skill.size();

        if(sum%(n/2)!=0) return -1;

        int target = sum*2/n;

        long long ans = 0;

        for(auto &[num, count]: mp){
            if(mp[target-num]!=mp[num]) return -1;
            
            ans+=mp[num]*1LL*num*(target-num);
        }

        return ans/2;
    }
};