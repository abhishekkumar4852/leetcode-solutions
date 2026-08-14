class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        for(int i = 0 ; i < num.size(); i++){
            char ch = num[i];

            while(k > 0 && !st.empty()&& st.back()>ch){
                st.pop_back();
                k--;
            }
            st.push_back(ch);
        }
        for(int i = 0 ;i < k ; i++){
            st.pop_back();

        }
        int i = 0 ;
        while( i < st.size() && st[i] == '0'){
            i++;
        }

        if(i == st.size()){
            return "0";
        }
        return st.substr(i);
    }
};