class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;

        for(auto it: hc){
            pq.push({it, 'h'});
        }

        for(auto it: vc){
            pq.push({it, 'v'});
        }

        long long ans=0, h=1, v=1;

        while(!pq.empty()){
            int cost=pq.top().first;
            int origin=pq.top().second;
            pq.pop();

            if(origin=='h'){
                ans+=h*cost;
                v++;
            } else{
                ans+=v*cost;
                h++;
            }

        }

        return ans;
    }
};