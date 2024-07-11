class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for(int i=0; i<s.size(); i++){
            if(s[i]==')'){
                string str="";
                while(st.top()!='('){
                    str.push_back(st.top());
                    st.pop();
                }
                st.pop();

                for(auto ch: str) st.push(ch);
            } else{
                st.push(s[i]);
            }
        }

        string ans = "";

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};