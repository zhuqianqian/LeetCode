/**
 * https://leetcode.com/problems/isomorphic-strings/
 */
 
bool isIsomorphic(char* s, char* t) {
    char hashS[128] = {0};
    char hashT[128] = {0};
    while(*s && *t) {
        if(hashS[*s] > 0 || hashT[*t] > 0) {
            if(hashS[*s] != *t || hashT[*t] != *s) {
                return false;
            }
        }
        else {
            hashS[*s] = *t;
            hashT[*t] = *s;
        }
        s++; t++;
    }
    return *s == *t;
}