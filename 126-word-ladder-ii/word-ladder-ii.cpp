class Solution {
public:

    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string word, string beginWord,
             vector<string>& path) {

        if (word == beginWord) {

            vector<string> temp = path;

            reverse(temp.begin(), temp.end());

            ans.push_back(temp);

            return;
        }

        for (int i = 0; i < parent[word].size(); i++) {

            string p = parent[word][i];

            path.push_back(p);

            dfs(p, beginWord, path);

            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList) {

        unordered_set<string> st;

        for (int i = 0; i < wordList.size(); i++) {
            st.insert(wordList[i]);
        }

        if (st.find(endWord) == st.end()) {
            return {};
        }

        queue<string> q;
        q.push(beginWord);

        st.erase(beginWord);

        bool found = false;

        while (!q.empty() && !found) {

            int size = q.size();

            unordered_set<string> used;

            for (int i = 0; i < size; i++) {

                string current = q.front();
                q.pop();

                string word = current;

                for (int j = 0; j < word.size(); j++) {

                    char original = word[j];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        word[j] = ch;

                        if (st.find(word) != st.end()) {

                            parent[word].push_back(current);

                            used.insert(word);

                            if (word == endWord) {
                                found = true;
                            }
                        }
                    }

                    word[j] = original;
                }
            }

            // Remove only after completing this level
            for (auto word : used) {
                st.erase(word);
                q.push(word);
            }
        }

        vector<string> path;

        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};