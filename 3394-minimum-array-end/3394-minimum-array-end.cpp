class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        int target = n-1, i=0;

        while(target>0){
            int bit = target&1;
            target >>= 1;

            while((ans&(1LL<<i)) != 0){
                i++;
            }

            if(bit){
                ans |= (1LL << i);
            }
            i++;
        }

        return ans;
    }
};

// 4 => 100
// 5 => 101
// 6 => 110

// 7 => 111
// 15 => 1111

// 6715153 => 11001100111011100010001
// 7193485 => 11011011100001110001101

// 55012476815 => 110011001110111111111100011110001111