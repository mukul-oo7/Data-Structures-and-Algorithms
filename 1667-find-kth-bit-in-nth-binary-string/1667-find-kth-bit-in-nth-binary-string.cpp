class Solution {
public:
    char findKthBit(int n, int k) {
        if(k==1) return '0';
        int count = 0, pos = k;

        while(pos != 1){
            if((pos&(pos-1))==0){
                count++;
                break;
            }
            int mid;
            for(int i=0; i<21; i++){
                if(pos&(1<<i)) mid = (1<<i);
            }

            pos = mid-abs(mid-pos);
            count++;
        }

        if(count%2) return '1';
        return '0';
    }
};