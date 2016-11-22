/**
 * https://leetcode.com/problems/reverse-vowels-of-a-string/
 */
 
int isVowel(char c) {
    char x = c | 0x20;
    return (x=='a' || x=='e' || x=='i' || x == 'o' || x=='u');
}

char* reverseVowels(char* s) {
    char *h, *e;
    h = e = s;
    while(*e) e++;
    e--; 
    while(h < e) {
        while(*h && !isVowel(*h)) {h++;}
        while(*e && !isVowel(*e)) {e--;}
        if(h < e) {
            *h ^= *e ^= *h ^= *e; 
        }
        h++; e--;
    }
    return s;
}