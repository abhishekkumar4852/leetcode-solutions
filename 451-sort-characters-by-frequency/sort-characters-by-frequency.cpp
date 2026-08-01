class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for( int i = 0 ; i < s.size() ; i++){
            mp[s[i]]++;
        }

        vector<pair<char,int>> vec;

        for(auto it = mp.begin() ; it != mp.end(); it++){
            vec.push_back(*it);
        }

        sort(vec.begin(),vec.end(),[](pair<char,int> a , pair<char,int> b){
            return a.second >b.second;
        });

        string ans = "";
        
        for(int i = 0 ; i < vec.size() ; i++){
            for(int j = 0 ; j < vec[i].second ; j++){
                ans+= vec[i].first;
            }
        }
        return ans;

    }
};