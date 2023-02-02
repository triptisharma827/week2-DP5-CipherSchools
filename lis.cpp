class Solution {
public:
    int dp[10000];
    int length(vector<int> &nums, int n){
        if(dp[n]!=-1)return dp[n];
        if(n==0)return dp[n]=0;
        int c=1;
        for(int i=n-1;i>0;i--){
            if(nums[n-1]>nums[i-1])
            {
                c=max(c,1+length(nums,i));
            }
        }
        return dp[n]=c;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        for(int i=nums.size();i>=0;i--)
            if(dp[i]==-1)
            length(nums,i);
        int ans=0;
        for(auto x:dp)
            ans=max(ans,x);
        return ans;
    }
};