class Solution {
public:
    int getLucky(string s, int k) {
        int ans=0;

        for(char ch: s){
            int d = ch-'a'+1;
            while(d>0){
                ans+=d%10;
                d/=10;
            }
        }

        while( --k >0 && ans>9 ){
            int t=0;

            while(ans>0){
                t+=ans%10;
                ans/=10;
            }
            ans=t;
        }

        return ans;
    }
};