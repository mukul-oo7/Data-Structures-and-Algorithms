class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> fre(k, 0);

        for(int e: arr){
            if(e>=0) fre[e%k]++;
            else{
                if(e%k == 0) fre[0]++;
                else fre[k+e%k]++;
            }
        }

        if(fre[0]%2) return false; 

        int i=1, j=k-1;
        while(i<=j){
            if(i==j){
                if(fre[i]%2) return false;
            } else{
                if(fre[i]!=fre[j]) return false;
            }

            i++;
            j--;
        }

        return true;
    }
};

// 0 1 2 3 4 