class Solution {
public:
    int helper(int ind, string &s, unordered_set<string> &st){
        if(ind==s.size()) return 0;

        string str = "";
        int mx = INT_MIN;

        for(int i=ind; i<s.size(); i++){
            str.push_back(s[i]);
            if(st.find(str)==st.end()){
                st.insert(str);
                mx = max(mx, 1+helper(i+1, s, st));
                st.erase(str);
            }
        }
        return mx;
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return helper(0, s, st);
        
    }
};