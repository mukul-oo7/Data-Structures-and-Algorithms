class Solution {
public:
    int minOperations(int n) {
        int num = n;

        int i=0, ans=0;

        while(i<30){
            if(!(n&(1<<i))){
                i++;
            } else{
                int count = 0;
                while(n&(1<<i)){
                    count++;
                    i++;
                }

                if(count==1) ans++;
                else{
                    ans++;
                    n=n|(1<<i);
                }
            }
        }

        return ans;
    }
};