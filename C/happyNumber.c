/**
 * https://leetcode.com/problems/happy-number/
 */
bool isHappy(int n) {
    /* a 32bit integer will at most reach 733 */
    int hash[1000] = {0};
    int v, x;
    do {
        for(v = 0; n > 0; n /= 10) {
            x = n%10;
            v += x*x;
        }
        n = v;
        if(hash[v] > 0) {
            break;
        }
        else { hash[v] = 1;}
    }while(n!=1);
    return n == 1;
}