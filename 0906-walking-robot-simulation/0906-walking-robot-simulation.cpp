class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obs) {
        set<pair<int, int>> st;
        for(auto it: obs) st.insert({it[0], it[1]});

        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x=0, y=0;
        int d = 0, ans=0;

        for(int cmd: commands){
            if(cmd==-1){
                d++;
                if(d==4) d=0;
            } else if(cmd == -2){
                d--;
                if(d==-1) d=3;
            } else{

                for(int i=0; i<cmd; i++){
                    int nx=x+dir[d][0], ny=y+dir[d][1];

                    if(st.find({nx, ny})!=st.end()) break;
                    x=nx, y=ny;
                }
            }

            ans= max(ans, x*x+y*y);
        }


        return ans;
    }
};


// 0, 1 N
// 1, 0 E
// 0, -1 S
// -1, 0 W