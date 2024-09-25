class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string, int> mp;

        for(string str: bannedWords) mp[str]++;

        int count = 0;

        for(string str: message){
            if(mp.find(str) != mp.end()) count++;
            if(count>=2) return true;
        }

        return false;
    }
};