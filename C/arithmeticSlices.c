/**
 * https://leetcode.com/problems/arithmetic-slices/
 */
 
/**
 * For a arithmetic slice of size n, the total number of arithmetic slices
 * is f(n)= 2 * f(n-1) - f(n-2) + 1;
 */
int numberOfArithmeticSlices(int* A, int ASize) {
    int result = 0;
    int i, delta;
    int tmp, r, r_1;
    if(ASize > 2) {
        delta = A[1] - A[0];
        r = r_1 = 0;
        for(i = 2; i < ASize; i++) {
            if(delta == (A[i] - A[i-1])) {
                tmp = r;
                r = r*2-r_1+1;
                r_1 = tmp;
            }
            else {
                result += r;
                r = r_1 = 0;
                delta = A[i] - A[i-1];
            }
        }
        result += r;
    }
    return result;
}