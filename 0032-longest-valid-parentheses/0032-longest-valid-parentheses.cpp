class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st1, st2;
        vector<int> v;
        int n=s.size();

        for(int i=0; i<n; i++){
            if(s[i]=='(') st1.push(i);
            else if(!st1.empty()) st1.pop();
            else st2.push(i);
        }
        while(!st1.empty()){
            v.push_back(st1.top());
            st1.pop();
        }

        while(!st2.empty()){
            v.push_back(st2.top());
            st2.pop();
        }

        sort(v.begin(), v.end());
        
        if(v.size() == 0) return n;
        
        int ans=max(v.front(), n-v.back()-1);
        
        for(int i=1; i<v.size(); i++){
            ans = max(ans, v[i]-v[i-1]-1);
        }

        return ans;
    }
};