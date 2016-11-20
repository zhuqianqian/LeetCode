/**
 * https://leetcode.com/problems/range-sum-query-immutable/
 */
 
struct NumArray {
    int *sums;
    int size;
};

struct NumArray gArray;

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    int i;
    gArray.size = numsSize;
    if(numsSize > 0) {
        gArray.sums = (int*)malloc(sizeof(int)*(numsSize+1));
        gArray.sums[0] = 0;
        for(i=1; i <= numsSize; i++) {
            gArray.sums[i] = gArray.sums[i-1] + nums[i-1];
        }
    }
    return &gArray;
}

int sumRange(struct NumArray* numArray, int i, int j) {
    return numArray->sums[j+1] - numArray->sums[i];
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
    free(numArray->sums);
    numArray->sums = NULL;
    numArray->size = 0;
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);