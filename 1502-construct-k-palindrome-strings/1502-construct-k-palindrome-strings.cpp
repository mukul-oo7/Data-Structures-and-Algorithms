class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> fre(26, 0);

        for(char ch: s) fre[ch-'a']++;

        int odd = 0;
        for(int ele: fre) if(ele%2) odd++;

        return odd <= k && s.size()>=k;
    }
};