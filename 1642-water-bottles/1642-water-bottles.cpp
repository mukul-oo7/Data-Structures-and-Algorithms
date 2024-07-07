class Solution {
public:
    int numWaterBottles(int bottle, int exch) {
        int ans=bottle;
        int empty=bottle;

        while(bottle/exch>0){
            int b = bottle/exch;
            ans+=b;
            bottle=bottle%exch+b;
        }

        return ans;
    }
};