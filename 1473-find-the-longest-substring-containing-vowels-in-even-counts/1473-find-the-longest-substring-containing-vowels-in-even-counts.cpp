class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> mp{{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};

        int mask=0, ans=0;
        unordered_map<int, int> fre;
        fre[mask]=-1;

        for(int i=0; i<s.size(); i++){
            if(mp.find(s[i])!=mp.end()){
                mask ^= (1<<mp[s[i]]);
            }

            if(fre.find(mask)!=fre.end()){
                ans = max(ans, i-fre[mask]);
            } else{
                fre[mask] = i;
            }
        }

        return ans;
    }
};