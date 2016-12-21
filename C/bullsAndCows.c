/**
 * https://leetcode.com/problems/bulls-and-cows/
 */
 
char HINTS[24];
char* getHint(char* secret, char* guess) {
    char hash[128] = {0};
    int bulls, cows;
    for(char *s = secret; *s; s++) {
        hash[*s] += 1;
    }
    for(bulls = cows = 0; *secret; secret++, guess++) {
        if(*secret == *guess) { bulls++; hash[*secret] -= 1; }
        else if(hash[*guess]) {cows++; hash[*guess] -= 1;}
    }
    for(char c = '0'; c <= '9'; c++) {
        cows += hash[c] < 0 ? hash[c] : 0;
    }
    sprintf(HINTS, "%dA%dB", bulls, cows);
    return HINTS;
}