class Solution {
public:

    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b)
            parent[b] = a;
    }

    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts) {

        int n = accounts.size();

        // DSU initialization
        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // email -> account index
        unordered_map<string, int> emailToAccount;

        // Step 1: Connect accounts having common emails
        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if (emailToAccount.find(email) == emailToAccount.end()) {
                    emailToAccount[email] = i;
                }
                else {
                    unite(i, emailToAccount[email]);
                }
            }
        }

        // Step 2: Group emails by their parent account
        unordered_map<int, vector<string>> groups;

        for (auto &it : emailToAccount) {

            string email = it.first;
            int account = find(it.second);

            groups[account].push_back(email);
        }

        // Step 3: Create answer
        vector<vector<string>> ans;

        for (auto &it : groups) {

            int account = it.first;

            vector<string> emails = it.second;

            sort(emails.begin(), emails.end());

            vector<string> temp;

            temp.push_back(accounts[account][0]);

            for (string email : emails)
                temp.push_back(email);

            ans.push_back(temp);
        }

        return ans;
    }
};