public class BestTimeToBuyAndSellStockAll {

    public int First(int[] prices) {
        if(prices == null || prices.length == 0) return 0;

        int profit = 0;
        int minPrice = Integer.MAX_VALUE;
        for(int i = 0; i < prices.length; i++) {
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            } else if(prices[i] - minPrice > profit) {
                profit = prices[i] - minPrice;
            }
        }

        return profit;
    }

    public int Second(int[] prices) {
        if(prices == null || prices.length == 0) return 0;

        int profit = 0;
        for(int i = 1; i < prices.length; i++) {
            if(prices[i] > prices[i-1])  {
                profit += prices[i] - prices[i-1];
            }
        }

        return profit;
    }

}
