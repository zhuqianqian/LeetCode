/*
 * https://leetcode.com/problems/length-of-last-word/
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
 * return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * 2015/12/18
 */
 
int lengthOfLastWord(char* s) {
    int count = 0;
    int length = 0;
    char *p = s;
    while(*p) {
        if(*p == ' ') {
            length = count;
            count = 0;
            while(*p && *p == ' ') p++;
            continue;
        }
        count++;
        p++;
    }
    return count > 0 ? count : length;
}
