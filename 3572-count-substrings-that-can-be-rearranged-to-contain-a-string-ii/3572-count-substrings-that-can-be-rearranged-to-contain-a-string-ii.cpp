class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        unordered_map<char, int> mp, fre;
        int cnt = 0;

        for(char ch: word2){
            mp[ch]++;
            if(mp[ch]==1) cnt++;
        }

        int j=0;
        long long ans = 0;

        for(int i=0; i<word1.size(); i++){
            if(mp.find(word1[i]) != mp.end()){
                fre[word1[i]]++;

                if(fre[word1[i]] == mp[word1[i]]){
                    cnt--;
                }
            }

            while(j<i && (fre.find(word1[j])==fre.end() || fre[word1[j]]>mp[word1[j]])){
                if(fre.find(word1[j]) == fre.end()) j++;
                else{
                    fre[word1[j]]--;
                    j++;
                }
            }

            if(cnt==0){
                ans+=j+1;
            }
        }

        return ans;
    }
};