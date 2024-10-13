class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<vector<int>> v;

        for(int i=0; i<nums.size(); i++){
            for(int num: nums[i]){
                v.push_back({num, i});
            }
        }

        sort(v.begin(), v.end());

        unordered_map<int, int> mp;

        int mx = 1e9, mn = 0;

        for(int l=0, r=0; r<v.size(); r++){
            mp[v[r][1]]++;

            while(mp.size()==nums.size() && mp[v[l][1]] > 1){
                mp[v[l][1]]--;
                l++;
            }

            if(mp.size() == nums.size()){
                if(v[r][0]-v[l][0] < mx-mn){
                    mx = v[r][0];
                    mn = v[l][0];
                }
            }
        }

        return {mn, mx};
    }
};
