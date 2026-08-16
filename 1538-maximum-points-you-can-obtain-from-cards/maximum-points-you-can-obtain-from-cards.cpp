class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int sum = 0;

        // Total sum
        for (int x : cardPoints) {
            sum += x;
        }

        int window = n - k;

        // Sum of first n-k elements
        int curr = 0;

        for (int i = 0; i < window; i++) {
            curr += cardPoints[i];
        }

        int mn = curr;

        // Find minimum window sum
        for (int i = window; i < n; i++) {
            curr += cardPoints[i];
            curr -= cardPoints[i - window];

            mn = min(mn, curr);
        }

        return sum - mn;
    }
};