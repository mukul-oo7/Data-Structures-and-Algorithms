class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> finalSubset(26, 0);

        for(auto str:words2){
            vector<int> subset(26, 0);

            for(char ch: str) subset[ch-'a']++;

            for(int i=0; i<26; i++) finalSubset[i] = max(finalSubset[i], subset[i]);
        }

        vector<string> res;

        for(string str: words1){
            vector<int> subset(26, 0);
            bool isRes = true;

            for(char ch: str) subset[ch-'a']++;

            for(int i=0; i<26; i++){
                if(subset[i]<finalSubset[i]){
                    isRes = false;
                    break;
                }
            }

            if(isRes) res.push_back(str);
        }

        return res;
    }
};