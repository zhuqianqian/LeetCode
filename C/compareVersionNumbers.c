/**
 * https://leetcode.com/problems/compare-version-numbers/
 */
 
int compareVersion(char* version1, char* version2) {
    int v1, v2;
    while(*version1 || *version2){
        v1 = v2 = 0;
        while(*version1 && *version1!= '.') { 
            v1 = v1* 10 + *version1 - '0';
            version1++;
        }
        while(*version2 && *version2!= '.') { 
            v2 = v2* 10 + *version2 - '0';
            version2++;
        }
        if(v1!=v2) {
            return v1 > v2 ? 1 : -1;
        }
        
        if(*version1) version1++;
        if(*version2) version2++;
    }
    return 0;
}