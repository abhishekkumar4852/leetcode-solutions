class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0];
        int sell = 0;
        int cooldown = 0;

        for (int i = 1; i < prices.size(); i++) {
            int price = prices[i];

            int prevBuy = buy;
            int prevSell = sell;
            int prevCooldown = cooldown;

            buy = max(prevBuy, prevCooldown - price);

            sell = prevBuy + price;

            cooldown = max(prevCooldown, prevSell);
        }

        return max(sell, cooldown);
    }
};