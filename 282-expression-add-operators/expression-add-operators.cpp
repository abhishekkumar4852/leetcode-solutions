class Solution {
public:
    void solve(string&num , int target , int index , long long value , long long prev , string path , vector<string>&ans){

        if(index == num.size()){
            if(value == target)
            ans.push_back(path);
            return;
        }

        for(int i = index ; i < num.size() ; i++ ){

            if(i > index  && num[index] == '0')
            break;

            string s = num.substr(index , i - index  + 1);
            long long curr = stoll(s);

            if(index == 0){
                solve(num , target , i+1 , curr , curr , s  , ans);
            }
            else{
                solve(num , target , i+1 , value+curr , curr , path + "+" + s , ans );

                solve(num , target , i+1 , value - curr , -curr , path + "-" + s  , ans );

                solve(num , target , i+1 , value - prev +prev*curr ,prev*curr, path + "*" + s  , ans );
            
            }

        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;

        solve(num , target , 0 ,0,0,"" , ans);
        return ans ;
        
    }
};