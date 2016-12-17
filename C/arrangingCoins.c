/**
 * https://leetcode.com/problems/arranging-coins/
 */ 
int arrangeCoinsMath(int n) {
    long nl = n * 8L;
    return (-1 + sqrt(1+nl))/2;
}

int arrangeCoins(int n) {
    long l, h;
    l = 1; h = n;
    long mid, x;
    do{
        mid = (l + h)/2;
        x = mid * (mid+1)/2;
        if(x == n || l == mid) return mid;
        if(x > n) { h = mid;}
        else {l = mid;}
    }while(l < h);
    return mid;
}