class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, min=prices[0], profit=0;
        for(i=0; i<prices.size(); i++){
            if(prices[i]<min){
                min = prices[i];
            }
            if(prices[i]-min>profit){
                profit = prices[i]-min;
            }
        }
        return profit;
    }
};