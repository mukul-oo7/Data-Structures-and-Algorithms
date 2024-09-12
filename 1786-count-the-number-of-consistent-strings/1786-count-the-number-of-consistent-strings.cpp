class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> allow(26, false);

        for(char ch: allowed) allow[ch-'a'] = true;
        int ans=0;

        for(auto str: words){
            ans++;
            for(auto ch: str){
                if(!allow[ch-'a']){
                    ans--;
                    break;
                }
            }
        }

        return ans;
    }
};