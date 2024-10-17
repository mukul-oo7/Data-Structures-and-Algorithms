class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);

        vector<int> next(str.size(), -1);
        stack<char> st;

        for(int i=str.size()-1; i>=0; i--){
            while(!st.empty() && str[st.top()]<str[i]){
                st.pop();
            }

            if(!st.empty()) next[i] = st.top();
            st.push(i);
        }

        for(int i=0; i<str.size(); i++){
            if(next[i]!=-1){
                int nx = next[i];
                while(next[nx]!=-1){
                    nx = next[nx];
                }

                if(str[i]==str[nx]) continue;

                swap(str[i], str[nx]);
                break;
            }
        }
        
        return stoi(str);
    }
};

// 6529458