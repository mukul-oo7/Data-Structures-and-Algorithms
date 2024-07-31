class Solution {
public:
    vector<int> dp;

    int helper(int ind, int width, vector<vector<int>> &book){
        if(ind>=book.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int w=0, height=0, ans=INT_MAX;

        for(int i=ind; i<book.size(); i++){
            w+=book[i][0];
            if(w>width) break;
            height=max(height, book[i][1]);

            ans = min(ans, height+helper(i+1, width, book));
        }

        return dp[ind] = ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        dp.resize(n, -1);
        return helper(0, shelfWidth, books);
    }
};