class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return to_string(a)+to_string(b) > to_string(b)+to_string(a);
        });

        string res="";
        for(auto it: nums){
            res+=to_string(it);
        }

        int i=0;
        while(i<res.size() && res[i]=='0') i++;
        res=res.substr(i);

        return res.empty()? "0": res;
    }
};