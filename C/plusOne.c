/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int)*digitsSize);
    int carry = 1, i;
    *returnSize = digitsSize;
    memcpy(result, digits, sizeof(int)*digitsSize);
    for (i = digitsSize - 1; i >= 0 && carry; --i) {
        if (result[i] == 9) { result[i] = 0; }
        else { result[i] += 1; carry = 0; }
    }
    if (digitsSize > 0 && carry) {
        *returnSize += 1;
        result = realloc(result, *returnSize*sizeof(int));
        memmove(result + 1, result, sizeof(int)*digitsSize);
        result[0] = carry;
    }
    return result;
}