/**
 * https://leetcode.com/problems/fizz-buzz/
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    int i, k;
    char** ans;
    *returnSize = n;
    if(n > 0){
        ans = (char**)malloc(sizeof(char*)*n);
        for(i = 1; i <= n; i++) {
            k = i-1;
            if(i % 15 == 0) {
                ans[k] = (char*)malloc(sizeof(char)*9);
                strcpy(ans[k], "FizzBuzz");
            }
            else if(i % 5 == 0) {
                ans[k] = (char*)malloc(sizeof(char)*5);
                strcpy(ans[k], "Buzz");
            }
            else if(i%3==0) {
                ans[k] = (char*)malloc(sizeof(char)*5);
                strcpy(ans[k], "Fizz");
            }
            else {
                ans[k] = (char*)malloc(sizeof(char)*9);
                sprintf(ans[k], "%d", i);
            }
        }
    }
    return ans;
}