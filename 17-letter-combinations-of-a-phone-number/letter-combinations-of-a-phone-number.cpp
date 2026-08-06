class Solution {
public:
    vector<string>ans;

    void solve(int idx , string& digits , string &temp , vector<string>&mp){

        if(idx == digits.size()){
            ans.push_back(temp);
            return;

        }
        string letters = mp[digits[idx]-'0'];

        for(int i = 0 ; i< letters.size() ; i++){
            temp.push_back(letters[i]);
            solve(idx+1 , digits , temp , mp);

            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        vector<string> mp = {
            "" , "", "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"
        };
         string temp = "";

         solve( 0 , digits , temp , mp);
         return ans;
        
    }
};