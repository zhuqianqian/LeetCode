char* convert(char* s, int numRows) {
    if (numRows <= 1) {
        return s;
    }
    int length = strlen(s);
    char* result = (char*)malloc(sizeof(char)*length + 1);
    result[length] = 0;
    char *p = result;
    int step = numRows * 2 - 2;
    int i, j, k;
    for (i = 0; i < numRows; i++) {
        for (j = i; j < length; j += step) {
            *p++ = s[j];
            k = j - i + step - i;
            if (i != 0 && i != (numRows - 1) && k < length) {
                *p++ = s[k];
            }
        }
    }
    return result;
}