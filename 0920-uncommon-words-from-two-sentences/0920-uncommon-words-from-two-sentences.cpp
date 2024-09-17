class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        string str = "";

        for(char ch: s1){
            if(ch == ' '){
                mp[str]++;
                str = "";
            }
            else str.push_back(ch);
        }
        mp[str]++;
        str = "";

        for(char ch: s2){
            if(ch == ' '){
                mp[str]++;
                str = "";
            } else{
                str.push_back(ch);
            }
        }
        mp[str]++;

        vector<string> res;

        for(auto &[str, count]: mp){
            if(count == 1) res.push_back(str);
        }

        return res;
    }
};