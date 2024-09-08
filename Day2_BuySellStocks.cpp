class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = prices[0], maxProfit = 0;

        for(int price: prices) {
            if(price < buyPrice) 
                buyPrice = price;
            else
                maxProfit = max(maxProfit, price-buyPrice);
        }

        return maxProfit;
    }
};