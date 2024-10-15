class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;

        int i=0, j=s.size()-1;

        while(i<j){
            if(s[i]=='0') i++;
            else if(s[j]=='1') j--;
            else{
                ans+=abs(j-i);
                i++;
                j--;
            }
        }

        return ans;
    }
};