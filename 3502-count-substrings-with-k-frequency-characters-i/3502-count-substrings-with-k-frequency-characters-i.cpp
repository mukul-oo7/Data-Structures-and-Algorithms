class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        unordered_map<int, int> mp;

        int ans = 0;
        for(int i=0, j=0; i<s.size(); i++){
            mp[s[i]]++;
            
            while(mp[s[i]] == k){
                mp[s[j++]]--;
            }
            ans+=j;
        }

        return ans;
    }
};