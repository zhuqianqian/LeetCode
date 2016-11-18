/**
 * https://leetcode.com/problems/valid-anagram/
 */

bool isAnagram(char* s, char* t) {
    char hash[128]={0};
    int i;
    if(s!=NULL && t!=NULL) {
        while(*s && *t) {
            hash[*s++] += 1;
            hash[*t++] -= 1;
        }
        if(*s || *t) return false;
        for(i = 'a'; i<='z'; i++) {
            if(hash[i] !=0) {
                return false;
            }
        }
        return true;
    }
    return false;
}