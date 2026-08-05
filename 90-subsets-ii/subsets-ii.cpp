class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;

    void solve(int idx , vector<int>&nums){
        ans.push_back(temp);
      

       for(int i = idx ; i < nums.size() ; i++){
           if( i > idx && nums[i] == nums[i-1])
           continue;

           temp.push_back(nums[i]);
           solve(i+1, nums);
           temp.pop_back();
       }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        solve(0 , nums);
        return ans;
        
    }
};