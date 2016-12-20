/**
 * https://leetcode.com/problems/number-of-segments-in-a-string/
 */
int countSegments(char* s) {
    int result = 0;
    int start = true;
    while(*s) {
        if(*s != 0x20 && start) {
            result++;
            start = false;
        }
        else if(*s == 0x20) {
            start = true;
        }
        s++;
    }
    return result;
}