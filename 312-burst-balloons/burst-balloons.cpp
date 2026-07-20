class Solution {
public:
    int dp[305][305];
    int solve(vector<int>& nums,int i , int j) {
        if(i>j)
        return 0 ;

        if (dp[i][j]!=-1)
        return dp[i][j];

        int mx = 0;

        for(int k = i ; k <= j ; k++){
            int left = solve(nums,i,k-1);
            int right = solve(nums,k+1,j);

            int temp = left+right+nums[i-1]*nums[k]*nums[j+1];

            mx = max(mx,temp);
        }
        return dp[i][j] = mx;

        
    }
    int maxCoins(vector<int>&nums){

        nums.insert(nums.begin(),1);
        nums.push_back(1);

        memset(dp,-1,sizeof(dp));

        return solve(nums,1,nums.size()-2);
    }
};