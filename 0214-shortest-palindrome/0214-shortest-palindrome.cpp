class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.size() == 0) return "";
        long long Mod = 1e9+7, fh = 0, rh = 0, pw = 1, base = 29, idx = 0;

        for(int i=0; i<s.size(); i++){
            char ch = s[i];

            fh = (fh*base + (ch-'a'+1)) % Mod;
            rh = (rh + (ch-'a'+1)*pw) % Mod;
            pw = (pw*base) % Mod;

            if(fh == rh) idx = i;

        }

        string str = s.substr(idx+1);
        reverse(str.begin(), str.end());

        return str+s;
    }
};