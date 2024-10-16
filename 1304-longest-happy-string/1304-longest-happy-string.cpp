class Solution {
public:
    void pushOne(string &str, char ch){
        str.push_back(ch);
    }

    void pushTwo(string &str, char ch){
        str.push_back(ch);
        str.push_back(ch);
    }

    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if(a!=0) pq.push({a, 'a'});
        if(b!=0) pq.push({b, 'b'});
        if(c!=0) pq.push({c, 'c'});

        string str = "";

        while(!pq.empty()){
            auto [count, ch] = pq.top();
            pq.pop();

            int i=str.size();

            if(i>=2 && str[i-1]==ch && str[i-2]==ch){
                if(pq.empty()) break;
                else{
                    auto [count2, ch2] = pq.top();
                    pq.pop();

                    str.push_back(ch2);
                    if(count2-1 > 0) pq.push({count2-1, ch2});
                    pq.push({count, ch});
                }
            } else{
                str.push_back(ch);
                if(count-1>0) pq.push({count-1, ch});
            }
        }

        return str;
    }
};