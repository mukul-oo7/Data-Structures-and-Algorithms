class Solution {
public:
    void stackPush(string &atom, string &count, stack<pair<string, int>> &st){
        if(atom.size()>0){
            if(count.size()>0){
                st.push({atom, stoi(count)});
            } else{
                st.push({atom, 1});
            }
        }
        atom="";
        count="";
    }
    string countOfAtoms(string formula) {
        stack<pair<string, int>> st;

        formula.push_back('$');

        string atom="";
        string count="";
        for(int i=0; i<formula.size(); i++){
            char ch=formula[i];

            if(ch=='('){
                stackPush(atom, count, st);
                atom=atom+ch;
                count="0";
                stackPush(atom, count, st);
            }
            else if(ch==')'){
                stackPush(atom, count, st);

                int j=i;
                while(j+1<formula.size() && formula[j+1]>='0' && formula[j+1]<='9'){
                    count=count+formula[j+1];
                    j++;
                }
                i=j;

                int c = (count.size()>0)? stoi(count): 1;
                stack<pair<string, int>> tmp;

                while(!st.empty()){
                    if(st.top().first=="("){
                        st.pop();
                        break;
                    }

                    tmp.push({st.top().first, st.top().second*c});
                    st.pop();
                }

                while(!tmp.empty()){
                    st.push({tmp.top().first, tmp.top().second});
                    tmp.pop();
                }
                
            }

            else if((ch>='A' && ch<='Z') || ch=='$'){
                stackPush(atom, count, st);
                atom=ch;
            } else if(ch>='a' && ch <='z'){
                atom=atom+ch;
            } else if(ch>='0' && ch <='9'){
                count=count+ch;
            }
        }

        map<string, int> mp;

        while(!st.empty()){
            // cout << st.top().first << " " << st.top().second << endl;
            mp[st.top().first] += st.top().second;
            st.pop();
        }

        string ans="";

        for(auto it: mp){
            ans+=it.first;
            if(it.second>1){
                ans+=to_string(it.second);
            }
        }

        return ans;
    }
};