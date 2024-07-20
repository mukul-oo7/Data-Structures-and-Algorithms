class Solution {
public:
    int solver(vector<int> &nums, int dif, int k){
        int ans=0;
        int l=0, r=nums.size()-1;
        
        while(l<r){
            
            if(abs(nums[l]-nums[r])!=dif){
                if(nums[l]<dif && nums[r]<dif){
                    if(abs(k-nums[l])>=dif || abs(k-nums[r])>=dif) ans++;
                    else{
                        ans+=2;
                    }
                } else{
                    ans++;
                }
            }
            l++;
            r--;
        }

        return ans;
    }
    int minChanges(vector<int>& nums, int k) {
        map<int, int> mp;
        int n=nums.size();
        
        int l=0, r=n-1;
        
        while(l<r){
            mp[abs(nums[l]-nums[r])]++;
            l++;
            r--;
        }
        
        int dif=INT_MAX, fre=INT_MIN, dif2=INT_MAX;
        
        for(auto it: mp){
            if(it.second>fre){
                fre=it.second;
                dif2=dif;
                dif=it.first;
            }
        }
        
        
        l=0, r=n-1;
        
        int ans=solver(nums, dif, k);
        if(dif2!=INT_MAX){
            ans = min(ans, solver(nums, dif2, k));
        }
        
        return ans;
    }
};