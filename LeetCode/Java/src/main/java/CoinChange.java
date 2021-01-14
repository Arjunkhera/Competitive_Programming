import java.util.Arrays;

public class CoinChange {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount+1];
        Arrays.fill(dp, amount+1);
        dp[0] = 0;

        int numberOfCoins = amount + 1;
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.length; j++) {
                if(coins[j] <= i) {
                    dp[i] = Math.min(dp[i-coins[j]] + 1, dp[i]);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
}
