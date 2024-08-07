class Solution {
public:
    struct Node{
        int val;
        Node(){
            val=0;
        }
    };
    Node seg[400005];

    void printSeg(){
        for(int i=0; i<24; i++){
            cout << seg[i].val << " " ;
        }

        cout << endl;
    }

    Node combine(Node &a, Node &b){
        Node c;
        c.val = a.val+b.val;
        return c;
    }

    void build(int ind, int l, int r, vector<int> &nums){
        if(l==r){
            int d=0;
            if(l>0 && l<nums.size()-1 && nums[l]>nums[l-1] && nums[l]>nums[l+1]) d=1;
            seg[ind].val = d;
            return;
        }

        int mid = (l+r)/2;
        build(2*ind+1, l, mid, nums);
        build(2*ind+2, mid+1, r, nums);
        seg[ind] = combine(seg[2*ind+1], seg[2*ind+2]);
    }

    void update(int ind, int l, int r, int i, int v, vector<int> &nums){
        if(l==r){
            nums[l]=v;
            int d=0;
            if(l>0 && l<nums.size()-1 && nums[l]>nums[l-1] && nums[l]>nums[l+1]) d=1;

            seg[ind].val = d;
            return;
        }

        int mid = (l+r)/2;
        if(i<=mid){
            update(2*ind+1, l, mid, i, v, nums);
        } else{
            update(2*ind+2, mid+1, r, i, v, nums);
        }

        seg[ind] = combine(seg[2*ind+1], seg[2*ind+2]);
    }

    int find(int ind, int l, int r, int sl, int sr, vector<int> &nums){
        if(r<sl || l>sr) return 0;
        if(sl<=l && sr>=r) return seg[ind].val;
        
        int mid = (l+r)/2;
        int lv = find(2*ind+1, l, mid, sl, sr, nums);
        int rv = find(2*ind+2, mid+1, r, sl, sr, nums);

        return lv+rv;
    }

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n=nums.size();
        build(0, 0, n-1, nums);

        for(auto q: queries){
            if(q[0]==1){
                if(q[2]-q[1]+1<3) ans.push_back(0);
                else{
                    ans.push_back(find(0, 0, n-1, q[1]+1, q[2]-1, nums));
                }
            } else{
                update(0, 0, n-1, q[1], q[2], nums);
                if(q[1]>0) update(0, 0, n-1, q[1]-1, nums[q[1]-1], nums);
                if(q[1]<nums.size()-1) update(0, 0, n-1, q[1]+1, nums[q[1]+1], nums);
            }
        }

        return ans;
    }
};