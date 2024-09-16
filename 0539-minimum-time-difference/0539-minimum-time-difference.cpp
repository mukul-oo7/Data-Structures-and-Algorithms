class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;

        for(string str: timePoints){
            int hour = stoi(str.substr(0, 2));
            int min = stoi(str.substr(3));

            time.push_back(hour*60+min);
        }

        sort(time.begin(), time.end());

        int ans = INT_MAX;

        for(int i=1; i<time.size(); i++){
            ans = min(ans, time[i]-time[i-1]);
        }

        return min(ans, 24*60-time.back()+time.front());
    }
};