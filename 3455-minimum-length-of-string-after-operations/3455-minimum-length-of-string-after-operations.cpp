class Solution {
public:
    int minimumLength(string s) {
        int ans=s.size();
        unordered_map<char, int> mp;
        
        for(auto it: s) mp[it]++;
        
        for(auto it: mp){
            if(it.second==1 || it.second==2) continue;
            if(it.second%2){
                ans-=(it.second-1);
            } else{
                ans-=(it.second-2);
            }
        }
        
        return ans;
    }
};