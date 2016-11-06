#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int coinChange(int* coins, int coinsSize, int amount) {
    unsigned int* dp = (unsigned int*)malloc(sizeof(int)*(amount + 1));
    int i, j, ans, t;
    memset(dp, 0xff, sizeof(int) * (amount + 1));
    dp[0] = 0;
    for (i = 1; i <= amount; i++) {
        for (j = 0; j < coinsSize; j++) {
            if (coins[j] <= i) {
                t = dp[i - coins[j]] + 1;
                if (t > 0 && t < dp[i]) {
                    dp[i] = t;
                }
            }      
        }
    }
    ans = dp[amount];
    free(dp);
    return ans;
}

int coinChange2(int* coins, int coinsSize, int amount) {
    unsigned int* dp = (unsigned int*)malloc(sizeof(int)*(amount + 1));
    int i, j, ans, t;
    memset(dp, 0xff, sizeof(int)*(amount + 1));
    dp[0] = 0;
    for (i = 0; i < coinsSize; i++) {
        for (j = coins[i]; j <= amount; j++) {
            t = dp[j - coins[i]] + 1;
            if (t > 0 && t < dp[j]) {
                dp[j] = t;
            }
        }
    }
    ans = dp[amount];
    free(dp);
    return ans;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("changeCoins <amount> [coin1, coint2,...]\n");
        return 0;
    }
    int i;
    int amount = atoi(argv[1]);
    int* coins = (int*)malloc(sizeof(int)*(argc - 2));
    for (i = 0; i < argc - 2; i++) {
        coins[i] = atoi(argv[i + 2]);
    }
    printf("Result: %d\t%d\n", coinChange(coins, argc - 2, amount),
        coinChange2(coins, argc-2, amount));
    free(coins);
    return 0;
}
