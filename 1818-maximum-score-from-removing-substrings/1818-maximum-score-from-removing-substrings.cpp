class Solution {
public:
    int ab(string &str, int x){
        stack<char> st;
        int ans=0;

        for(int i=0; i<str.size(); i++){
            if(str[i]=='b' && !st.empty() && st.top()=='a'){
                ans+=x;
                st.pop();
            } else{
                st.push(str[i]);
            }
        }

        string s = "";
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(), s.end());
        str = s;

        return ans;
    }

    int ba(string &str, int y){
        stack<char> st;
        int ans=0;

        for(int i=0; i<str.size(); i++){
            if(str[i]=='a' && !st.empty() && st.top()=='b'){
                ans+=y;
                st.pop();
            } else{
                st.push(str[i]);
            }
        }

        string s = "";
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(), s.end());
        str = s;

        return ans;
    }
    int maximumGain(string s, int x, int y) {
        int ans=0;

        if(x>y){
            ans+=ab(s, x);
            ans+=ba(s, y);
        } else{
            ans+=ba(s, y);
            ans+=ab(s, x);
        }

        return ans;
    }
};