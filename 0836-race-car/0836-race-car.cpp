class Solution {
public:
    int racecar(int target) {
        queue<vector<int>> q;
        q.push({0, 1, 0});

        while(!q.empty()){
            int pos = q.front()[0];
            int speed = q.front()[1];
            int count = q.front()[2];
            q.pop();

            if(pos == target) return count;

            if(abs(pos)>2*target) continue;

            q.push({pos+speed, speed*2, count+1});
            
            if(pos+speed > target && speed > 0) q.push({pos, -1, count+1});
            else if(pos+speed < target && speed<0) q.push({pos, 1, count+1});
        }

        return 0;
    }
};