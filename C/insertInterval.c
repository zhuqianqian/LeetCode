/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
* https://leetcode.com/problems/insert-interval
*/

 /**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MIN(a, b) (a) < (b) ? (a) : (b);
#define MAX(a, b) (a) > (b) ? (a) : (b);
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    struct Interval* result = (struct Interval*)malloc(sizeof(struct Interval)*(intervalsSize + 1));
    if(intervals == NULL || intervalsSize == 0) {
        *returnSize = 1;
        *result = newInterval;
        return result;
    }
    *returnSize = 0;
    int i;
    for(i = 0; i < intervalsSize; i++) {
        if(intervals[i].end < newInterval.start) {
            result[(*returnSize)++] = intervals[i];
        } else if(intervals[i].start > newInterval.end) {            
            result[(*returnSize)++] = intervals[i];
            break;
        } else {
            result[*returnSize].start = MIN(newInterval.start, intervals[i].start);
            while(i < intervalsSize) {
                if(intervals[i].end > newInterval.end) break;
                i++;
            }
            if(i < intervalsSize && intervals[i].start <= newInterval.end)  {
                result[(*returnSize)++].end = intervals[i].end;
                i++;
            } else {
                result[(*returnSize)++].end = MAX(newInterval.end, intervals[i-1].end);
            }
            break;
        }
    }
    while(i < intervalsSize) {
        result[(*returnSize)++] = intervals[i++];
    }
    if(newInterval.start > intervals[i-1].end) {        
        result[(*returnSize)++] = newInterval;
    }
    return result;
}
