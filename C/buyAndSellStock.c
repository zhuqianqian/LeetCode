/*
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 * 2016/01/02
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int(*fptr)(int*, int);
 
int maxProfit(int* prices, int pricesSize) {
    int min, profit, i, minAt;
    min = INT_MAX;
    for(i = profit = 0; i < pricesSize; ++i) {
        if(min > prices[i]) {
            min = prices[i];
            minAt = i;
        }
        if((prices[i] - min) > profit && minAt < i) {
            profit = prices[i] - min;
        }
    }
    return profit;
}

/* a0,a1,..ai,b0,b1,...bj..
 * if a0 < a1 < ... < ai, b0 < b1 < ... < bj, as long as 
 * b0 < ai, (ai - a0 + bj - b0) > (bj - a0) is true.
 * Thus the problem is to find the sum of the (last-first) 
 * of each increasing sequence.
 */
int maxProfit2(int *prices, int pricesSize) {
    int profit = 0 , min, i;
    if (pricesSize > 0) {
        min = prices[0];
        for (i = 1; i < pricesSize; ++i) {
            if (prices[i] < prices[i - 1]) {
                profit += prices[i - 1] - min;
                min = prices[i];
            }
        }
        profit += prices[i - 1] - min;
    }
    return profit;
}

int maxProfitK(int k, int *prices, int pricesSize) {
    return 0;
}

int maxProfitCooldown(int *prices, int pricesSize) {
    return 0;
}

int main(int argc, char **argv) {
    int i, *prices;
    fptr f = NULL;
    char **values = NULL;
    int numberCount = argc - 2;
    int k;
    if (argc < 2) {
        printf("maxProfit <options> [number0[, number1[,...]]]\n");
        printf("<options> are: \n\t-o: only one transaction can be performed.\n");
        printf("\t-u: unlimited transactions can be performed.\n");
        printf("\t-k: k transactions can be performed. A value for k must follow\n");
        printf("\t-c: unlimited transactions, but there is one day cooldown.\n");
        return 0;
    }
    values = argv + 2;
    if (!strcmp(argv[1], "-o")) {
        f = maxProfit;
    }
    else if (!strcmp(argv[1], "-u")) {
        f = maxProfit2;
    }
    else if (!strcmp(argv[1], "-c")) {
        f = maxProfitCooldown;
    }
    else if (!strcmp(argv[1], "-k")) {
        values += 1;
        numberCount -= 1;
        if (argc < 3) {
            printf("You must specify a value for k.\n");
            return 0;
        }
        k = atoi(argv[2]);
    }
    else {
        printf("Invalid option: %s\n", argv[1]);
        return 0;
    }
    prices = (int *)malloc(sizeof(int)* numberCount);
    for (i = 0; i < numberCount; ++i, values++) {
        prices[i] = atoi(*values);
    }
    if (f != NULL) {
        printf("Max profit %s: %d\n", argv[1], f(prices, numberCount));
    }
    else {
        printf("Max Profit %s: %d\n", argv[1], maxProfitK(k, prices, numberCount));
    }
    return 0;
}
