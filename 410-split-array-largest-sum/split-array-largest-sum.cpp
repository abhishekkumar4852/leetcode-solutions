class Solution {
public:
    bool canSplit(vector<int>&nums, int k , int maxSum){
        int count = 1;
        long long currSum = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            if(currSum + nums[i] <= maxSum){
                currSum += nums[i];
            }else{
                count++;
                currSum = nums[i];
            }
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low= nums[0];
        int high = 0;

        for(int i = 0 ; i< nums.size() ; i++){
            if(nums[i]>low)
            low = nums[i];
            high += nums[i];
            
            

        }
        while (low < high){
            int mid = low + (high - low)/2;

            if(canSplit(nums,k,mid))
            high = mid;
            else 
            low = mid+1;
        }
        return low;
        
    }
};