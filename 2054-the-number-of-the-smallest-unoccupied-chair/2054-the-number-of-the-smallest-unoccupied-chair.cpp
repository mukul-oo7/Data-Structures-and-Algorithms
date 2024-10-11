class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        pair<int, int> frn = {times[targetFriend][0], times[targetFriend][1]};

        sort(times.begin(), times.end());

        int tf;

        for(int i=0; i<times.size(); i++){
            if(frn.first == times[i][0] && frn.second == times[i][1]){
                tf = i;
                break;
            }
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        set<int> chair;

        int currentChair, nextChair = 0;

        for(int i=0; i<=tf; i++){
            while(!pq.empty() && pq.top().first<=times[i][0]){
                chair.insert(pq.top().second);
                pq.pop();
            }

            if(!chair.empty()){
                currentChair = *chair.begin();
                chair.erase(chair.begin());
            } else{
                currentChair = nextChair++;
            }

            pq.push({times[i][1], currentChair});
        }


        return currentChair;
    }
};

