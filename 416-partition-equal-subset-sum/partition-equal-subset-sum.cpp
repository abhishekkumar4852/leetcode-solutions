class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i = 0;i<n;i++){
            sum+= nums[i];
        }
        if(sum%2!=0)
        return false;

        int target = sum/2;

        vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));

        for(int i = 0 ; i<=n;i++){
            dp[i][0] = true ;
        }
        for(int j = 0 ; j<=target ;j++){
            dp[0][j] =false;
        }

        for(int i = 1;i<=n;i++){
            for(int j = 1 ; j<=target ; j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]]||dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][target];
        
    }
};