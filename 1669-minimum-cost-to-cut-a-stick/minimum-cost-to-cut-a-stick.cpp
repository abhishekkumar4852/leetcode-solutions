class Solution {
public:
    vector<vector<int>>dp;

    int solve(vector<int>&cuts , int i , int j ){
        if(i + 1 == j)
        return 0 ;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int ans = INT_MAX;

        for(int k = i+1 ; k < j ; k++){
            int cost = (cuts[j] - cuts[i])+solve(cuts , i ,k)+ solve(cuts,k, j);

            ans = min(ans , cost);
        }
        return dp[i][j] = ans ;

    }
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(),cuts.end());

        int m = cuts.size();

        dp.assign(m, vector<int>(m,-1));

        return solve(cuts,0 ,m-1);
    }
};