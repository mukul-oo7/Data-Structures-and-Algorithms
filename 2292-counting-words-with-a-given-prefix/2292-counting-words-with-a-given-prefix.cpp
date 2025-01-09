class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;

        for(string &str: words){
            bool isPref = str.size() >= pref.size() ? true: false;

            for(int i=0; i<pref.size() && i<str.size(); i++){
                if(pref[i]!=str[i]){
                    isPref = false;
                    break;
                }
            }

            if(isPref) ans++;
        }

        return ans;
    }
};