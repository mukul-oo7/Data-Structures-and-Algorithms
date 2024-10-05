class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp1, mp2;

        for(char ch: s1) mp1[ch]++;

        int j=0;

        for(int i=0; i<s2.size(); i++){
            char ch = s2[i];
            if(mp1.find(ch)==mp1.end()){
                j=i+1;
                mp2.clear();
                continue;
            }

            mp2[ch]++;

            while(mp2[ch]>mp1[ch]){
                mp2[s2[j]]--;
                j++;
            }

            bool flag = true;
            for(auto &[ch, count]: mp1){
                if(count != mp2[ch]){
                    flag = false;
                    break;
                }
            }

            if(flag) return true;

        }

        return false;
    }
};