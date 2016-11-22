/**
 * https://leetcode.com/problems/reverse-string/
 */
 
char* reverseString(char* s) {
    char *h, *e;
    char t;
    h = e = s;
    while(*e) e++;
    e--; 
    while(h < e) {
        //t  = *h; *h = *e;  *e =  t;
        *h ^= *e ^= *h ^= *e;
        h++; e--;
    }
    return s;
}