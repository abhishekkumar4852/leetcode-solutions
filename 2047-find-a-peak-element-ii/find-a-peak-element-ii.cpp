class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int low = 0;
        int high = cols-1;

        while(low <= high){
            int mid = low+(high-low)/2;

            int maxRow = 0 ;
            for(int i = 1 ; i < rows ; i++){
                if(mat[i][mid] > mat[maxRow][mid]){
                    maxRow = i ;
                }
            }
            int left = (mid == 0 )? -1 : mat[maxRow][mid-1];
            int right = (mid == cols-1)? -1 : mat[maxRow][mid + 1];

            if(mat[maxRow][mid] > left && mat[maxRow][mid]>right){
                return {maxRow,mid};
            }
            else if (left > mat[maxRow][mid]){
                high = mid - 1;

            }else {
                low = mid+1;
            }
        }
        return {-1,-1};
        
    }
};