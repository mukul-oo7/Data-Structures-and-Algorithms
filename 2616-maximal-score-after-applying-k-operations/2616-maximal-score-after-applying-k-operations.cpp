class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;

        priority_queue<int> pq;

        for(auto num: nums) pq.push(num);

        for(int i=0; i<k && !pq.empty(); i++){
            int num = pq.top();
            pq.pop();

            ans+=num;
            int new_num = ceil(num/3.0);
            if(new_num!=0) pq.push(new_num);
        }

        return ans;
    }
};